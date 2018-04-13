/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_material.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 14:15:07 by agrosset          #+#    #+#             */
/*   Updated: 2018/03/29 17:54:41 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	ft_parse_material_4(char **line, int *i, t_material *mat)
{
	if (!ft_strcmp(line[i[0]], "texture"))
	{
		if (line[i[0] + 1] == NULL || !(ft_strlen(line[i[0] + 1]) > 0))
			return (return_print("Error parsing material id", 0));
		else if (!(mat->texture = ft_strdup(line[++i[0]])))
			return (return_print("malloc error", 0));
	}
	return (1);
}

static int	ft_parse_material_3(char **line, int *i, t_material *mat)
{
	if (!ft_strcmp(line[i[0]], "diffuse")
		&& !parse_double(line, i, &mat->k_diffuse, 5))
		return (return_print("Error parsing material diffuse", 0));
	else if (!ft_strcmp(line[i[0]], "shininess")
		&& !parse_shine(line, i, &mat->shine, 2))
		return (return_print("Error parsing material shininess", 0));
	else if (!ft_strcmp(line[i[0]], "reflexion")
		&& !parse_double(line, i, &mat->refle, 5))
		return (return_print("Error parsing material reflexion", 0));
	else if (!ft_strcmp(line[i[0]], "n")
		&& !parse_n(line, i, &mat->n, 5))
		return (return_print("Error parsing material n", 0));
	else if (!ft_strcmp(line[i[0]], "refraction")
		&& !parse_n(line, i, &mat->refra, 5))
		return (return_print("Error parsing material refraction", 0));
	else if (!ft_strcmp(line[i[0]], "perturbation")
		&& !ft_parse_perturbation(line, i, &mat->ft_perturbation))
		return (return_print("Error parsing material perturbation", 0));
	return (ft_parse_material_4(line, i, mat));
}

static int	ft_parse_material_2(char **line, int *i, t_material *mat)
{
	if (!ft_strcmp(line[i[0]], "id"))
	{
		if (line[i[0] + 1] == NULL || !(ft_strlen(line[i[0] + 1]) > 0))
			return (return_print("Error parsing material id", 0));
		else
		{
			if (!(mat->name = ft_strdup(line[++i[0]])))
				return (return_print("malloc error", 0));
			i[1] |= 1;
		}
	}
	else if (!ft_strcmp(line[i[0]], "color1")
		&& !parse_color(line, i, &mat->color1))
		return (return_print("Error parsing material color1", 0));
	else if (!ft_strcmp(line[i[0]], "color2")
		&& !parse_color(line, i, &mat->color2))
		return (return_print("Error parsing material color2", 0));
	else if (!ft_strcmp(line[i[0]], "ambiant")
		&& !parse_double(line, i, &mat->k_ambiant, 3))
		return (return_print("Error parsing material ambiant", 0));
	else if (!ft_strcmp(line[i[0]], "specular")
		&& !parse_double(line, i, &mat->k_spec, 3))
		return (return_print("Error parsing material specular", 0));
	return (ft_parse_material_3(line, i, mat));
}

static int	ft_delete_pre_mat(t_list **lst, t_material **mat)
{
	free(*lst);
	free((*mat)->name);
	free((*mat)->texture);
	free(*mat);
	return (0);
}

int			ft_parse_material(t_env *env, char **line)
{
	int			i[2];
	t_material	*mat;
	t_list		*lst;

	if (env->scene == NULL)
		return (return_print("Error, a scene must be declared first", 0));
	if ((mat = (t_material *)ft_memalloc(sizeof(t_material))) == NULL)
		return (return_print("malloc error", 0));
	if ((lst = ft_lstnewfrom(mat, sizeof(*mat))) == NULL)
	{
		free(mat);
		return (return_print("malloc error", 0));
	}
	ft_init_material(mat);
	i[0] = 0;
	i[1] = 0;
	while (line[++i[0]])
		if (ft_parse_material_2(line, i, mat) == 0)
			return (ft_delete_pre_mat(&lst, &mat));
	if (env->scene->materials == NULL)
		env->scene->materials = lst;
	else
		ft_lstadd(&(env->scene->materials), lst);
	return (i[1] == 1 ? 1 : return_print("error material imcomplete", 0));
}
