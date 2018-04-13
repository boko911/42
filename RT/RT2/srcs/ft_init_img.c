/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 14:11:34 by agrosset          #+#    #+#             */
/*   Updated: 2016/08/10 10:14:17 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_init_img(t_env *env, t_img *img, int width, int height)
{
	if ((img->img = SDL_CreateTexture(env->renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET, width, height)) == NULL)
		return (return_print("error during image initialization", -1));
	pthread_mutex_init(&img->mutex, NULL);
	img->renderer = env->renderer;
	SDL_SetRenderTarget(env->renderer, img->img);
	SDL_SetRenderDrawColor(env->renderer, 0, 0, 0, 0);
	SDL_RenderClear(env->renderer);
	SDL_QueryTexture(img->img, NULL, NULL, &img->res.width, &img->res.height);
	return (0);
}
