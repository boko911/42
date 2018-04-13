/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perturbation4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 12:41:32 by agrosset          #+#    #+#             */
/*   Updated: 2018/04/02 19:00:16 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	ft_is_introu(t_phpa *ph, t_perturbation *perturbation)
{
	int	x_centre;
	int	y_centre;

	if ((ph->x % perturbation->frequence[0]) < (perturbation->frequence[0] / 2))
		x_centre = (ph->x / perturbation->frequence[0]) *
		perturbation->frequence[0];
	else
		x_centre = ((ph->x / perturbation->frequence[0]) + 1) *
			perturbation->frequence[0];
	if (((ph->y % perturbation->frequence[0]) <
		(perturbation->frequence[0] / 2)))
		y_centre = (ph->y / perturbation->frequence[0]) *
		perturbation->frequence[0];
	else
		y_centre = ((ph->y / perturbation->frequence[0]) + 1) *
			perturbation->frequence[0];
	if (sqrt(POW2((ph->x - x_centre)) + POW2((ph->y - y_centre))) <
		perturbation->frequence[1])
		return (1);
	return (0);
}

t_color		ft_perturbation_a_trous(t_phpa *ph, t_obj *obj)
{
	t_perturbation		*perturbation;
	t_color				color;

	if ((perturbation =
		get_perturbation(ph, obj, &ft_perturbation_a_trous)) == NULL)
		return (obj->mat->color1);
	if (ft_is_introu(ph, perturbation))
	{
		obj->mat->refra = 1;
		obj->mat->n = 1.0;
		obj->mat->k_diffuse = 0;
		rgb_equal_rgb(&color, &obj->mat->color1);
	}
	else
	{
		obj->mat->refra = 0.0;
		obj->mat->k_diffuse = 0.9;
		rgb_equal_rgb(&color, &obj->mat->color1);
	}
	return (color);
}
