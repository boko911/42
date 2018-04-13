/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 00:06:10 by nbuhler           #+#    #+#             */
/*   Updated: 2018/02/01 00:06:13 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void			get_color_light(t_widgets *widgets)
{
	gchar		test2[5];
	gchar		test3[5];
	gchar		test4[5];

	widgets->scene.color_r_light =
		g_ascii_dtostr(test2, 5, widgets->color2.red);
	widgets->scene.color_g_light =
		g_ascii_dtostr(test3, 5, widgets->color2.green);
	widgets->scene.color_b_light =
		g_ascii_dtostr(test4, 5, widgets->color2.blue);
	widgets->scene.text_color_light =
		g_strdup_printf(" color %s %s %s ",
		widgets->scene.color_r_light,
		widgets->scene.color_g_light,
		widgets->scene.color_b_light);
}

void			get_input_light(t_widgets *widgets)
{
	widgets->scene.pos_x_light =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_pos_x_l));
	widgets->scene.pos_y_light =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_pos_y_l));
	widgets->scene.pos_z_light =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_pos_z_l));
	gtk_color_chooser_get_rgba(GTK_COLOR_CHOOSER(widgets->btn_color_l),
		&widgets->color2);
	get_color_light(widgets);
	widgets->scene.intensity =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_intensity));
}

char			*light_1(t_widgets *widgets)
{
	char		*text_light;

	text_light = "--Lights declaration\nlight ";
	text_light = ft_strjoin(text_light, "position ");
	text_light = ft_strjoin(text_light,
		(char*)(widgets->scene.pos_x_light));
	text_light = ft_strjoin(text_light, " ");
	text_light = ft_strjoin(text_light,
		(char*)(widgets->scene.pos_y_light));
	text_light = ft_strjoin(text_light, " ");
	text_light = ft_strjoin(text_light,
		(char*)(widgets->scene.pos_z_light));
	text_light = ft_strjoin(text_light,
		(char*)(widgets->scene.text_color_light));
	text_light = ft_strjoin(text_light, "power ");
	text_light = ft_strjoin(text_light,
		(char*)(widgets->scene.intensity));
	text_light = ft_strjoin(text_light, "\n");
	return (text_light);
}

char			*save_text_light(t_widgets *widgets)
{
	char	*text_light;

	if (widgets->scene.count_light == 1)
		text_light = light_1(widgets);
	if (widgets->scene.count_light >= 2)
	{
		text_light = ft_strjoin(widgets->scene.text_light, "light ");
		text_light = ft_strjoin(text_light, "position ");
		text_light = ft_strjoin(text_light,
			(char*)(widgets->scene.pos_x_light));
		text_light = ft_strjoin(text_light, " ");
		text_light = ft_strjoin(text_light,
			(char*)(widgets->scene.pos_y_light));
		text_light = ft_strjoin(text_light, " ");
		text_light = ft_strjoin(text_light,
			(char*)(widgets->scene.pos_z_light));
		text_light = ft_strjoin(text_light,
			(char*)(widgets->scene.text_color_light));
		text_light = ft_strjoin(text_light, "power ");
		text_light = ft_strjoin(text_light,
			(char*)(widgets->scene.intensity));
		text_light = ft_strjoin(text_light, "\n");
	}
	return (text_light);
}
