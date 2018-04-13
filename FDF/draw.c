/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 12:01:54 by nbuhler           #+#    #+#             */
/*   Updated: 2017/04/18 12:01:56 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_trace_dxsup(t_fdf *fdf, t_draw *draw)
{
	int	i;
	int	x;
	int	y;
	int	cumul;

	x = draw->xmin;
	y = draw->ymin;
	i = 1;
	cumul = draw->dx / 2;
	while (i <= draw->dx)
	{
		x += draw->xinc;
		cumul += draw->dy;
		if (cumul >= draw->dx)
		{
			cumul -= draw->dx;
			y += draw->yinc;
		}
		mlx_pixel_put(fdf->mlx, fdf->win, x, y, fdf->color);
		i++;
	}
}

void	ft_trace_dysup(t_fdf *fdf, t_draw *draw)
{
	int	i;
	int	x;
	int	y;
	int	cumul;

	x = draw->xmin;
	y = draw->ymin;
	i = 1;
	cumul = draw->dy / 2;
	while (i <= draw->dy)
	{
		y += draw->yinc;
		cumul += draw->dx;
		if (cumul >= draw->dy)
		{
			cumul -= draw->dy;
			x += draw->xinc;
		}
		i++;
		mlx_pixel_put(fdf->mlx, fdf->win, x, y, fdf->color);
	}
}

void	ft_put_pixel(t_fdf *fdf, t_draw *draw)
{
	int	x;
	int	y;

	x = draw->xmin;
	y = draw->ymin;
	draw->dx = draw->xmax - x;
	draw->dy = draw->ymax - y;
	draw->xinc = (draw->dx > 0) ? 1 : -1;
	draw->yinc = (draw->dy > 0) ? 1 : -1;
	draw->dx = abs(draw->dx);
	draw->dy = abs(draw->dy);
	mlx_pixel_put(fdf->mlx, fdf->win, x, y, fdf->color);
	if (draw->dx > draw->dy)
		ft_trace_dxsup(fdf, draw);
	else
		ft_trace_dysup(fdf, draw);
}

void	ft_draw_lines(t_fdf *fdf, t_draw *draw, int i)
{
	while (++i < (draw->xf))
	{
		draw->xmin = draw->xoffset;
		draw->ymin = draw->yt - (draw->tmp->z[i] * draw->z);
		if (i + 1 < draw->xf)
		{
			draw->xmax = draw->xoffset + draw->w_t;
			draw->ymax = draw->yt + draw->h_t - (draw->tmp->z[i + 1] * draw->z);
		}
		else
		{
			draw->xmax = draw->xmin;
			draw->ymax = draw->ymin;
		}
		ft_put_pixel(fdf, draw);
		if (draw->tmp->next != NULL)
		{
			draw->xmax = draw->xmin - draw->w_t;
			draw->ymax = draw->yt + draw->h_t -
			(draw->tmp->next->z[i] * draw->z);
			ft_put_pixel(fdf, draw);
		}
		draw->xoffset = draw->xoffset + draw->w_t;
		draw->yt = draw->yt + draw->h_t;
	}
}

void	ft_draw(t_env *e)
{
	int		i;
	t_data	*tmp;

	tmp = e->draw->tmp;
	i = -1;
	while (e->draw->tmp)
	{
		e->draw->xoffset = e->draw->decalx;
		e->draw->yt = e->draw->decaly;
		ft_draw_lines(e->fdf, e->draw, i);
		i = -1;
		e->draw->decalx = e->draw->decalx - e->draw->w_t;
		e->draw->decaly = e->draw->decaly + e->draw->h_t;
		e->draw->tmp = e->draw->tmp->next;
	}
	e->draw->tmp = tmp;
}
