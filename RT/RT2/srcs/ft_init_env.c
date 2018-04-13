/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 14:23:19 by agrosset          #+#    #+#             */
/*   Updated: 2018/02/14 14:48:08 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		myaudiocallback(void *userdata, Uint8 *stream, int streamlenght)
{
	t_audiodata	*audio;
	Uint32		lenght;

	audio = (t_audiodata*)userdata;
	if (audio->lenght == 0)
		return ;
	lenght = (Uint32)streamlenght;
	lenght = (lenght > audio->lenght ? audio->lenght : lenght);
	SDL_memcpy(stream, audio->pos, lenght);
	audio->pos += lenght;
	audio->lenght -= lenght;
}

static void		init_audio(t_env *env)
{
	SDL_Init(SDL_INIT_AUDIO);
	if (SDL_LoadWAV(FILEPATH, &(env->wavspec),
		&(env->wavstart), &(env->wavlenght)) == NULL)
	{
		ft_putendl("Filepath couldnt load correctly");
	}
	env->audio.pos = env->wavstart;
	env->audio.lenght = env->wavlenght;
	env->wavspec.callback = myaudiocallback;
	env->wavspec.userdata = &(env->audio);
	env->device = SDL_OpenAudioDevice(NULL, 0,
		&(env->wavspec), NULL, SDL_AUDIO_ALLOW_ANY_CHANGE);
	if (env->device == 0)
		ft_putendl("NO DEVICE");
}

t_env			*ft_init_env(void)
{
	t_env		*env;

	if ((env = (t_env *)ft_memalloc(sizeof(t_env))) == NULL)
	{
		ft_putendl("malloc error: env");
		return (NULL);
	}
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		ft_putendl("SDL2 init error");
		free(env);
		return (NULL);
	}
	env->n_threads = 1;
	env->finish = 0;
	env->width = 0;
	env->height = 0;
	ft_init_material(&env->base_material);
	init_audio(env);
	return (env);
}
