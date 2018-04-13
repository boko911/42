/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:52:21 by nbuhler           #+#    #+#             */
/*   Updated: 2017/04/18 13:52:46 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_color(int keycode, t_env *e)
{
	if (keycode == 5)
		e->fdf->color = 0x339933;
	if (keycode == 15)
		e->fdf->color = 0xFF0000;
	if (keycode == 38)
		e->fdf->color = 0xFFFF00;
	ft_move(0, 0, 0, e);
}

void	ft_refresh(t_env *e)
{
	if (e->fdf->menu == 1)
		e->fdf->menu = 0;
	else
		e->fdf->menu = 1;
	ft_move(0, 0, 0, e);
}

void	ft_move(int x, int y, int z, t_env *e)
{
	static	int	contx;
	static	int	conty;
	static	int	contz;

	contx = contx + x;
	conty = conty + y;
	contz = z;
	if (z != 0)
		contz = contz + z;
	else
		ft_calcul(e);
	ft_center_plan(e->fdf, e->draw);
	e->draw->decalx = e->draw->decalx + contx;
	e->draw->decaly = e->draw->decaly + conty;
	e->draw->z = e->draw->z + contz;
	mlx_clear_window(e->fdf->mlx, e->fdf->win);
	ft_draw(e);
	if (e->fdf->menu == 0)
		ft_menu_1(e->fdf);
	else
		ft_menu_2(e->fdf);
	mlx_key_hook(e->fdf->win, my_key_funct, e);
	mlx_loop(e->fdf->mlx);
}

int		my_key_funct(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		ft_move(-10, 0, 0, e);
	if (keycode == 124)
		ft_move(10, 0, 0, e);
	if (keycode == 126)
		ft_move(0, -10, 0, e);
	if (keycode == 125)
		ft_move(0, 10, 0, e);
	if (keycode == 69)
		ft_move(0, 0, 1, e);
	if (keycode == 78)
		ft_move(0, 0, -1, e);
	if (keycode == 46)
		ft_refresh(e);
	if (keycode == 5 || keycode == 15 || keycode == 38)
		change_color(keycode, e);
	return (0);
}
