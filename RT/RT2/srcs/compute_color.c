/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:35:58 by agrosset          #+#    #+#             */
/*   Updated: 2018/04/02 15:01:26 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_color	ft_compute_refracted(t_env *env, t_lex_fra reflerefra,
	t_ray ray, t_mtx normal)
{
	t_ray	refract;
	t_color	color;
	int		bol;

	normal = get_normal(ray);
	refract.pos = mtx_add(ray.pos, mtx_mult(ray.dir,
		ray.t));
	VOM(refract.pos, 0, 3) = 1;
	refract.dir = vect_refract(&bol, ray.dir, normal, ray.obj_closest->mat->n);
	if (!bol)
		return (rgb_new(0, 0, 0));
	reflerefra.nb_reflex++;
	color = compute_color(env, &refract, reflerefra);
	color = rgb_mult_cpy(color, reflerefra.coef_refrac);
	rgb_clamp(&color);
	return (color);
}

static t_color	ft_compute_reflected(t_env *env, t_lex_fra reflerefra,
	t_ray ray, t_mtx normal)
{
	t_ray	reflected;
	t_color	color;

	normal = get_normal(ray);
	reflected.pos = mtx_add(ray.pos, mtx_mult(ray.dir,
		ray.t));
	VOM(reflected.pos, 0, 3) = 1;
	reflected.dir = vect_reflect(ray.dir, normal);
	reflerefra.nb_reflex++;
	color = compute_color(env, &reflected, reflerefra);
	color = rgb_mult_cpy(color, reflerefra.coef_reflex);
	rgb_clamp(&color);
	return (color);
}

static void		compute_color_p2(t_env *env, t_ray *ray,
	t_lex_fra reflerefra, t_color *color)
{
	t_mtx	normal;

	normal = get_normal(*ray);
	if (reflerefra.coef_reflex > 0.001 &&
		reflerefra.nb_reflex < env->scene->max_ref)
		rgb_add_rgb(color, ft_compute_reflected(env, reflerefra,
			*ray, normal));
	if (reflerefra.coef_refrac > 0.001 &&
		reflerefra.nb_refrac < env->scene->max_ref)
		rgb_add_rgb(color, ft_compute_refracted(env, reflerefra,
			*ray, normal));
}

t_color			compute_color(t_env *env, t_ray *ray,
	t_lex_fra reflerefra)
{
	t_color	color;

	if (find_closest(env->scene, ray))
	{
		color = compute_light(env->scene, ray);
		reflerefra.coef_reflex *= ray->obj_closest->mat->refle;
		reflerefra.coef_refrac *= ray->obj_closest->mat->refra;
		if ((reflerefra.coef_reflex > 0.001 &&
			reflerefra.nb_reflex < env->scene->max_ref) ||
			(reflerefra.coef_refrac > 0.001 &&
			reflerefra.nb_refrac < env->scene->max_ref))
			compute_color_p2(env, ray, reflerefra, &color);
		return (color);
	}
	else
		return (env->scene->bgcolor);
}
