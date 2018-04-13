/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest_index_palette.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 14:52:23 by agrosset          #+#    #+#             */
/*   Updated: 2018/01/29 13:19:59 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbmp.h"

static int			pow2(int a)
{
	return (a * a);
}

unsigned char		get_closest_index_palette(t_palette *palette, t_rgb rgb)
{
	int				i;
	int				dist;
	int				tdist;
	unsigned char	closest;

	i = -1;
	dist = 0xFFFFFF;
	while (++i < palette->count)
	{
		tdist = pow2(rgb.r - palette->colors[i].r)
			+ pow2(rgb.g - palette->colors[i].g)
			+ pow2(rgb.b - palette->colors[i].b);
		if (tdist < dist)
		{
			dist = tdist;
			closest = i;
		}
	}
	return (closest);
}
