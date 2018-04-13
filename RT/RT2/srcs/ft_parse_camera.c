/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:10:54 by agrosset          #+#    #+#             */
/*   Updated: 2016/08/08 13:54:51 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		ft_parse_camera_3(char **line, int *i, t_env *env, int *valid)
{
	if (!ft_strcmp(line[*i], "fov"))
	{
		if (!parse_double(line, i, &env->scene->camera->fov, 1))
			return (return_print("Error parsing camera field of view", 0));
		else
			*valid |= 8;
	}
	if (!ft_strcmp(line[*i], "antialiasing"))
	{
		if (!parse_int(line, i, &env->scene->camera->antialiasing))
			return (return_print("Error parsing camera antialiasing", 0));
		else
			env->scene->camera->antialiasing =
				ft_fclamp(env->scene->camera->antialiasing, 1, 5);
		if (env->scene->camera->antialiasing <= 0)
			return (return_print(
				"Error antialiasing must be superior to 0", 0));
	}
	return (1);
}

static int		ft_parse_camera_2(char **line, int *i, t_env *env, int *valid)
{
	if (!ft_strcmp(line[*i], "screen"))
	{
		if (!parse_resolution(line, i, &env->scene->camera->res))
			return (return_print("Error parsing camera resolution", 0));
		else
			*valid |= 1;
	}
	if (!ft_strcmp(line[*i], "position"))
	{
		if (!parse_vector3(line, i, &env->scene->camera->pos))
			return (return_print("Error parsing camera position", 0));
		else
			*valid |= 2;
	}
	else if (!ft_strcmp(line[*i], "rotation"))
	{
		if (!parse_vector3(line, i, &env->scene->camera->dir))
			return (return_print("Error parsing camera rotation", 0));
		else
			*valid |= 4;
	}
	return (ft_parse_camera_3(line, i, env, valid));
}

int				ft_parse_camera(t_env *env, char **line)
{
	int				i;
	int				valid;

	if (env->scene == NULL)
		return (return_print("Error, a scene must be declared first", 0));
	if (env->scene->camera == NULL && (env->scene->camera =
		(t_camera *)ft_memalloc(sizeof(t_camera))) == NULL)
		return (return_print("malloc error", 0));
	i = 0;
	valid = 0;
	env->scene->camera->antialiasing = 1;
	while (line[++i])
	{
		if (ft_parse_camera_2(line, &i, env, &valid) == 0)
		{
			free(env->scene->camera);
			return (0);
		}
	}
	return (valid == 15 && (ft_init_camera(env->scene->camera)));
}
