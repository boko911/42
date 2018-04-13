/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinitialize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:56:53 by nbuhler           #+#    #+#             */
/*   Updated: 2018/02/13 18:56:55 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void		reinitialize_entries(t_widgets *widgets)
{
	gtk_combo_box_set_active(GTK_COMBO_BOX(widgets->box_s_s), 0);
	gtk_entry_set_text(GTK_ENTRY(widgets->e_pos_x_s), "x");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_pos_y_s), "y");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_pos_z_s), "z");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_rot_x_s), "x");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_rot_y_s), "y");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_rot_z_s), "z");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_radius_s), "1");
}

void		reinitialize_entries_mat(t_widgets *widgets)
{
	gtk_entry_set_text(GTK_ENTRY(widgets->e_ambiant), "1");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_diffuse), "0");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_specular), "1");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_shininess), "100");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_reflexion), "0");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_refraction1), "0");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_refraction2), "0");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_name_mat), "...");
}

void		reinitialize_entries_light(t_widgets *widgets)
{
	gtk_entry_set_text(GTK_ENTRY(widgets->e_pos_x_l), "x");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_pos_y_l), "y");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_pos_z_l), "z");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_intensity), "100");
}

void		reinitialize_entries_cam(t_widgets *widgets)
{
	gtk_entry_set_text(GTK_ENTRY(widgets->e_width), "width");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_height), "height");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_pos_x_c), "x");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_pos_y_c), "y");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_pos_z_c), "z");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_rot_x_c), "x");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_rot_y_c), "y");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_rot_z_c), "z");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_fov), "80");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_anti), "1-4");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_s_ambiant), "0.3");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_b_ambiant), "1");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_c_ambiant), "1");
	gtk_entry_set_text(GTK_ENTRY(widgets->e_max_r), "0");
}

void		reinitialize_entries_img(t_widgets *widgets)
{
	gtk_entry_set_text(GTK_ENTRY(widgets->e_imgid), "...");
}
