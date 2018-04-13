/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:57:11 by nbuhler           #+#    #+#             */
/*   Updated: 2017/05/04 14:57:12 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_refresh(t_env *e)
{
	if (e->type == 1 || e->type == 3)
		ft_draw_m(e);
	if (e->type == 2)
		ft_draw_j(e);
}

void	ft_reset(t_env *e)
{
	e->x = -1;
	e->y = -1;
	e->z = 100;
	e->color = 0x123456;
	e->ite_max = 50;
	if (e->type == 1 || e->type == 3)
	{
		ft_init_fractal_mandelbrot(e);
		ft_center_plan(e);
	}
	if (e->type == 2)
	{
		ft_init_fractal_julia(e);
		ft_center_plan(e);
	}
}

t_env	ft_init_env(t_env *e)
{
	ft_bzero(e, sizeof(t_env));
	e->width = 480;
	e->height = 400;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->width, e->height, "Fractol");
	e->img = mlx_new_image(e->mlx, e->width, e->height);
	e->pxl = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->ed));
	e->fractal = (t_fractal *)malloc(sizeof(t_fractal));
	e->ite_max = 50;
	e->z = 100;
	e->x = 0;
	e->y = 0;
	e->mouse_x = 1;
	e->mouse_y = 1;
	e->menu = 0;
	e->color = 0x123456;
	return (*e);
}

void	ft_setup(t_env *e)
{
	mlx_hook(e->win, MOTION_NOTIFY, PTR_MOTION_MASK, mouse_move_hook, e);
	mlx_mouse_hook(e->win, mouse_click_hook, e);
	if (e->type == 1 || e->type == 3)
	{
		ft_init_fractal_mandelbrot(e);
		ft_center_plan(e);
		ft_draw_m(e);
	}
	if (e->type == 2)
	{
		ft_init_fractal_julia(e);
		ft_center_plan(e);
		ft_draw_j(e);
	}
	mlx_key_hook(e->win, my_key_funct, e);
	mlx_loop(e->mlx);
}
