/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 16:41:10 by agrosset          #+#    #+#             */
/*   Updated: 2018/04/02 15:50:16 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_mtx	ft_calc_ray_dir(t_env *env, int x, int y, int *x_y_a)
{
	t_mtx	out;
	int		x_a;
	int		y_a;

	x_a = x_y_a[0];
	y_a = x_y_a[1];
	out = norm_vect(mtx_add(mtx_mult(env->scene->camera->dir,
		env->scene->camera->vp_dist), mtx_add(mtx_mult(
		env->scene->camera->x_indent,
		x - env->scene->camera->res.width / 2. + x_a /
		(double)env->scene->camera->antialiasing), mtx_mult(
		env->scene->camera->y_indent,
		y - env->scene->camera->res.height / 2. + y_a /
		(double)env->scene->camera->antialiasing))));
	return (out);
}

static void		get_pixel_color_p2(t_env *env, int x, int y, t_color *color)
{
	t_ray		ray;
	int			x_y_a[2];
	t_lex_fra	reflerefra;

	ft_lock_mult_thread(env);
	x_y_a[0] = -1;
	ray.pos = env->scene->camera->pos;
	while (++x_y_a[0] < env->scene->camera->antialiasing)
	{
		x_y_a[1] = -1;
		while (++x_y_a[1] < env->scene->camera->antialiasing)
		{
			ft_init_lexrac(&reflerefra);
			env->scene->x = x;
			env->scene->y = y;
			ray.dir = ft_calc_ray_dir(env, x, y, x_y_a);
			ray.invdir = get_inv_vect(&ray.dir);
			rgb_add_rgb(color, compute_color(env, &ray, reflerefra));
		}
	}
	rgb_div(color, POW2(env->scene->camera->antialiasing));
	rgb_clamp(color);
	check_filter(color, env);
	ft_unlock_mult_thread(env);
}

static t_color	get_pixel_color(t_env *env, int x, int y)
{
	t_color		color;

	color = rgb_new(0, 0, 0);
	if (env->scene->blind)
		ft_check_blindly(env, &color);
	get_pixel_color_p2(env, x, y, &color);
	return (color);
}

static int		render_scene_p2(t_env *env)
{
	int				x;
	int				y;
	unsigned int	current_pixel_cpy;

	ft_lock_mult_thread(env);
	current_pixel_cpy = env->processed_pixels;
	env->processed_pixels++;
	ft_unlock_mult_thread(env);
	if (current_pixel_cpy >= (unsigned int)(env->scene->camera->res.height *
		env->scene->camera->res.width))
	{
		env->finish = 1;
		return (0);
	}
	y = current_pixel_cpy / env->scene->camera->res.width;
	x = current_pixel_cpy % env->scene->camera->res.width;
	set_img_pixel(&env->bg_img, x, y, get_pixel_color(env, x, y));
	return (1);
}

void			*render_scene(void *arg)
{
	t_env *env;

	env = (t_env *)arg;
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
	while (1)
	{
		if (render_scene_p2(env) == 0)
			break ;
	}
	while (1)
		SDL_Delay(50);
	pthread_exit(NULL);
}
