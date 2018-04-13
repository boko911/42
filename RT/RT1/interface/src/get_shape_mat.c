/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shape_mat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 06:58:21 by nbuhler           #+#    #+#             */
/*   Updated: 2018/02/02 06:58:26 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void		hide_widget_shape(t_widgets *widgets)
{
	gtk_widget_hide(widgets->l_pos_s);
	gtk_widget_hide(widgets->e_pos_x_s);
	gtk_widget_hide(widgets->e_pos_y_s);
	gtk_widget_hide(widgets->e_pos_z_s);
	gtk_widget_hide(widgets->l_rot_s);
	gtk_widget_hide(widgets->e_rot_x_s);
	gtk_widget_hide(widgets->e_rot_y_s);
	gtk_widget_hide(widgets->e_rot_z_s);
	gtk_widget_hide(widgets->l_radius_s);
	gtk_widget_hide(widgets->e_radius_s);
	gtk_widget_hide(widgets->l_color_s);
	gtk_widget_hide(widgets->ch_color_s);
	gtk_widget_hide(widgets->l_ambiant);
	gtk_widget_hide(widgets->e_ambiant);
	gtk_widget_hide(widgets->l_diffuse);
	gtk_widget_hide(widgets->e_diffuse);
	gtk_widget_hide(widgets->l_specular);
	gtk_widget_hide(widgets->e_specular);
	gtk_widget_hide(widgets->l_shininess);
	gtk_widget_hide(widgets->e_shininess);
	gtk_widget_hide(widgets->l_reflexion);
	gtk_widget_hide(widgets->e_reflexion);
	gtk_widget_hide(widgets->l_refraction);
	gtk_widget_hide(widgets->e_refraction1);
	gtk_widget_hide(widgets->e_refraction2);
}

void		show_widget_shape(t_widgets *widgets)
{
	gtk_widget_show(widgets->l_pos_s);
	gtk_widget_show(widgets->e_pos_x_s);
	gtk_widget_show(widgets->e_pos_y_s);
	gtk_widget_show(widgets->e_pos_z_s);
	gtk_widget_show(widgets->l_rot_s);
	gtk_widget_show(widgets->e_rot_x_s);
	gtk_widget_show(widgets->e_rot_y_s);
	gtk_widget_show(widgets->e_rot_z_s);
	gtk_widget_show(widgets->l_radius_s);
	gtk_widget_show(widgets->e_radius_s);
	gtk_widget_show(widgets->l_color_s);
	gtk_widget_show(widgets->ch_color_s);
	gtk_widget_show(widgets->l_ambiant);
	gtk_widget_show(widgets->e_ambiant);
	gtk_widget_show(widgets->l_diffuse);
	gtk_widget_show(widgets->e_diffuse);
	gtk_widget_show(widgets->l_specular);
	gtk_widget_show(widgets->e_specular);
	gtk_widget_show(widgets->l_shininess);
	gtk_widget_show(widgets->e_shininess);
	gtk_widget_show(widgets->l_reflexion);
	gtk_widget_show(widgets->e_reflexion);
	gtk_widget_show(widgets->l_refraction);
	gtk_widget_show(widgets->e_refraction1);
	gtk_widget_show(widgets->e_refraction2);
}

void		get_input_shape(t_widgets *widgets)
{
	widgets->scene.shape =
	gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widgets->box_s_s));
	widgets->scene.material =
	gtk_combo_box_text_get_active_text(
		GTK_COMBO_BOX_TEXT(widgets->box_material));
	widgets->scene.pos_x_shape =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_pos_x_s));
	widgets->scene.pos_y_shape =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_pos_y_s));
	widgets->scene.pos_z_shape =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_pos_z_s));
	widgets->scene.rot_x_shape =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_rot_x_s));
	widgets->scene.rot_y_shape =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_rot_y_s));
	widgets->scene.rot_z_shape =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_rot_z_s));
	widgets->scene.radius =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_radius_s));
}

void		get_input_image(t_widgets *widgets)
{
	widgets->scene.path_img =
		gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(widgets->ch_image));
	widgets->scene.img_id =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_imgid));
}

void		get_input_texture(t_widgets *widgets)
{
	widgets->scene.texture_id =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_textureid));
	widgets->scene.texture =
		gtk_combo_box_text_get_active_text(
			GTK_COMBO_BOX_TEXT(widgets->box_texture));
	widgets->scene.elarge1 =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_elarge1));
	widgets->scene.elarge2 =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_elarge2));
	widgets->scene.begin1 =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_begin1));
	widgets->scene.begin2 =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_begin2));
}
