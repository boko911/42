/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 10:43:04 by agrosset          #+#    #+#             */
/*   Updated: 2018/03/08 15:05:19 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	destruct_env(t_env *env)
{
	if (!env)
		return ;
	if (env->bg_img.img)
		SDL_DestroyTexture(env->bg_img.img);
	env->bg_img.img = NULL;
	if (env->renderer)
		SDL_DestroyRenderer(env->renderer);
	env->renderer = NULL;
	if (env->win)
		SDL_DestroyWindow(env->win);
	env->win = NULL;
	if (env->scene)
		clean_scene(env->scene);
	free(env->wavstart);
}

void	ft_exit(t_env *env, int i)
{
	destruct_env(env);
	exit(i);
}
