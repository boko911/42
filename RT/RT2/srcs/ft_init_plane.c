/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 13:01:04 by agrosset          #+#    #+#             */
/*   Updated: 2016/09/12 15:54:27 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_plane(t_env *env, t_tobj *tobj, t_plane *obj, int *i)
{
	tobj->rot = mtx_createscalemtx(1, 1, 1);
	tobj->scale = mtx_createscalemtx(1, 1, 1);
	obj->mat = &env->base_material;
	set_vector(&obj->aabb[0], -1.0 / 0.0, -1.0 / 0.0, -1.0 / 0.0);
	set_vector(&obj->aabb[1], 1.0 / 0.0, 1.0 / 0.0, 1.0 / 0.0);
	i[0] = 0;
	i[1] = 0;
}

int		ft_delete_plane(t_list **lst, t_plane **obj)
{
	free(*lst);
	free(*obj);
	return (0);
}

int		ft_alloc_plane(t_plane **obj, t_list **lst)
{
	if ((*obj = (t_plane *)ft_memalloc(sizeof(t_plane))) == NULL)
		return (return_print("malloc error", 0));
	if ((*lst = ft_lstnewfrom(*obj, sizeof(*obj))) == NULL)
	{
		free(obj);
		return (return_print("malloc error", 0));
	}
	return (1);
}
