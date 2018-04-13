/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perturbation2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 12:41:32 by agrosset          #+#    #+#             */
/*   Updated: 2018/01/29 13:51:37 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color			ft_perturbation_colone_for_all(t_phpa *ph, t_obj *obj)
{
	static int		frequence = 0;
	static int		bol = 0;
	static t_color	color;

	if (!bol)
	{
		frequence = rand() % (201);
		bol++;
	}
	rgb_equal_rgb(&color, ft_choose_by_one_coord(ph->x, frequence, obj));
	return (color);
}

t_color			ft_perturbation_line_for_all(t_phpa *ph, t_obj *obj)
{
	static int		frequence = 0;
	static int		bol = 0;
	static t_color	color;

	if (!bol)
	{
		frequence = rand() % (201);
		bol++;
	}
	rgb_equal_rgb(&color, ft_choose_by_one_coord(ph->y, frequence, obj));
	return (color);
}

t_color			ft_perturbation_dam_for_all(t_phpa *ph, t_obj *obj)
{
	static int	frequence[2] = {0, 0};
	static int	bol = 0;
	t_color		color;

	if (!bol)
	{
		frequence[0] = rand() % (201);
		frequence[1] = rand() % (201);
		bol++;
	}
	rgb_equal_rgb(&color, ft_choose_by_two_coord(ph->x, ph->y,
		frequence, obj));
	return (color);
}
