/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_israndom_mat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 12:24:06 by agrosset          #+#    #+#             */
/*   Updated: 2018/01/29 16:18:32 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	ft_perturbation_line_mat(char **line, char *str, const char *id)
{
	ft_strcpy(*line, "material id ");
	ft_strcat(*line, str);
	ft_strcat(*line, " color1 ~ ~ ~ ambiant ~ diffuse ~ ");
	ft_strcat(*line, "specular ~ shininess ~");
	if (!ft_strcmp(id, "~+"))
		ft_strcat(*line, " refraction ~ n ~");
	else if (!ft_strcmp(id, "~*"))
		ft_strcat(*line, " reflexion ~ refraction ~ n ~");
	else if (!ft_strcmp(id, "~/"))
		ft_strcat(*line, " reflexion ~");
}

static int	ft_alloc_mat(int nb_random_mat, char **str, char **line)
{
	if ((*str = ft_memalloc(sizeof(char) * (5 + 12))) == NULL)
		return (0);
	*str = ft_strcpy(*str, "rand");
	if ((*line = ft_itoa(nb_random_mat)) == NULL)
	{
		ft_memdel((void **)str);
		return (0);
	}
	*str = ft_strcat(*str, *line);
	ft_memdel((void **)line);
	if ((*line = ft_memalloc(sizeof(char) * 109)) == NULL)
	{
		ft_memdel((void **)&str);
		return (0);
	}
	return (1);
}

int			ft_random_mat(t_env *env, const char *id, t_material **mat)
{
	static int	nb_random_mat = 0;
	char		*line;
	char		*str;
	char		**line_mat;
	int			bol;

	if (!ft_alloc_mat(nb_random_mat, &str, &line))
		return (0);
	ft_perturbation_line_mat(&line, str, id);
	if ((line_mat = ft_strsplit(line, ' ')) == NULL)
	{
		ft_memdel((void **)&str);
		ft_memdel((void **)&line);
		return (0);
	}
	bol = ft_parse_material(env, line_mat);
	nb_random_mat++;
	*mat = get_material(env, str);
	ft_delete_line_array(line_mat, 0);
	ft_memdel((void **)&str);
	ft_memdel((void **)&line);
	return (bol);
}
