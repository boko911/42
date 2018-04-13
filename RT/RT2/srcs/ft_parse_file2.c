/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:48:31 by nbuhler           #+#    #+#             */
/*   Updated: 2018/04/02 19:00:38 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	ft_parse_error(int line_nbr, char **line)
{
	free(*line);
	ft_putstr("error processing line ");
	ft_putnbr(line_nbr);
	ft_putendl("\nexiting...");
	return (-1);
}

static int	ft_parse_line_p2(t_env *env, char **line)
{
	if (!ft_strcmp(line[0], "$"))
		return (ft_delete_line_array(line, ft_random_shape(env, line)));
	else if (!ft_strcmp(line[0], "$*"))
		return (ft_delete_line_array(line, ft_random_shape_spe(env, line)));
	ft_putstr("Unknown type : ");
	ft_putendl(line[0]);
	return (ft_delete_line_array(line, 0));
}

static int	ft_parse_line(t_env *env, char **line)
{
	if (!ft_strcmp(line[0], "scene"))
		return (ft_delete_line_array(line, ft_parse_scene(env, line)));
	else if (!ft_strcmp(line[0], "camera"))
		return (ft_delete_line_array(line, ft_parse_camera(env, line)));
	else if (!ft_strcmp(line[0], "sphere"))
		return (ft_delete_line_array(line, ft_parse_sphere(env, line)));
	else if (!ft_strcmp(line[0], "plane"))
		return (ft_delete_line_array(line, ft_parse_plane(env, line)));
	else if (!ft_strcmp(line[0], "cylinder"))
		return (ft_delete_line_array(line, ft_parse_cylinder(env, line)));
	else if (!ft_strcmp(line[0], "cone"))
		return (ft_delete_line_array(line, ft_parse_cone(env, line)));
	else if (!ft_strcmp(line[0], "light"))
		return (ft_delete_line_array(line, ft_parse_light(env, line)));
	else if (!ft_strcmp(line[0], "material"))
		return (ft_delete_line_array(line, ft_parse_material(env, line)));
	else if (!ft_strcmp(line[0], "image"))
		return (ft_delete_line_array(line, ft_parse_image(env, line)));
	else if (!ft_strcmp(line[0], "texture"))
		return (ft_delete_line_array(line, ft_parse_texture(env, line)));
	return (ft_parse_line_p2(env, line));
}

int			is_xml(char *argv)
{
	int		ret;
	int		len;
	int		i;

	ret = 0;
	len = ft_strlen(argv);
	i = len - 4;
	if (argv[i] == '.')
	{
		if (argv[++i] == 'x')
		{
			if (argv[++i] == 'm')
			{
				if (argv[++i] == 'l' && argv[i + 1] == '\0')
				{
					ret = 1;
				}
			}
		}
	}
	return (ret);
}

int			get_next_line_file(t_env *env, int fd)
{
	char	*line;
	char	**str;
	int		l;

	l = 0;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		++l;
		str = ft_strsplit(line, ' ');
		if (*str == NULL || ft_strlen(*str) == 0 || !ft_strncmp(*str, "--", 2))
		{
			ft_delete_line_array(str, 0);
			free(line);
			continue ;
		}
		if (!ft_parse_line(env, str))
			return (ft_parse_error(l, &line));
		free(line);
	}
	close(fd);
	return (env->scene && env->scene->camera ? 0 : -1);
}
