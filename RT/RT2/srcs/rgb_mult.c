/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 12:48:35 by agrosset          #+#    #+#             */
/*   Updated: 2016/09/06 14:54:42 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		rgb_mult(t_color *color, double mult)
{
	color->r *= mult;
	color->g *= mult;
	color->b *= mult;
}

t_color		rgb_mult_cpy(t_color color, double mult)
{
	t_color	ret;

	ret.r = color.r * mult;
	ret.g = color.g * mult;
	ret.b = color.b * mult;
	return (ret);
}
