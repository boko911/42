/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cam3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 06:27:31 by nbuhler           #+#    #+#             */
/*   Updated: 2018/02/02 06:27:32 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void		get_color_background_cam(t_widgets *widgets)
{
	gchar	test2[5];
	gchar	test3[5];
	gchar	test4[5];

	widgets->scene.color_r =
		g_ascii_dtostr(test2, 5, widgets->color.red);
	widgets->scene.color_g =
		g_ascii_dtostr(test3, 5, widgets->color.green);
	widgets->scene.color_b =
		g_ascii_dtostr(test4, 5, widgets->color.blue);
	widgets->scene.text_background =
		g_strdup_printf(" background %s %s %s ",
			widgets->scene.color_r,
			widgets->scene.color_g,
			widgets->scene.color_b);
}

void		get_input_cam_1(t_widgets *widgets)
{
	widgets->scene.width =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_width));
	widgets->scene.height =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_height));
	widgets->scene.pos_x_cam =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_pos_x_c));
	widgets->scene.pos_y_cam =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_pos_y_c));
	widgets->scene.pos_z_cam =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_pos_z_c));
	widgets->scene.rot_x_cam =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_rot_x_c));
	widgets->scene.rot_y_cam =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_rot_y_c));
	widgets->scene.rot_z_cam =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_rot_z_c));
	widgets->scene.fov =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_fov));
}

void		get_input_cam_2(t_widgets *widgets)
{
	widgets->scene.antialiasing =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_anti));
	widgets->scene.filtre =
	gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widgets->box_filtre));
	gtk_color_chooser_get_rgba(GTK_COLOR_CHOOSER(widgets->back_color_c),
		&widgets->color);
	get_color_background_cam(widgets);
	widgets->scene.scene_ambiant =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_s_ambiant));
	widgets->scene.base_impact_ambiant =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_b_ambiant));
	widgets->scene.coef_impact_ambiant =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_c_ambiant));
	widgets->scene.max_reflexion =
		gtk_entry_get_text(GTK_ENTRY(widgets->e_max_r));
}

void		get_input_cam(t_widgets *widgets)
{
	get_input_cam_1(widgets);
	get_input_cam_2(widgets);
}
