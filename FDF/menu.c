/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 18:54:38 by nbuhler           #+#    #+#             */
/*   Updated: 2017/04/21 18:54:40 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_menu_1(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 10, 10, 0xFF0000,
		"Press 'M' to open MENU");
}

void	ft_menu_2(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 10, 1, 0xFF0000,
		"MENU :");
	mlx_string_put(fdf->mlx, fdf->win, 10, 20, 0xFF0000,
		"Press Directional Keys to move");
	mlx_string_put(fdf->mlx, fdf->win, 10, 40, 0xFF0000,
		"Press '+' or '-' to modify deepness");
	mlx_string_put(fdf->mlx, fdf->win, 10, 60, 0xFF0000,
		"Press 'J' to change color to yellow");
	mlx_string_put(fdf->mlx, fdf->win, 10, 80, 0xFF0000,
		"Press 'G' to change color to green");
	mlx_string_put(fdf->mlx, fdf->win, 10, 100, 0xFF0000,
		"Press 'R' to change color to red");
	mlx_string_put(fdf->mlx, fdf->win, 10, 120, 0xFF0000,
		"Press M to reduce menu");
	mlx_string_put(fdf->mlx, fdf->win, 10, 140, 0xFF0000,
		"Press 'ESC' to quit");
}
