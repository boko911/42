/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_blindly.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 16:41:10 by agrosset          #+#    #+#             */
/*   Updated: 2018/03/08 15:02:26 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_mtx	ft_calc_ray_dir(t_env *env, int x, int y)
{
	t_mtx	out;

	out = norm_vect(mtx_add(mtx_mult(env->scene->camera->dir,
		env->scene->camera->vp_dist), mtx_add(mtx_mult(
		env->scene->camera->x_indent,
		x - env->scene->camera->res.width / 2.0), mtx_mult(
		env->scene->camera->y_indent,
		y - env->scene->camera->res.height / 2.0))));
	return (out);
}

static int		ft_light_contact(t_env *env, t_list *current, t_ray *ray,
	double *p)
{
	t_ray	lray;
	double	coef_refrac;
	double	t;

	lray.pos = ((t_light *)current->content)->pos;
	lray.dir = norm_vect(mtx_add(mtx_negate(lray.pos), ray->pos));
	lray.invdir = get_inv_vect(&lray.dir);
	t = sqrt(POW2((VOM(ray->pos, 0, 0) - VOM(lray.pos, 0, 0))) +
		POW2((VOM(ray->pos, 1, 0) - VOM(lray.pos, 1, 0))) +
		POW2((VOM(ray->pos, 2, 0) - VOM(lray.pos, 2, 0))));
	coef_refrac = 1.0;
	if (find_closest_blindly(env->scene, &lray, t, &coef_refrac))
	{
		*p = (((t_light *)current->content)->power) / POW2(t) * coef_refrac;
		return (1);
	}
	return (0);
}

static void		ft_check_blindly_p2(t_env *env, t_color *temp_color)
{
	t_mtx	beg_end[2];
	t_ray	ray;
	t_list	*current;
	double	p;

	p = 1.0;
	ray.pos = env->scene->camera->pos;
	current = env->scene->lights;
	beg_end[0] = ft_calc_ray_dir(env, 0, 0);
	beg_end[1] = ft_calc_ray_dir(env, env->scene->camera->res.width,
		env->scene->camera->res.height);
	while (current)
	{
		if (ft_is_inscene(((t_light *)current->content)->pos,
			ray.pos, beg_end) && ft_light_contact(env, current, &ray, &p))
		{
			rgb_add_rgb(temp_color, rgb_clamp_rgb(
				rgb_mult_cpy((((t_light *)current->content)->color), p)));
		}
		current = current->next;
	}
}

void			ft_check_blindly(t_env *env, t_color *color)
{
	static int		bol = 0;
	static t_color	temp_color;

	if (!bol)
	{
		temp_color = rgb_new(0, 0, 0);
		ft_check_blindly_p2(env, &temp_color);
		bol = 1;
	}
	rgb_equal_rgb(color, &temp_color);
}
