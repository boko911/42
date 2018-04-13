/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 14:12:54 by agrosset          #+#    #+#             */
/*   Updated: 2018/03/08 15:10:11 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	cylinder_inter(t_obj *obj, t_ray ray)
{
	double		abc[3];
	double		t[2];
	double		h;
	char		ret;

	ray.pos = mtx_product(obj->trans.i_ftrans, ray.pos);
	ray.dir = mtx_product(obj->trans.i_rot, ray.dir);
	abc[0] = POW2(ray.dir.mtx[0]) + POW2(ray.dir.mtx[2]);
	abc[1] = 2 * (ray.pos.mtx[0] * ray.dir.mtx[0]
		+ ray.pos.mtx[2] * ray.dir.mtx[2]);
	abc[2] = POW2(ray.pos.mtx[0]) + POW2(ray.pos.mtx[2])
		- ((t_cylinder *)obj)->radius;
	if ((ret = solve_quadratic(abc, t)) == 0)
		return (-1);
	if ((h = ray.dir.mtx[1] * t[0] + ray.pos.mtx[1]) >= 0
		&& h <= ((t_cylinder *)obj)->h)
		return (t[0]);
	else if (ret == 2 && (h = ray.dir.mtx[1] * t[1] + ray.pos.mtx[1]) >= 0
		&& h <= ((t_cylinder *)obj)->h)
		return (t[1]);
	return (-1);
}

t_mtx	cylinder_normal(t_obj *obj, t_inter *inter, t_ray *ray)
{
	t_mtx	normal;
	t_mtx	objpos;
	t_mtx	roriobj;

	objpos =
	mtx_mult(mtx_product(obj->trans.i_rot,
		mtx_product(obj->trans.i_trans, inter->pos)),
		1 / ((t_cylinder *)obj)->radius);
	roriobj = mtx_mult(mtx_product(obj->trans.i_rot,
		mtx_product(obj->trans.i_trans, mtx_mult(ray->dir,
			ray->t - LIMIT_MIN))), 1 / ((t_cylinder *)obj)->radius);
	set_vector(&normal, objpos.mtx[0], 0, objpos.mtx[2]);
	return (norm_vect(mtx_product(obj->trans.rot, normal)));
}
