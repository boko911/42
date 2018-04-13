/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 17:20:31 by nbuhler           #+#    #+#             */
/*   Updated: 2017/04/20 17:20:34 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_setup(t_env *e)
{
	ft_cal_tuile(e->fdf, e->draw);
	ft_center_plan(e->fdf, e->draw);
	ft_draw(e);
	if (e->fdf->menu == 0)
		ft_menu_1(e->fdf);
	else
		ft_menu_2(e->fdf);
	mlx_key_hook(e->fdf->win, my_key_funct, e);
	mlx_loop(e->fdf->mlx);
}
