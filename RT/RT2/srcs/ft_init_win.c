/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 16:44:57 by agrosset          #+#    #+#             */
/*   Updated: 2018/03/08 14:35:45 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_init_win(t_env *env)
{
	if (SDL_CreateWindowAndRenderer(env->scene->camera->res.width,
		env->scene->camera->res.height, SDL_WINDOW_SHOWN, &env->win,
		&env->renderer))
		return (-1);
	SDL_SetWindowTitle(env->win, "rt @42");
	if (env->width != 0 && env->height != 0)
		SDL_SetWindowPosition(env->win, env->width, env->height);
	return (0);
}
