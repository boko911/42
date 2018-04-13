/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 12:48:35 by agrosset          #+#    #+#             */
/*   Updated: 2016/09/06 14:54:03 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		rgb_add_rgb(t_color *colora, t_color colorb)
{
	colora->r += colorb.r;
	colora->g += colorb.g;
	colora->b += colorb.b;
}

void		rgb_add(t_color *color, float r, float g, float b)
{
	color->r += r;
	color->g += g;
	color->b += b;
}
