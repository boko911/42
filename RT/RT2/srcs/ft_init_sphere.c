/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 12:28:17 by agrosset          #+#    #+#             */
/*   Updated: 2018/01/29 13:42:47 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_sphere(t_env *env, t_tobj *tobj, t_sphere *obj, int *i)
{
	tobj->rot = mtx_createscalemtx(1, 1, 1);
	tobj->scale = mtx_createscalemtx(1, 1, 1);
	obj->radius = 1;
	obj->h1 = 0;
	obj->h2 = 0;
	obj->mat = &env->base_material;
	i[0] = 0;
	i[1] = 0;
}

int		ft_alloc_sphere(t_sphere **obj, t_list **lst)
{
	if ((*obj = (t_sphere *)ft_memalloc(sizeof(t_sphere))) == NULL)
		return (return_print("malloc error", 0));
	if ((*lst = ft_lstnewfrom(obj, sizeof(*obj))) == NULL)
	{
		free(*lst);
		return (return_print("malloc error", 0));
	}
	return (1);
}

void	last_setup(t_sphere *obj)
{
	double rad;

	rad = sqrt(obj->radius);
	set_vector(&obj->aabb[0], obj->trans.trans.mtx[3] - rad,
		obj->trans.trans.mtx[7] - rad,
		obj->trans.trans.mtx[11] - rad);
	set_vector(&obj->aabb[1], obj->trans.trans.mtx[3] + rad,
		obj->trans.trans.mtx[7] + rad,
		obj->trans.trans.mtx[11] + rad);
	if (obj->h1 == obj->h2)
	{
		obj->h1 = -rad;
		obj->h2 = rad;
	}
}

int		ft_delete_sphere(t_list **lst, t_sphere **obj)
{
	free(*lst);
	free(*obj);
	return (0);
}
