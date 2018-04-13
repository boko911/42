/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 17:01:21 by agrosset          #+#    #+#             */
/*   Updated: 2018/04/02 14:58:53 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		set_img_pixel(t_img *img, int x, int y, t_color color)
{
	if (x >= 0 && x < img->res.width && y >= 0 && y < img->res.height)
	{
		pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
		pthread_mutex_lock(&img->mutex);
		SDL_SetRenderTarget(img->renderer, img->img);
		SDL_SetRenderDrawColor(img->renderer, color.r * 255, color.g * 255,
			color.b * 255, 255);
		SDL_RenderDrawPoint(img->renderer, x, y);
		pthread_mutex_unlock(&img->mutex);
		pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	}
}
