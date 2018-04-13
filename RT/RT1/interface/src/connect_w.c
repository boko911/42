/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_w.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 06:42:27 by nbuhler           #+#    #+#             */
/*   Updated: 2018/02/02 06:42:33 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void	connect_widgets_window_1(t_widgets *widgets)
{
	widgets->btn_ch_file =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "btn_ch_file"));
	widgets->btn_quit =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "btn_quit"));
	widgets->btn_cre_file =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "btn_cre_file"));
	widgets->btn_exe_rt =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "btn_exe_rt"));
	widgets->btn_thread =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "btn_thread"));
	widgets->btn_bmp =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "btn_bmp"));
	widgets->btn_sound =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "btn_sound"));
	widgets->adjustement =
		gtk_spin_button_get_adjustment(GTK_SPIN_BUTTON(widgets->btn_thread));
	widgets->box_option =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "box_option"));
	gtk_widget_hide(widgets->box_option);
	gtk_adjustment_configure(widgets->adjustement, 0, 1, 21, 1, 1, 1);
	gtk_widget_hide(widgets->btn_exe_rt);
}

void	connect_widgets_window_2_1(t_widgets *widgets)
{
	widgets->w_2 =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "w_2"));
	widgets->l_reso =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_reso"));
	widgets->e_width =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_width"));
	widgets->e_height =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_height"));
	widgets->l_pos =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_pos"));
	widgets->e_pos_x_c =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_pos_x_c"));
	widgets->e_pos_y_c =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_pos_y_c"));
	widgets->e_pos_z_c =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_pos_z_c"));
	widgets->l_rot =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_rot"));
	widgets->e_rot_x_c =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_rot_x_c"));
	widgets->e_rot_y_c =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_rot_y_c"));
	widgets->e_rot_z_c =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_rot_z_c"));
}

void	connect_widgets_window_2_2(t_widgets *widgets)
{
	widgets->l_fov =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_fov"));
	widgets->e_fov =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_fov"));
	widgets->l_anti =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_anti"));
	widgets->e_anti =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_anti"));
	widgets->l_back =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_back"));
	widgets->back_color_c =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "back_color_c"));
	widgets->btn_add_c =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "btn_add_c"));
	widgets->btn_add_sl =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "btn_add_sl"));
	widgets->box_filtre =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "box_filtre"));
	gtk_widget_hide(widgets->btn_add_sl);
}

void	connect_widgets_window_2_3(t_widgets *widgets)
{
	widgets->l_s_ambiant =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_s_ambiant"));
	widgets->e_s_ambiant =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_s_ambiant"));
	widgets->l_b_ambiant =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_b_ambiant"));
	widgets->e_b_ambiant =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_b_ambiant"));
	widgets->l_c_ambiant =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_c_ambiant"));
	widgets->e_c_ambiant =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_c_ambiant"));
	widgets->l_max_r =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_max_r"));
	widgets->e_max_r =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_max_r"));
	gtk_window_set_decorated(GTK_WINDOW(widgets->w_2), FALSE);
}

void	connect_widgets_window_2(t_widgets *widgets)
{
	connect_widgets_window_2_1(widgets);
	connect_widgets_window_2_2(widgets);
	connect_widgets_window_2_3(widgets);
}
