/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:57:22 by nbuhler           #+#    #+#             */
/*   Updated: 2017/05/04 14:57:23 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(int error)
{
	if (error == 1)
	{
		ft_putstr("Please enter 1(Mandelbrot), 2(Julia) or 3(BurningShip)");
		exit(0);
	}
}
