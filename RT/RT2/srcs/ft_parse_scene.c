/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:46:26 by agrosset          #+#    #+#             */
/*   Updated: 2018/02/14 15:11:20 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		ft_parse_scene3(char **line, int *i, t_scene *scene)
{
	if (!ft_strcmp(line[*i], "max_reflexion"))
	{
		if (!parse_int(line, i, &scene->max_ref))
			return (return_print("Error parsing reflexion count", 0));
		if (scene->max_ref < 0)
			return (return_print("Error max_reflexion must be > 0", 0));
	}
	if (!ft_strcmp(line[*i], "filter"))
	{
		if (!parse_filter(line, i, &scene->filter))
			return (return_print("Error parsing filter", 0));
	}
	if (!ft_strcmp(line[*i], "blind"))
	{
		if (!parse_int(line, i, &scene->blind))
			return (return_print("Error parsing blind", 0));
	}
	return (1);
}

static int		ft_parse_scene2(char **line, int *i, t_scene *scene,
	int *valid)
{
	if (!ft_strcmp(line[*i], "ambiant"))
	{
		if (!parse_color(line, i, &scene->i_ambiant))
			return (return_print("Error parsing scene ambiant light", 0));
		else
			*valid |= 1;
	}
	else if (!ft_strcmp(line[*i], "background"))
	{
		if (!parse_color(line, i, &scene->bgcolor))
			return (return_print("Error parsing scene background color", 0));
	}
	else if (!ft_strcmp(line[*i], "ambiant_base_impact"))
	{
		if (!parse_double(line, i, &scene->ambbaseimpact, 3))
			return (return_print("Error parsing ambiant base impact", 0));
	}
	else if (!ft_strcmp(line[*i], "ambiant_coef_impact"))
	{
		if (!parse_double(line, i, &scene->ambcoefimpact, 3))
			return (return_print("Error parsing ambiant coef impact", 0));
	}
	return (ft_parse_scene3(line, i, scene));
}

int				ft_parse_scene(t_env *env, char **line)
{
	t_scene	*scene;
	int		valid;
	int		i;

	if (env->scene != NULL)
	{
		scene = env->scene;
		ft_bzero(scene, sizeof(t_scene));
	}
	else if ((scene = (t_scene *)ft_memalloc(sizeof(t_scene))) == NULL)
		return (return_print("malloc error", 0));
	i = 0;
	valid = 0;
	scene->filter = 0;
	scene->max_ref = 5;
	scene->blind = 0;
	while (line[++i])
		if (ft_parse_scene2(line, &i, scene, &valid) == 0)
			return (0);
	if (valid != 1)
		free(scene);
	else
		env->scene = scene;
	return (valid == 1 ? 1 : return_print("error scene imcomplete", 0));
}
