/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 23:05:42 by nbuhler           #+#    #+#             */
/*   Updated: 2018/01/31 23:05:46 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void			get_info_exec(t_widgets *widgets)
{
	widgets->scene.path =
		gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(widgets->btn_ch_file));
	widgets->scene.thread =
		gtk_spin_button_get_value(GTK_SPIN_BUTTON(widgets->btn_thread));
	if (gtk_switch_get_active(GTK_SWITCH(widgets->btn_bmp)) == FALSE)
		widgets->scene.bmp = 1;
	else
		widgets->scene.bmp = 0;
	if (gtk_switch_get_active(GTK_SWITCH(widgets->btn_sound)) == FALSE)
		widgets->scene.sound = 1;
	else
		widgets->scene.sound = 0;
}

int				main(int argc, char *argv[])
{
	t_widgets	*widgets;

	gtk_init(&argc, &argv);
	widgets = g_slice_new(t_widgets);
	widgets->builder = gtk_builder_new();
	gtk_builder_add_from_file(widgets->builder, "interface/real.glade", NULL);
	widgets->w_1 =
		GTK_WIDGET(gtk_builder_get_object(widgets->builder, "w_1"));
	gtk_window_set_decorated(GTK_WINDOW(widgets->w_1), FALSE);
	connect_widgets(widgets);
	gtk_builder_connect_signals(widgets->builder, widgets);
	gtk_widget_show(widgets->w_1);
	gtk_main();
	g_object_unref(widgets->builder);
	g_slice_free(t_widgets, widgets);
	return (0);
}
