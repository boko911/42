/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 14:23:07 by agrosset          #+#    #+#             */
/*   Updated: 2016/08/08 13:53:53 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_mtx	get_normal(t_ray ray)
{
	t_mtx	pos;
	t_obj	*obj;
	t_inter	inter;

	obj = ray.obj_closest;
	pos = mtx_add(mtx_mult(ray.dir, ray.t), ray.pos);
	pos.mtx[3] = 1;
	inter.pos = pos;
	inter.t = 0;
	return (obj->normal(obj, &inter, &ray));
}
