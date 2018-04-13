/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 06:33:44 by nbuhler           #+#    #+#             */
/*   Updated: 2018/02/02 06:33:46 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

char		*set_text2(t_widgets *widgets)
{
	char	*text;

	text = g_strdup_printf("--Camera declaration\n"\
		"camera position %s %s %s rotation %s %s %s%s"\
		"screen %s %s fov %s antialiasing %s\n",
		widgets->scene.pos_x_cam,
		widgets->scene.pos_y_cam,
		widgets->scene.pos_z_cam,
		widgets->scene.rot_x_cam,
		widgets->scene.rot_y_cam,
		widgets->scene.rot_z_cam,
		" ",
		widgets->scene.width,
		widgets->scene.height,
		widgets->scene.fov,
		widgets->scene.antialiasing);
	return (text);
}

gchar		*get_text1(t_widgets *widgets)
{
	gchar	*text;

	text = g_strdup_printf("--Scene declaration, must be the first thing\n"\
		"scene ambiant %s %s %s%sambiant_base_impact %s%s"\
		"ambiant_coef_impact %s max_reflexion %s\n\n",
		widgets->scene.scene_ambiant,
		widgets->scene.scene_ambiant,
		widgets->scene.scene_ambiant,
		widgets->scene.text_background,
		widgets->scene.base_impact_ambiant,
		" ",
		widgets->scene.coef_impact_ambiant,
		widgets->scene.max_reflexion);
	return (text);
}

gchar		*get_text2(t_widgets *widgets)
{
	gchar	*text;

	text = g_strdup_printf("--Scene declaration, must be the first thing\n"\
		"scene ambiant %s %s %s%sambiant_base_impact %s%s"\
		"ambiant_coef_impact %s max_reflexion %s filter %s\n\n",
		widgets->scene.scene_ambiant,
		widgets->scene.scene_ambiant,
		widgets->scene.scene_ambiant,
		widgets->scene.text_background,
		widgets->scene.base_impact_ambiant,
		" ",
		widgets->scene.coef_impact_ambiant,
		widgets->scene.max_reflexion,
		widgets->scene.filtre);
	return (text);
}

void		save_text_cam(t_widgets *widgets)
{
	gchar	*text;
	gchar	*text2;

	if (g_strcmp0(widgets->scene.filtre, "Sans filtre") == 0)
		text = get_text1(widgets);
	else
		text = get_text2(widgets);
	text2 = set_text2(widgets);
	widgets->scene.text_cam = ft_strjoin((char*)text, (char*)text2);
	g_free(text);
	g_free(text2);
}
