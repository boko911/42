/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_shape2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 07:02:45 by nbuhler           #+#    #+#             */
/*   Updated: 2018/02/02 07:02:48 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

char			*shape_1_e_cone(char *text_original, t_widgets *widgets)
{
	char		*text_shape;

	text_shape = text_original;
	text_shape = ft_strjoin(text_shape, " angle ");
	text_shape = ft_strjoin(text_shape, (char*)(widgets->scene.radius));
	text_shape = ft_strjoin(text_shape, " material ");
	text_shape = ft_strjoin(text_shape, (char*)widgets->scene.material);
	text_shape = ft_strjoin(text_shape, "\n");
	return (text_shape);
}

char			*shape_1_e_radius(char *text_original, t_widgets *widgets)
{
	char		*text_shape;

	text_shape = text_original;
	text_shape = ft_strjoin(text_shape, " radius ");
	text_shape = ft_strjoin(text_shape,
		(char*)(widgets->scene.radius));
	text_shape = ft_strjoin(text_shape, " material ");
	text_shape = ft_strjoin(text_shape,
		(char*)widgets->scene.material);
	text_shape = ft_strjoin(text_shape, "\n");
	return (text_shape);
}

char			*shape_1_e(char *text_original, t_widgets *widgets)
{
	char		*text_shape;

	text_shape = text_original;
	if (g_strcmp0(widgets->scene.shape, "plane") == 0)
	{
		text_shape = ft_strjoin(text_shape, " material ");
		text_shape = ft_strjoin(text_shape,
			(char*)widgets->scene.material);
		text_shape = ft_strjoin(text_shape, "\n");
	}
	else
	{
		if (g_strcmp0(widgets->scene.shape, "cone") == 0)
			text_shape = shape_1_e_cone(text_shape, widgets);
		else
			text_shape = shape_1_e_radius(text_shape, widgets);
	}
	return (text_shape);
}

char			*shape_1(char *text_original, t_widgets *widgets)
{
	char		*text_shape;

	text_shape = text_original;
	text_shape = ft_strjoin(text_shape, " position ");
	text_shape = ft_strjoin(text_shape,
		(char*)(widgets->scene.pos_x_shape));
	text_shape = ft_strjoin(text_shape, " ");
	text_shape = ft_strjoin(text_shape,
		(char*)(widgets->scene.pos_y_shape));
	text_shape = ft_strjoin(text_shape, " ");
	text_shape = ft_strjoin(text_shape,
		(char*)(widgets->scene.pos_z_shape));
	text_shape = ft_strjoin(text_shape, " rotation ");
	text_shape = ft_strjoin(text_shape,
		(char*)(widgets->scene.rot_x_shape));
	text_shape = ft_strjoin(text_shape, " ");
	text_shape = ft_strjoin(text_shape,
		(char*)(widgets->scene.rot_y_shape));
	text_shape = ft_strjoin(text_shape, " ");
	text_shape = ft_strjoin(text_shape,
		(char*)(widgets->scene.rot_z_shape));
	text_shape = shape_1_e(text_shape, widgets);
	return (text_shape);
}
