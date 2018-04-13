/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:56:24 by nbuhler           #+#    #+#             */
/*   Updated: 2017/05/04 14:56:26 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move(t_env *e, int k)
{
	if (k == 126)
	{
		e->y = e->y + 10;
		e->x = e->x + 0;
	}
	if (k == 125)
	{
		e->y = e->y - 10;
		e->x = e->x + 0;
	}
	if (k == 124)
	{
		e->y = e->y + 0;
		e->x = e->x - 10;
	}
	if (k == 123)
	{
		e->y = e->y + 0;
		e->x = e->x + 10;
	}
}

void	ft_change_color(t_env *e, int k)
{
	if (k == 83)
		e->color = 0xFF6935;
	if (k == 84)
		e->color = 0x0065FF;
	if (k == 85)
		e->color = 0x478532;
	if (k == 86)
		e->color = 0x123456;
}

void	ft_deepness(t_env *e, int k)
{
	if (k == 67)
		e->ite_max += 5;
	if (k == 75)
		e->ite_max -= 5;
}

void	ft_display_menu(t_env *e)
{
	if (e->menu == 0)
		e->menu = 1;
	else
		e->menu = 0;
}

int		my_key_funct(int k, t_env *e)
{
	if (k == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	if (k == 69)
		ft_zoom_in(e);
	if (k == 78)
		ft_zoom_out(e);
	if (k == 126 || k == 125 || k == 123 || k == 124)
		ft_move(e, k);
	if (k == 83 || k == 84 || k == 85 || k == 86)
		ft_change_color(e, k);
	if (k == 75 || k == 67)
		ft_deepness(e, k);
	if (k == 87)
		ft_reset(e);
	if (k == 46)
		ft_display_menu(e);
	if (k == 0)
		ft_enadisa_mouse(e);
	ft_refresh(e);
	return (0);
}
