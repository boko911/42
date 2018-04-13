/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 06:22:46 by nbuhler           #+#    #+#             */
/*   Updated: 2018/02/02 06:22:47 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void			on_shapebox_changed(GtkWidget *w, t_widgets *widgets)
{
	const gchar	*shape;

	widgets->trash = w;
	shape = gtk_combo_box_text_get_active_text(
		GTK_COMBO_BOX_TEXT(widgets->box_s_s));
	if (g_strcmp0(shape, "$") == 0)
		hide_widget_shape(widgets);
	else
		show_widget_shape(widgets);
	if (g_strcmp0(shape, "cone") == 0)
		gtk_label_set_text(GTK_LABEL(widgets->l_radius_s),
			" Angle :");
	else if (g_strcmp0(shape, "cylinder") == 0 &&
		g_strcmp0(shape, "sphere") == 0)
		gtk_label_set_text(GTK_LABEL(widgets->l_radius_s),
			" Radius :");
	if (g_strcmp0(shape, "plane") == 0)
	{
		gtk_widget_hide(widgets->l_radius_s);
		gtk_widget_hide(widgets->e_radius_s);
		gtk_label_set_text(GTK_LABEL(widgets->l_radius_s), NULL);
	}
}

void			on_button_add_shape_clicked(GtkWidget *w, t_widgets *widgets)
{
	widgets->trash = w;
	get_input_shape(widgets);
	if (check_input_shape(widgets) == 0)
	{
		widgets->scene.count_shape++;
		get_shape(widgets);
		gtk_label_set_text(GTK_LABEL(widgets->l_add_f),
			g_strdup_printf("Forme %d Ajoutée!!!",
				widgets->scene.count_shape));
		reinitialize_entries(widgets);
		reinitialize_entries_mat(widgets);
	}
	else
		gtk_label_set_text(GTK_LABEL(widgets->l_add_f), NULL);
	if (widgets->scene.count_shape >= 1)
		gtk_widget_show(widgets->g_save_file);
	if (widgets->scene.text_light == NULL)
		widgets->scene.text_light =
			"--Lights declaration\n";
}

void			on_button_save_file_clicked(GtkWidget *w, t_widgets *widgets)
{
	gchar		*text;
	const char	*command;

	widgets->trash = w;
	widgets->scene.filename =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_filename));
	widgets->scene.fichier = NULL;
	widgets->scene.fichier = fopen("test.txt", "w");
	text = g_strdup_printf("mv test.txt %s; mv %s demo",
		widgets->scene.filename, widgets->scene.filename);
	command = (const char*)(text);
	set_empty_char(widgets);
	if (widgets->scene.fichier != NULL)
	{
		fprintf(widgets->scene.fichier, "%s\n%s\n%s\n%s\n%s\n%s\n",
			widgets->scene.text_cam, widgets->scene.text_light,
			widgets->scene.text_image,
			widgets->scene.text_texture, widgets->scene.text_material,
			widgets->scene.text_shape);
		fclose(widgets->scene.fichier);
	}
	system(command);
	gtk_widget_hide(widgets->w_4);
	g_free(text);
}

void			on_add_light_clicked(GtkWidget *w, t_widgets *widgets)
{
	char		*lbl_change;

	lbl_change = "AJOUTER CAMERA";
	widgets->trash = w;
	gtk_widget_hide(widgets->w_2);
	gtk_button_set_label(GTK_BUTTON(widgets->btn_add_c), lbl_change);
	gtk_widget_show(widgets->w_3);
}

void			on_add_forme_clicked(GtkWidget *w, t_widgets *widgets)
{
	widgets->trash = w;
	gtk_widget_hide(widgets->w_3);
	gtk_widget_show(widgets->w_4);
}
