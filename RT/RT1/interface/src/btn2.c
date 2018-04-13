/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 06:20:42 by nbuhler           #+#    #+#             */
/*   Updated: 2018/02/02 06:20:44 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void		on_add_spot_clicked(GtkWidget *w, t_widgets *widgets)
{
	widgets->trash = w;
	get_input_light(widgets);
	if (check_input_light(widgets) == 0)
	{
		widgets->scene.count_light++;
		widgets->scene.text_light = save_text_light(widgets);
		gtk_label_set_text(GTK_LABEL(widgets->l_add_s),
			g_strdup_printf("Spot %d Ajouté!!!", widgets->scene.count_light));
		reinitialize_entries_light(widgets);
	}
	else
		gtk_label_set_text(GTK_LABEL(widgets->l_add_s), NULL);
}

void		on_button_add_cam_clicked(GtkWidget *w, t_widgets *widgets)
{
	char *change_lbl;

	widgets->trash = w;
	change_lbl = "MODIFIER CAMERA";
	get_input_cam(widgets);
	if (check_input_cam(widgets) == 0)
	{
		save_text_cam(widgets);
		gtk_widget_show(widgets->btn_add_sl);
		gtk_button_set_label(GTK_BUTTON(widgets->btn_add_c), change_lbl);
	}
	else
		gtk_widget_hide(widgets->btn_add_sl);
}

void		on_create_mat_clicked(GtkWidget *w, t_widgets *widgets)
{
	widgets->trash = w;
	gtk_widget_show(widgets->g_cre_mat);
	gtk_widget_show(widgets->g_cre_txt);
}

void		on_btn_ok_mat_clicked(GtkWidget *w, t_widgets *widgets)
{
	widgets->trash = w;
	get_input_mat(widgets);
	if (check_input_mat(widgets) == 0)
	{
		gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(widgets->box_material), 10,
			widgets->scene.mat_name, widgets->scene.mat_name);
		widgets->scene.count_mat++;
		widgets->scene.text_material = mult_strjoin(widgets);
		gtk_label_set_text(GTK_LABEL(widgets->l_cre_mat),
			g_strdup_printf("Materiel %s Ajouté!!!", widgets->scene.mat_name));
		reinitialize_entries_mat(widgets);
	}
	else
		gtk_label_set_text(GTK_LABEL(widgets->l_cre_mat), NULL);
}
