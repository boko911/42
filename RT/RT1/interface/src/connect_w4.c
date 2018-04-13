/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_w4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:33:55 by nbuhler           #+#    #+#             */
/*   Updated: 2018/03/22 17:33:59 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void	connect_widgets_window_5_1(t_widgets *widgets)
{
	widgets->l_texture_id =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_texture_id"));
	widgets->e_textureid =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_textureid"));
	widgets->l_texture_img =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_texture_img"));
	widgets->box_texture =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "box_texture"));
	widgets->l_elarge =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_elarge"));
	widgets->e_elarge1 =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_elarge1"));
	widgets->e_elarge2 =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_elarge2"));
	widgets->l_begin =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_begin"));
	widgets->e_begin1 =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_begin1"));
	widgets->e_begin2 =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_begin2"));
	widgets->btn_add_txt =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "btn_add_txt"));
	hide_widget_txt(widgets);
}

void	connect_widgets_window_5(t_widgets *widgets)
{
	widgets->g_cre_txt =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "g_cre_txt"));
	gtk_widget_hide(widgets->g_cre_txt);
	widgets->l_load_image =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_load_image"));
	widgets->ch_image =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "ch_image"));
	widgets->l_cre_img =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_cre_img"));
	widgets->l_imgid =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "l_imgid"));
	widgets->e_imgid =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "e_imgid"));
	widgets->btn_add_img =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "btn_add_img"));
	connect_widgets_window_5_1(widgets);
}
