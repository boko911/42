/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:57:15 by nbuhler           #+#    #+#             */
/*   Updated: 2017/04/18 13:57:17 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_calcul(t_env *e)
{
	ft_cal_tuile(e->fdf, e->draw);
	ft_center_plan(e->fdf, e->draw);
}

void		ft_cal_tuile(t_fdf *fdf, t_draw *draw)
{
	int		w_t;
	int		h_t;

	w_t = fdf->width / (draw->xf + draw->yf);
	h_t = w_t / 2;
	draw->w_t = w_t;
	draw->h_t = h_t;
}

void		ft_center_plan(t_fdf *fdf, t_draw *draw)
{
	int decalx;
	int decaly;

	decalx = ((fdf->width / 2) - (draw->xf * draw->w_t) / 2) * 2;
	decaly = ((fdf->height / 2) - (draw->yf * draw->h_t)) / 2;
	if (decalx >= fdf->width / 2 && draw->h_t < decaly)
	{
		draw->decalx = decalx;
		draw->decaly = (decaly + (decaly * 2));
	}
	if (decalx >= fdf->width / 2 && draw->h_t > decaly)
	{
		draw->decalx = decalx;
		draw->decaly = (decaly + decaly * 2);
	}
	if (decalx < fdf->width / 2 && draw->h_t < decaly)
	{
		draw->decalx = decalx;
		draw->decaly = decaly;
	}
	if (decalx < fdf->width / 2 && draw->h_t > decaly)
	{
		draw->decalx = (decalx - (decalx * 0.25) / 2);
		draw->decaly = decaly;
	}
}
