/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_mat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 07:01:40 by nbuhler           #+#    #+#             */
/*   Updated: 2018/02/02 07:01:42 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

char			*material_1_strjoin(t_widgets *widgets)
{
	char		*text_material;

	text_material = "--Material declarations\nmaterial id ";
	text_material = ft_strjoin(text_material, (char*)widgets->scene.mat_name);
	text_material = ft_strjoin(text_material,
		(char*)widgets->scene.text_color_shape);
	text_material = ft_strjoin(text_material,
		(char*)widgets->scene.text_color2_shape);
	text_material = ft_strjoin(text_material, " perturbation ");
	text_material = ft_strjoin(text_material,
		(char*)widgets->scene.perturbation);
	text_material = is_texture(text_material, widgets);
	text_material = ft_strjoin(text_material, " ambiant ");
	text_material = ft_strjoin(text_material,
		(char*)(widgets->scene.ambiant));
	text_material = ft_strjoin(text_material, " diffuse ");
	text_material = ft_strjoin(text_material,
		(char*)(widgets->scene.diffuse));
	text_material = ft_strjoin(text_material, " specular ");
	text_material = ft_strjoin(text_material,
		(char*)(widgets->scene.specular));
	text_material = ft_strjoin(text_material, " shininess ");
	text_material = ft_strjoin(text_material,
		(char*)(widgets->scene.shininess));
	return (text_material);
}

char			*material_2_strjoin(char *text_original, t_widgets *widgets)
{
	char		*text_material;

	text_material = ft_strjoin(text_original, " specular ");
	text_material = ft_strjoin(text_material,
		(char*)(widgets->scene.specular));
	text_material = ft_strjoin(text_material, " shininess ");
	text_material = ft_strjoin(text_material,
		(char*)(widgets->scene.shininess));
	text_material = ft_strjoin(text_material, " refle ");
	text_material = ft_strjoin(text_material,
		(char*)(widgets->scene.reflexion));
	text_material = ft_strjoin(text_material, " refraction ");
	text_material = ft_strjoin(text_material,
		(char*)(widgets->scene.refraction1));
	text_material = ft_strjoin(text_material, " n ");
	text_material = ft_strjoin(text_material,
		(char*)(widgets->scene.refraction2));
	text_material = ft_strjoin(text_material, "\n");
	return (text_material);
}

char			*material_2(t_widgets *widgets)
{
	char		*text_material;

	text_material = ft_strjoin(widgets->scene.text_material, "material id ");
	text_material = ft_strjoin(text_material,
		(char*)widgets->scene.mat_name);
	text_material = ft_strjoin(text_material,
		(char*)widgets->scene.text_color_shape);
	text_material = ft_strjoin(text_material,
		(char*)widgets->scene.text_color2_shape);
	text_material = ft_strjoin(text_material, " perturbation ");
	text_material = ft_strjoin(text_material,
		(char*)widgets->scene.perturbation);
	if (widgets->scene.with_texture == 0)
	{
		text_material = ft_strjoin(text_material, " texture ");
		text_material = ft_strjoin(text_material,
		(char*)widgets->scene.texture_mat);
	}
	text_material = ft_strjoin(text_material, " ambiant ");
	text_material = ft_strjoin(text_material,
		(char*)widgets->scene.ambiant);
	text_material = ft_strjoin(text_material, " diffuse ");
	text_material = ft_strjoin(text_material, (char*)widgets->scene.diffuse);
	text_material = material_2_strjoin(text_material, widgets);
	return (text_material);
}

char			*material_1(t_widgets *widgets)
{
	char		*text_material;

	text_material = material_1_strjoin(widgets);
	text_material = ft_strjoin(text_material, " refle ");
	text_material = ft_strjoin(text_material,
		(char*)(widgets->scene.reflexion));
	text_material = ft_strjoin(text_material, " refraction ");
	text_material = ft_strjoin(text_material,
		(char*)(widgets->scene.refraction1));
	text_material = ft_strjoin(text_material, " n ");
	text_material = ft_strjoin(text_material,
		(char*)(widgets->scene.refraction2));
	text_material = ft_strjoin(text_material, "\n");
	return (text_material);
}

char			*mult_strjoin(t_widgets *widgets)
{
	char	*text_material;

	if (widgets->scene.count_mat == 1)
		text_material = material_1(widgets);
	if (widgets->scene.count_mat >= 2)
		text_material = material_2(widgets);
	return (text_material);
}
