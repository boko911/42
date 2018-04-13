/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perturbation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 12:41:32 by agrosset          #+#    #+#             */
/*   Updated: 2018/04/04 14:09:42 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color			ft_perturbation_half_rnd_two_color(t_phpa *ph, t_obj *obj)
{
	static int		frequence = 0;
	static int		bol = 0;
	static int		rnd = 0;
	t_color			color;

	(void)ph;
	if (!bol)
	{
		frequence = rand() % (401) + 1;
		rnd = rand() % frequence;
		bol++;
	}
	if (rnd < (frequence / 2))
		rgb_equal_rgb(&color, &obj->mat->color1);
	else
		rgb_equal_rgb(&color, &obj->mat->color2);
	rnd = (rnd + 1) % frequence;
	return (color);
}

t_color			ft_perturbation_random(t_phpa *ph, t_obj *obj)
{
	t_color	color;

	(void)ph;
	(void)obj;
	color.r = (double)(rand() % 256) / 255.0;
	color.g = (double)(rand() % 256) / 255.0;
	color.b = (double)(rand() % 256) / 255.0;
	return (color);
}

t_color			ft_perturbation_uni(t_phpa *ph, t_obj *obj)
{
	t_color	color;

	(void)ph;
	color = obj->mat->color1;
	return (color);
}
