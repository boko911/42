/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_w3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 06:47:59 by nbuhler           #+#    #+#             */
/*   Updated: 2018/02/02 06:48:01 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void	connect_widgets_window_3(t_widgets *widgets)
{
	widgets->w_3 =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "w_3"));
	gtk_window_set_decorated(GTK_WINDOW(widgets->w_3), FALSE);
	widgets->l_pos_l =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_pos_l"));
	widgets->e_pos_x_l =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_pos_x_l"));
	widgets->e_pos_y_l =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_pos_y_l"));
	widgets->e_pos_z_l =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_pos_z_l"));
	widgets->l_color_l =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_color_l"));
	widgets->btn_color_l =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "btn_color_l"));
	widgets->l_intensity =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_intensity"));
	widgets->e_intensity =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_intensity"));
	widgets->btn_add_f =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "btn_add_f"));
	widgets->btn_add_l =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "btn_add_l"));
	widgets->l_add_s =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_add_s"));
}

void	hide_widget_txt(t_widgets *widgets)
{
	gtk_widget_hide(widgets->l_texture_id);
	gtk_widget_hide(widgets->e_textureid);
	gtk_widget_hide(widgets->l_texture_img);
	gtk_widget_hide(widgets->box_texture);
	gtk_widget_hide(widgets->l_elarge);
	gtk_widget_hide(widgets->e_elarge1);
	gtk_widget_hide(widgets->e_elarge2);
	gtk_widget_hide(widgets->l_begin);
	gtk_widget_hide(widgets->e_begin1);
	gtk_widget_hide(widgets->e_begin2);
	gtk_widget_hide(widgets->btn_add_txt);
}

void	show_widget_txt(t_widgets *widgets)
{
	gtk_widget_show(widgets->l_texture_id);
	gtk_widget_show(widgets->e_textureid);
	gtk_widget_show(widgets->l_texture_img);
	gtk_widget_show(widgets->box_texture);
	gtk_widget_show(widgets->l_elarge);
	gtk_widget_show(widgets->e_elarge1);
	gtk_widget_show(widgets->e_elarge2);
	gtk_widget_show(widgets->l_begin);
	gtk_widget_show(widgets->e_begin1);
	gtk_widget_show(widgets->e_begin2);
	gtk_widget_show(widgets->btn_add_txt);
}

void	connect_widgets(t_widgets *widgets)
{
	widgets->scene.count_light = 0;
	widgets->scene.count_shape = 0;
	widgets->scene.count_mat = 0;
	widgets->scene.count_img = 0;
	widgets->scene.count_texture = 0;
	connect_widgets_window_1(widgets);
	connect_widgets_window_2(widgets);
	connect_widgets_window_3(widgets);
	connect_widgets_window_4(widgets);
	connect_widgets_window_5(widgets);
}
