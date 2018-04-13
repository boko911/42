/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:35:58 by agrosset          #+#    #+#             */
/*   Updated: 2018/04/02 15:01:20 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int g_sleep;

static char	near_enough(t_ray *r1, t_ray *r2)
{
	t_mtx	p1;
	t_mtx	p2;

	p1 = mtx_add(mtx_mult(r1->dir, r1->t), r1->pos);
	p2 = mtx_add(mtx_mult(r2->dir, r2->t), r2->pos);
	return (NEAR(p1.mtx[0], p2.mtx[0])
		&& NEAR(p1.mtx[1], p2.mtx[1])
		&& NEAR(p1.mtx[2], p2.mtx[2]));
}

static void	set_ambiant_light(t_phpa *ph, t_scene *scene, t_ray *ray,
								t_color *color)
{
	double	dot;
	t_mtx	n;

	n = mtx_negate(ray->dir);
	dot = ft_fclamp((dot_vect(&n, &ph->normal) + scene->ambbaseimpact)
		* scene->ambcoefimpact, 0, 1);
	*color = rgb_new(
		ft_min(scene->i_ambiant.r, ft_get_nuance(ph, ray->obj_closest, 'r', 1))
			* dot * ray->obj_closest->mat->k_ambiant,
		ft_min(scene->i_ambiant.g, ft_get_nuance(ph, ray->obj_closest, 'g', 1))
			* dot * ray->obj_closest->mat->k_ambiant,
		ft_min(scene->i_ambiant.b, ft_get_nuance(ph, ray->obj_closest, 'b', 1))
			* dot * ray->obj_closest->mat->k_ambiant);
	ph->color = color;
	ph->diffuse = &color[1];
	ph->specular = &color[2];
	*ph->diffuse = rgb_new(0, 0, 0);
	*ph->specular = rgb_new(0, 0, 0);
}

static void	compute_light_p2(t_scene *scene, t_ray *ray, t_list *current,
	t_phpa *ph)
{
	t_ray	lray;
	double	t_coef_refrac[2];
	t_mtx	inter_pos;

	lray.pos = ((t_light *)current->content)->pos;
	inter_pos = mtx_mult(ray->dir, ray->t);
	lray.dir = norm_vect(mtx_add(mtx_sub(inter_pos, lray.pos), ray->pos));
	lray.invdir = get_inv_vect(&lray.dir);
	t_coef_refrac[0] = sqrt(POW2((VOM(inter_pos, 0, 0) - VOM(lray.pos, 0, 0))) +
		POW2((VOM(inter_pos, 1, 0) - VOM(lray.pos, 1, 0))) +
		POW2((VOM(inter_pos, 2, 0) - VOM(lray.pos, 2, 0))));
	if (find_closest_light(scene, &lray, t_coef_refrac, ray->obj_closest) &&
		near_enough(ray, &lray))
	{
		ph->lray = &lray;
		ph->light = (t_light *)current->content;
		ph->coef_refrac = t_coef_refrac[1];
		phong(ph);
	}
}

t_color		compute_light(t_scene *scene, t_ray *ray)
{
	t_list	*current;
	t_color	color[3];
	t_phpa	*ph;

	ph = &(scene->ph);
	current = scene->lights;
	ph->normal = get_normal(*ray);
	ph->camera = scene->camera;
	ph->texture = scene->texture;
	ph->ray = ray;
	set_ambiant_light(ph, scene, ray, color);
	ph->x = scene->x;
	ph->y = scene->y;
	while (current)
	{
		compute_light_p2(scene, ray, current, ph);
		current = current->next;
	}
	rgb_add(ph->color, ph->diffuse->r, ph->diffuse->g, ph->diffuse->b);
	rgb_add(ph->color, ph->specular->r, ph->specular->g, ph->specular->b);
	rgb_clamp(ph->color);
	return (*color);
}
