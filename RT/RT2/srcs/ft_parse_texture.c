/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 14:15:07 by agrosset          #+#    #+#             */
/*   Updated: 2018/04/02 19:21:01 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	ft_parse_texture_4(char **line, int *i, t_texture *text)
{
	if (!ft_strcmp(line[i[0]], "begin"))
	{
		if (line[i[0] + 1] == NULL || !(ft_strlen(line[i[0] + 1]) > 0) ||
			line[i[0] + 2] == NULL || !(ft_strlen(line[i[0] + 2]) > 0))
			return (return_print("Error parsing texture begin", 0));
		if (!parse_int(line, i, &text->begin_x) ||
			!parse_int(line, i, &text->begin_y))
			return (return_print("Error parsing texture begin", -1));
	}
	if (!ft_strcmp(line[i[0]], "elarge"))
	{
		if (line[i[0] + 1] == NULL || !(ft_strlen(line[i[0] + 1]) > 0) ||
			line[i[0] + 2] == NULL || !(ft_strlen(line[i[0] + 2]) > 0))
			return (return_print("Error parsing texture elarge", 0));
		if (!parse_double(line, i, &text->elarge_x, 5) ||
			!parse_double(line, i, &text->elarge_y, 5))
			return (return_print("Error parsing texture begin", -1));
	}
	return (1);
}

static int	ft_parse_texture_3(char **line, int *i, t_texture *text)
{
	if (!ft_strcmp(line[i[0]], "id"))
	{
		if (line[i[0] + 1] == NULL || !(ft_strlen(line[i[0] + 1]) > 0))
			return (return_print("Error parsing texture id", 0));
		else
		{
			if (!(text->name = ft_strdup(line[i[0] + 1])))
				return (return_print("malloc error", 0));
			i[0] += 1;
			i[1] += 1;
		}
	}
	return (ft_parse_texture_4(line, i, text));
}

static int	ft_parse_texture_2(char **line, int *i, t_texture *text,
	t_scene *scene)
{
	t_surface	*src_surf;
	t_list		*actuel;

	if (!ft_strcmp(line[i[0]], "image"))
	{
		actuel = scene->surface;
		while (actuel != NULL)
		{
			src_surf = (t_surface *)actuel->content;
			if (!ft_strcmp(src_surf->name, line[i[0] + 1]))
				break ;
			actuel = actuel->next;
		}
		if (!actuel)
			return (return_print("surface actuellement non creer.", 0));
		else
		{
			text->surface = src_surf;
			i[1]++;
		}
	}
	return (ft_parse_texture_3(line, i, text));
}

int			ft_parse_texture(t_env *env, char **line)
{
	int			i[2];
	t_texture	*text;
	t_list		*lst;

	text = NULL;
	lst = NULL;
	if (!ft_init_texture(&text, env))
		return (0);
	i[0] = 0;
	i[1] = 0;
	while (line[++i[0]])
		if (ft_parse_texture_2(line, i, text, env->scene) == 0)
		{
			free(lst);
			free(text->name);
			free(text);
			return (0);
		}
	if (!ft_init_texture_p2(&lst, text))
		return (0);
	if (env->scene->texture == NULL)
		env->scene->texture = lst;
	else
		ft_lstadd(&(env->scene->texture), lst);
	return (i[1] == 2 ? 1 : return_print("error t_surface imcomplete", 0));
}
