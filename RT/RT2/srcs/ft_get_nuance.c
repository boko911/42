/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nuance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:35:58 by agrosset          #+#    #+#             */
/*   Updated: 2018/04/02 19:00:55 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int g_sleep;

double	ft_get_nuance(t_phpa *ph, t_obj *obj, char c, int a)
{
	static t_color color;

	if (c == 'r')
	{
		if (a)
		{
			if (obj->mat->texture != NULL)
				color = ft_texture_img(ph, obj);
			else
				color = obj->mat->ft_perturbation(ph, obj);
		}
		return (color.r);
	}
	if (c == 'g')
		return (color.g);
	if (c == 'b')
		return (color.b);
	return (0.0);
}
