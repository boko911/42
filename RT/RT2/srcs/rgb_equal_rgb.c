/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_equal_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 12:16:35 by agrosset          #+#    #+#             */
/*   Updated: 2016/09/06 14:51:02 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	rgb_equal_rgb(t_color *color_dest, t_color *color_src)
{
	color_dest->r = color_src->r;
	color_dest->g = color_src->g;
	color_dest->b = color_src->b;
}
