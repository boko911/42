/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_mat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:27:04 by nbuhler           #+#    #+#             */
/*   Updated: 2018/02/28 11:27:05 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void			get_color_mat(t_widgets *widgets)
{
	gchar		test2[5];
	gchar		test3[5];
	gchar		test4[5];

	widgets->scene.color_r_shape =
		g_ascii_dtostr(test2, 5, widgets->color3.red);
	widgets->scene.color_g_shape =
		g_ascii_dtostr(test3, 5, widgets->color3.green);
	widgets->scene.color_b_shape =
		g_ascii_dtostr(test4, 5, widgets->color3.blue);
	widgets->scene.text_color_shape = g_strdup_printf(" color1 %s %s %s",
		widgets->scene.color_r_shape,
		widgets->scene.color_g_shape,
		widgets->scene.color_b_shape);
}

void			get_color2_mat(t_widgets *widgets)
{
	gchar		test2[5];
	gchar		test3[5];
	gchar		test4[5];

	widgets->scene.color2_r_shape =
		g_ascii_dtostr(test2, 5, widgets->color4.red);
	widgets->scene.color2_g_shape =
		g_ascii_dtostr(test3, 5, widgets->color4.green);
	widgets->scene.color2_b_shape =
		g_ascii_dtostr(test4, 5, widgets->color4.blue);
	widgets->scene.text_color2_shape = g_strdup_printf(" color2 %s %s %s",
		widgets->scene.color2_r_shape,
		widgets->scene.color2_g_shape,
		widgets->scene.color2_b_shape);
}
