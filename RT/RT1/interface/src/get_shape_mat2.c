/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shape_mat2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:23:49 by nbuhler           #+#    #+#             */
/*   Updated: 2018/03/22 17:23:50 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void		get_text_thread(t_widgets *widgets)
{
	char	buff[4];

	widgets->scene.thread_text =
				g_ascii_dtostr(buff, 4, widgets->scene.thread);
}

void		get_input_mat(t_widgets *widgets)
{
	gtk_color_chooser_get_rgba(GTK_COLOR_CHOOSER(widgets->ch_color_s),
		&widgets->color3);
	get_color_mat(widgets);
	widgets->scene.ambiant = gtk_entry_get_text(GTK_ENTRY(widgets->e_ambiant));
	widgets->scene.diffuse = gtk_entry_get_text(GTK_ENTRY(widgets->e_diffuse));
	widgets->scene.specular =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_specular));
	widgets->scene.shininess =
	gtk_entry_get_text(GTK_ENTRY(widgets->e_shininess));
	widgets->scene.reflexion =
	gtk_entry_get_text(GTK_ENTRY(widgets->e_reflexion));
	widgets->scene.refraction1 =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_refraction1));
	widgets->scene.refraction2 =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_refraction2));
	widgets->scene.mat_name =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_name_mat));
	gtk_color_chooser_get_rgba(GTK_COLOR_CHOOSER(widgets->ch_color2_s),
		&widgets->color4);
	widgets->scene.perturbation = gtk_combo_box_text_get_active_text(
		GTK_COMBO_BOX_TEXT(widgets->box_perturbation));
	widgets->scene.texture_mat =
	gtk_combo_box_text_get_active_text(
		GTK_COMBO_BOX_TEXT(widgets->box_texture_mat));
	get_color2_mat(widgets);
}
