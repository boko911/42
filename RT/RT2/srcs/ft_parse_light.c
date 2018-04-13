/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 15:21:39 by agrosset          #+#    #+#             */
/*   Updated: 2018/03/29 17:57:40 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	ft_parse_light_2(char **line, int *i, t_light *light)
{
	if (!ft_strcmp(line[i[0]], "position"))
	{
		if (!parse_vector3(line, i, &light->pos))
			return (return_print("Error parsing light position", 0));
		else
			i[1] |= 1;
	}
	else if (!ft_strcmp(line[i[0]], "color"))
	{
		if (!parse_color(line, i, &light->color))
			return (return_print("Error parsing light color", 0));
		else
			i[1] |= 2;
	}
	else if (!ft_strcmp(line[i[0]], "power"))
	{
		if (!parse_double(line, i, &light->power, 2))
			return (return_print("Error parsing light power", 0));
		else
			i[1] |= 4;
	}
	return (1);
}

int			ft_alloc_light(t_light **light, t_list **lst)
{
	if ((*light = (t_light *)ft_memalloc(sizeof(t_light))) == NULL)
		return (return_print("malloc error", 0));
	if ((*lst = ft_lstnewfrom(*light, sizeof(*light))) == NULL)
	{
		free(light);
		return (return_print("malloc error", 0));
	}
	return (1);
}

int			ft_parse_light(t_env *env, char **line)
{
	int			i[2];
	t_light		*light;
	t_list		*lst;

	if (env->scene == NULL)
		return (return_print("Error, a scene must be declared first", 0));
	if (!ft_alloc_light(&light, &lst))
		return (0);
	i[0] = 0;
	i[1] = 0;
	while (line[++i[0]])
		if (ft_parse_light_2(line, i, light) == 0)
		{
			free(light);
			free(lst);
			return (0);
		}
	if (env->scene->lights == NULL)
		env->scene->lights = lst;
	else
		ft_lstadd(&(env->scene->lights), lst);
	return (i[1] == 7 ? 1 : return_print("error light incomplete", 0));
}
