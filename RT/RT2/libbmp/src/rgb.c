/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 09:57:09 by agrosset          #+#    #+#             */
/*   Updated: 2016/08/22 10:48:07 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbmp.h"

t_rgb	get_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	t_rgb	rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}

void	set_rgb(t_rgb *rgb, unsigned char r, unsigned char g, unsigned char b)
{
	rgb->r = r;
	rgb->g = g;
	rgb->b = b;
}
