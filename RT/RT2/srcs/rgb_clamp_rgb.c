/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_clamp_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 14:45:07 by agrosset          #+#    #+#             */
/*   Updated: 2016/09/06 14:48:42 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		rgb_clamp_rgb(t_color c_src)
{
	t_color	color;

	rgb_equal_rgb(&color, &c_src);
	if (color.r < 0)
		color.r = 0;
	else if (color.r > 1)
		color.r = 1;
	if (color.g < 0)
		color.g = 0;
	else if (color.g > 1)
		color.g = 1;
	if (color.b < 0)
		color.b = 0;
	else if (color.b > 1)
		color.b = 1;
	return (color);
}
