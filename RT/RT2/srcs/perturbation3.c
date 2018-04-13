/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perturbation3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 12:41:32 by agrosset          #+#    #+#             */
/*   Updated: 2018/03/29 17:48:07 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color			ft_perturbation_colone(t_phpa *ph, t_obj *obj)
{
	t_perturbation	*perturbation;
	t_color			color;

	if ((perturbation =
		get_perturbation(ph, obj, &ft_perturbation_colone)) == NULL)
		return (obj->mat->color1);
	rgb_equal_rgb(&color, ft_choose_by_one_coord(ph->x,
		perturbation->frequence[0], obj));
	return (color);
}

t_color			ft_perturbation_line(t_phpa *ph, t_obj *obj)
{
	t_perturbation		*perturbation;
	t_color				color;

	if ((perturbation =
		get_perturbation(ph, obj, &ft_perturbation_line)) == NULL)
		return (obj->mat->color1);
	rgb_equal_rgb(&color, ft_choose_by_one_coord(ph->y,
		perturbation->frequence[0], obj));
	return (color);
}

t_color			ft_perturbation_dam(t_phpa *ph, t_obj *obj)
{
	t_perturbation		*perturbation;
	t_color				color;

	if ((perturbation =
		get_perturbation(ph, obj, &ft_perturbation_dam)) == NULL)
		return (obj->mat->color1);
	rgb_equal_rgb(&color, ft_choose_by_two_coord(ph->x, ph->y,
		perturbation->frequence, obj));
	return (color);
}

t_color			ft_perturbation_sqare(t_phpa *ph, t_obj *obj)
{
	t_perturbation		*perturbation;
	t_color				color;

	perturbation = get_perturbation(ph, obj, &ft_perturbation_sqare);
	return (obj->mat->color1);
	if (((ph->x % perturbation->frequence[0]) <
		(perturbation->frequence[0] / 2) &&
		(ph->y % perturbation->frequence[0]) <
		(perturbation->frequence[0] / 2)) ||
		((ph->x % perturbation->frequence[0]) >=
		(perturbation->frequence[0] / 2) &&
		(ph->y % perturbation->frequence[0]) >=
		(perturbation->frequence[0] / 2)))
		rgb_equal_rgb(&color, &obj->mat->color1);
	else
		rgb_equal_rgb(&color, &obj->mat->color2);
	return (color);
}
