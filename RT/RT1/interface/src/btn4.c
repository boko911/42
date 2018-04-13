/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:45:05 by nbuhler           #+#    #+#             */
/*   Updated: 2018/03/22 16:45:06 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void		on_btn_img_clicked(GtkWidget *w, t_widgets *widgets)
{
	widgets->trash = w;
	get_input_image(widgets);
	if (check_input_image(widgets) == 0)
	{
		widgets->scene.count_img++;
		gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(widgets->box_texture),
			10,
			NULL, widgets->scene.img_id);
		show_widget_txt(widgets);
		widgets->scene.text_image = mult_strjoin_image(widgets);
		gtk_label_set_text(GTK_LABEL(widgets->l_cre_img),
			g_strdup_printf("Image %s Ajoutée!!!", widgets->scene.img_id));
		reinitialize_entries_img(widgets);
	}
	else
		gtk_label_set_text(GTK_LABEL(widgets->l_cre_img), NULL);
}

void		on_btn_txt_clicked(GtkWidget *w, t_widgets *widgets)
{
	widgets->trash = w;
	get_input_texture(widgets);
	if (check_input_texture(widgets) == 0)
	{
		widgets->scene.count_texture++;
		gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(widgets->box_texture_mat),
			10,
			NULL, widgets->scene.texture_id);
		widgets->scene.text_texture = mult_strjoin_texture(widgets);
	}
}

void		set_empty_char(t_widgets *widgets)
{
	if (widgets->scene.text_cam == NULL)
		widgets->scene.text_cam = " ";
	if (widgets->scene.text_image == NULL)
		widgets->scene.text_image = " ";
	if (widgets->scene.text_light == NULL)
		widgets->scene.text_light = " ";
	if (widgets->scene.text_texture == NULL)
		widgets->scene.text_texture = " ";
	if (widgets->scene.text_material == NULL)
		widgets->scene.text_material = " ";
	if (widgets->scene.text_shape == NULL)
		widgets->scene.text_shape = " ";
}
