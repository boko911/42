/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 17:01:21 by agrosset          #+#    #+#             */
/*   Updated: 2018/04/02 19:21:54 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_texture_plane(t_fttexture *imgtexture, t_obj *obj, t_phpa *ph,
	int *x_y)
{
	double	u;
	double	v;

	(void)obj;
	u = ph->x;
	v = ph->y;
	x_y[0] = u + imgtexture->texture->surface->surface->w;
	x_y[1] = v - imgtexture->texture->surface->surface->h;
}

void	ft_spherical_mapping(t_fttexture *imgtexture, t_obj *obj, t_phpa *ph,
	int *x_y)
{
	t_mtx	*normal;
	double	u;
	double	v;

	(void)obj;
	normal = &(ph->normal);
	u = VOM(*normal, 0, 0) + 0.5;
	v = VOM(*normal, 1, 0) - 0.5;
	x_y[0] = u * imgtexture->texture->surface->surface->w;
	x_y[1] = v * imgtexture->texture->surface->surface->h;
}
