/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 10:27:24 by acoudray          #+#    #+#             */
/*   Updated: 2018/03/29 17:50:52 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				ft_random_shape_spe(t_env *env, char **line)
{
	int		rnd;
	int		i;
	char	*str;

	rnd = rand();
	rnd = rand() % (4 + 1 - 1) + 1;
	if ((str = ft_memalloc(sizeof(char) * 100)) == NULL)
	{
		ft_putendl("error malloc");
		return (0);
	}
	ft_strcpy(str, "$ position ~ ~ ~ radius ~ angle ~ rotation ~ ~ ~");
	ft_strcat(str, " height ~ start_height ~ end_height ~ material ~*");
	line = ft_strsplit(str, ' ');
	if (rnd == 1 || rnd == 2)
		i = (rnd == 1) ? ft_parse_plane(env, line) : ft_parse_sphere(env, line);
	if (rnd == 3 || rnd == 4)
		i = (rnd == 3) ? ft_parse_cylinder(env, line) : ft_parse_cone(env,
		line);
	ft_delete_line_array(line, 0);
	ft_memdel((void **)&str);
	return (i);
}

int				ft_random_shape(t_env *env, char **line)
{
	int		rnd;
	int		i;
	char	*str;

	rnd = rand();
	rnd = rand() % (3 + 1 - 1) + 1;
	if ((str = ft_memalloc(sizeof(char) * 100)) == NULL)
	{
		ft_putendl("error malloc");
		return (0);
	}
	ft_strcpy(str, "$ position ~ ~ ~ radius ~ angle ~ rotation ~ ~ ~");
	ft_strcat(str, " height ~ start_height ~ end_height ~ material ~*");
	line = ft_strsplit(str, ' ');
	if (rnd == 1 || rnd == 2)
		i = (rnd == 1) ? ft_parse_cone(env, line) : ft_parse_sphere(env, line);
	else
		i = ft_parse_cylinder(env, line);
	ft_delete_line_array(line, 0);
	ft_memdel((void **)&str);
	return (i);
}
