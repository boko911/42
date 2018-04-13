/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_w2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 06:43:38 by nbuhler           #+#    #+#             */
/*   Updated: 2018/02/02 06:43:40 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void	connect_widgets_window_4_1(t_widgets *widgets)
{
	widgets->w_4 =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "w_4"));
	gtk_window_set_decorated(GTK_WINDOW(widgets->w_4), FALSE);
	widgets->l_shape =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_shape"));
	widgets->box_s_s =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "box_s_s"));
	widgets->l_pos_s =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_pos_s"));
	widgets->e_pos_x_s =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_pos_x_s"));
	widgets->e_pos_y_s =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_pos_y_s"));
	widgets->e_pos_z_s =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_pos_z_s"));
	widgets->l_rot_s =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_rot_s"));
	widgets->e_rot_x_s =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_rot_x_s"));
	widgets->e_rot_y_s =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_rot_y_s"));
	widgets->e_rot_z_s =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_rot_z_s"));
}

void	connect_widgets_window_4_2(t_widgets *widgets)
{
	widgets->l_radius_s =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_radius_s"));
	widgets->e_radius_s =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_radius_s"));
	widgets->l_color_s =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_color_s"));
	widgets->ch_color_s =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "ch_color_s"));
	widgets->l_ambiant =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_ambiant"));
	widgets->e_ambiant =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_ambiant"));
	widgets->l_diffuse =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_diffuse"));
	widgets->e_diffuse =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_diffuse"));
	widgets->l_specular =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_specular"));
	widgets->e_specular =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_specular"));
	widgets->l_shininess =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_shininess"));
	widgets->e_shininess =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_shininess"));
}

void	connect_widgets_window_4_3(t_widgets *widgets)
{
	widgets->l_reflexion =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_reflexion"));
	widgets->e_reflexion =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_reflexion"));
	widgets->l_refraction =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_refraction"));
	widgets->e_refraction1 =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_refraction1"));
	widgets->e_refraction2 =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_refraction2"));
	widgets->l_save =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_save"));
	widgets->e_filename =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_filename"));
	widgets->btn_add_s =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "btn_add_s"));
	widgets->btn_save_file =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "btn_save_file"));
	widgets->g_save_file =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "g_save_file"));
	gtk_widget_hide(widgets->g_save_file);
	widgets->ch_color2_s =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "ch_color2_s"));
	widgets->box_perturbation =
	GTK_WIDGET(gtk_builder_get_object(widgets->builder, "box_perturbation"));
}

void	connect_widgets_window_4_4(t_widgets *widgets)
{
	widgets->box_texture_mat =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "box_texture_mat"));
	widgets->e_name_mat =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_name_mat"));
	widgets->btn_cre_m =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "btn_cre_m"));
	widgets->btn_ok_mat =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "btn_ok_mat"));
	widgets->box_material =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "box_material"));
	widgets->g_cre_mat =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "g_cre_mat"));
	widgets->l_add_f =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_add_f"));
	widgets->l_cre_mat =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_crea_m"));
	widgets->l_save =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_save"));
	widgets->l_name_m =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_name_m"));
	gtk_widget_hide(widgets->g_cre_mat);
}

void	connect_widgets_window_4(t_widgets *widgets)
{
	connect_widgets_window_4_1(widgets);
	connect_widgets_window_4_2(widgets);
	connect_widgets_window_4_3(widgets);
	connect_widgets_window_4_4(widgets);
}
