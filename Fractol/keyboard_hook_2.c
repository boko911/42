/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hook_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:32:28 by nbuhler           #+#    #+#             */
/*   Updated: 2017/05/04 18:08:03 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom_in(t_env *e)
{
	e->x += e->mouse_x / 11;
	e->y += e->mouse_y / 11;
	e->z = e->z * 1.1;
	e->y = e->y * 1.1;
	e->x = e->x * 1.1;
}

void	ft_zoom_out(t_env *e)
{
	e->x -= e->mouse_x / 11;
	e->y -= e->mouse_y / 11;
	e->z = e->z / 1.1;
	e->x = e->x / 1.1;
	e->y = e->y / 1.1;
}

void	ft_enadisa_mouse(t_env *e)
{
	if (e->mouse == 1)
		e->mouse = 0;
	else
		e->mouse = 1;
}
