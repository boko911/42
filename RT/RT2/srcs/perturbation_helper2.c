/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perturbation_helper2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 12:41:32 by agrosset          #+#    #+#             */
/*   Updated: 2018/04/02 19:27:41 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color			*ft_choose_by_two_coord(int x, int y,
	int *frequence, t_obj *obj)
{
	if (((x % frequence[0]) < (frequence[0] / 2) &&
		(y % frequence[1]) < (frequence[1] / 2)) ||
		((x % frequence[0]) >= (frequence[0] / 2) &&
		(y % frequence[1]) >= (frequence[1] / 2)))
		return (&obj->mat->color1);
	return (&obj->mat->color2);
}

t_color			*ft_choose_by_one_coord(int coord, int frequence, t_obj *obj)
{
	if ((coord % frequence) < (frequence / 2))
		return (&obj->mat->color1);
	return (&obj->mat->color2);
}
