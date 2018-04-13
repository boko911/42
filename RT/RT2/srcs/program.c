/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 13:04:45 by agrosset          #+#    #+#             */
/*   Updated: 2018/03/08 14:27:15 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	run_working_threads(t_env *env)
{
	int			i;
	int			real_i;

	i = -1;
	real_i = 0;
	while (++i < env->n_threads)
	{
		if (pthread_create(&env->threads[real_i], NULL, render_scene,
			(void *)env) == 0)
		{
			real_i++;
			ft_putstr("Thread #");
			ft_putnbr(i + 1);
			ft_putendl(" started!");
		}
		else
		{
			ft_putstr("Failed to create thread #");
			ft_putnbr(i + 1);
			ft_putendl("!");
		}
	}
	env->real_n_threads = real_i;
}

static int	init_working_threads(t_env *env)
{
	if ((env->threads = ft_memalloc(env->n_threads *
		sizeof(pthread_t))) == NULL)
		return (return_print("Error during malloc of pthread_t", -1));
	if (pthread_mutex_init(&env->mutex, NULL))
		return (return_print("Error initializing the mutex", -1));
	env->processed_pixels = 0;
	gettimeofday(&env->clocks[0], NULL);
	SDL_SetWindowTitle(env->win, "rt @42 - Rendering...");
	run_working_threads(env);
	return (0);
}

static void	*clock_count(void *param)
{
	t_env		*env;
	int			i;

	env = (t_env *)param;
	i = -1;
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	while (env->finish != 1)
		SDL_Delay(1);
	gettimeofday(&env->clocks[1], NULL);
	env->new_title = "rt @42 - Rendering finished";
	add_to_queue(env, update_title);
	if (env->print_time)
	{
		ft_putstr("Time taken : ");
		ft_putnbr(env->clocks[1].tv_sec - env->clocks[0].tv_sec);
		ft_putchar(',');
		ft_putnbr((env->clocks[1].tv_usec - env->clocks[0].tv_usec) / 1000);
		ft_putendl("s");
	}
	save_to_bmp(env);
	return (NULL);
}

static int	handle_clock(t_env *env)
{
	return (pthread_create(&env->clockthread, NULL, clock_count, env) ?
		return_print("Can't initialiaze clock thread, aborting...", -1) : 0);
}

void		program(int argc, char **argv)
{
	t_env		*env;

	if (argc < 2)
	{
		if (argc > 0)
			print_usage(argv[0]);
		exit(0);
	}
	if ((env = ft_init_env()) == NULL)
		ft_exit(env, 1);
	if (ft_parse_args(env, argc, argv) == -1)
		ft_exit(env, 1);
	if (ft_init_win(env) == -1)
		ft_exit(env, 1);
	if (ft_init_img(env, &env->bg_img, env->scene->camera->res.width,
		env->scene->camera->res.height) == -1)
		ft_exit(env, 1);
	if (init_working_threads(env) == -1)
		ft_exit(env, 1);
	if (handle_clock(env) == -1)
		ft_exit(env, 1);
	sdl_loop(env);
	destruct_env(env);
}
