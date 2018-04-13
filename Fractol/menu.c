/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:26:06 by nbuhler           #+#    #+#             */
/*   Updated: 2017/05/04 12:26:09 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_menu(t_env *e)
{
	if (e->menu == 1)
	{
		mlx_string_put(e->mlx, e->win, 1, 0,
			0xFFFFFF, "Arrows Key to move ");
		mlx_string_put(e->mlx, e->win, 1, 15,
			0xFFFFFF, "Press A to disable mouse (Julia)");
		mlx_string_put(e->mlx, e->win, 1, 30,
			0xFFFFFF, "Press 1, 2, 3 or 4 to change the color");
		mlx_string_put(e->mlx, e->win, 1, 45,
			0xFFFFFF, "Mouse Scrool to zoom :");
		mlx_string_put(e->mlx, e->win, 1, 60,
			0xFFFFFF, "Press * or / to change deepness");
		mlx_string_put(e->mlx, e->win, 1, 75,
			0xFFFFFF, "Press + or - to zoom");
		mlx_string_put(e->mlx, e->win, 1, 90,
			0xFFFFFF, "Press 5 to reset fractal");
		mlx_string_put(e->mlx, e->win, 1, 105,
			0xFFFFFF, "Press ESC to quit the program");
		mlx_string_put(e->mlx, e->win, 1, 120,
			0xFFFFFF, "Press M to hide Menu");
	}
	if (e->menu == 0)
		mlx_string_put(e->mlx, e->win, 1, 0,
			0xFFFFFF, "Press M to display Menu");
}
