/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 06:15:52 by nbuhler           #+#    #+#             */
/*   Updated: 2018/04/02 16:03:14 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void			on_window_close(GtkWidget *w)
{
	gtk_widget_hide(w);
}

void			on_window_main_destroy(void)
{
	gtk_main_quit();
}

void			on_create_scene_clicked(GtkWidget *w, t_widgets *widgets)
{
	widgets->trash = w;
	widgets->scene.text_cam = " ";
	widgets->scene.text_material = " ";
	widgets->scene.text_light = " ";
	widgets->scene.text_shape = " ";
	widgets->scene.text_color_light = " ";
	reinitialize_entries_cam(widgets);
	gtk_widget_show(widgets->w_2);
}

void			on_exec_rt_clicked(GtkWidget *w, t_widgets *widgets)
{
	char		*commandline;
	char		buff[4];

	widgets->trash = w;
	get_info_exec(widgets);
	if (widgets->scene.path != NULL)
	{
		commandline = "./rt ";
		if (widgets->scene.bmp == 0)
			commandline = ft_strjoin(commandline, "-o rt1.bmp ");
		if (widgets->scene.sound == 0)
			commandline = ft_strjoin(commandline, "-p ");
		if (widgets->scene.thread > 0)
		{
			widgets->scene.thread_text =
				g_ascii_dtostr(buff, 4, widgets->scene.thread);
			commandline = ft_strjoin(commandline, "-t ");
			commandline =
				ft_strjoin(commandline, (char*)widgets->scene.thread_text);
			commandline = ft_strjoin(commandline, " ");
		}
		commandline = ft_strjoin(commandline, (char*)widgets->scene.path);
		system(commandline);
		g_free(commandline);
	}
}

void			file_selected(GtkWidget *w, t_widgets *widgets)
{
	gchar		*path;

	widgets->trash = w;
	path =
	gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(widgets->btn_ch_file));
	if (path != NULL)
	{
		gtk_widget_show(widgets->btn_exe_rt);
		gtk_widget_show(widgets->box_option);
	}
	g_free(path);
}
