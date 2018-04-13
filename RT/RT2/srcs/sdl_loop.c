/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 10:41:49 by agrosset          #+#    #+#             */
/*   Updated: 2018/03/08 14:23:15 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	execute_queue(t_env *env)
{
	t_list		*tmp;
	void		(*method)(t_env *env);

	if (!env->queue)
		return ;
	pthread_mutex_lock(&env->queuemutex);
	tmp = env->queue;
	while (tmp)
	{
		method = (void (*)(t_env *env))tmp->content;
		if (method != NULL)
			method(env);
		tmp = env->queue->next;
		free(env->queue);
		env->queue = tmp;
	}
	env->queue = NULL;
	pthread_mutex_unlock(&env->queuemutex);
}

static void	check_sound(t_env *env)
{
	if (env->play_sound == 1)
	{
		if (env->finish == 0)
		{
			SDL_PauseAudioDevice(env->device, 0);
			if (env->audio.lenght < 20000)
			{
				env->audio.pos = env->wavstart;
				env->audio.lenght = env->wavlenght;
			}
		}
		else
		{
			SDL_PauseAudioDevice(env->device, 1);
			SDL_CloseAudioDevice(env->device);
		}
	}
}

void		button_pressed(SDL_Event event)
{
	const char *command;

	if (event.key.keysym.sym == SDLK_a)
	{
		command = "sh script/demo1.sh";
		system(command);
	}
	if (event.key.keysym.sym == SDLK_z)
	{
		command = "sh script/demo2.sh";
		system(command);
	}
}

static void	do_work(t_env *env)
{
	pthread_mutex_lock(&env->bg_img.mutex);
	check_sound(env);
	SDL_SetRenderTarget(env->renderer, NULL);
	SDL_SetRenderDrawColor(env->renderer, 0, 0, 0, 0);
	SDL_RenderClear(env->renderer);
	SDL_RenderCopy(env->renderer, env->bg_img.img, NULL, NULL);
	SDL_RenderPresent(env->renderer);
	pthread_mutex_unlock(&env->bg_img.mutex);
	execute_queue(env);
}

void		sdl_loop(t_env *env)
{
	SDL_Event				event;
	SDL_MouseButtonEvent	mouse_button_event;

	env->loop = 1;
	while (env->loop)
	{
		SDL_PollEvent(&event);
		if (env->finish == 1 && (event.type == SDL_QUIT ||
			event.type == SDL_KEYDOWN))
			button_pressed(event);
		if (env->finish == 1 && (event.type == SDL_QUIT ||
			(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)))
			env->loop = 0;
		if (env->finish == 1 && event.type == SDL_MOUSEBUTTONDOWN)
			mouse_button_event = event.button;
		do_work(env);
		SDL_Delay(10);
	}
}
