/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 12:02:17 by nbuhler           #+#    #+#             */
/*   Updated: 2017/04/18 12:02:18 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_draw		ft_init_draw(t_data *data)
{
	t_draw	draw;

	ft_bzero(&draw, sizeof(t_draw));
	draw.w_t = 0;
	draw.h_t = 0;
	draw.data = data;
	draw.tmp = draw.data;
	draw.xi = 0;
	draw.xf = ft_find_xf(data);
	draw.yi = 0;
	draw.yf = ft_find_yf(data);
	draw.xmin = 0;
	draw.xmax = 0;
	draw.xinc = 0;
	draw.dx = 0;
	draw.ymin = 0;
	draw.ymax = 0;
	draw.yinc = 0;
	draw.dy = 0;
	draw.xoffset = 0;
	draw.yt = 0;
	draw.decalx = 0;
	draw.decaly = 0;
	draw.z = 1;
	return (draw);
}

t_fdf		ft_init_fdf(t_fdf *fdf)
{
	ft_bzero(fdf, sizeof(t_fdf));
	fdf->width = 1400;
	fdf->height = 800;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, fdf->width, fdf->height, "fdf");
	fdf->menu = 0;
	fdf->color = 0xFFFFFF;
	return (*fdf);
}

t_env		ft_init_env(t_fdf *fdf, t_draw *draw)
{
	t_env	e;

	ft_bzero(&e, sizeof(t_env));
	e.fdf = fdf;
	e.draw = draw;
	e.keycode = 0;
	return (e);
}
