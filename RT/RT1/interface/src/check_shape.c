/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 06:35:41 by nbuhler           #+#    #+#             */
/*   Updated: 2018/02/02 06:35:43 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

int		check_pos_shape(t_widgets *widgets)
{
	int	ret;

	ret = 0;
	if (ft_isint((char*)widgets->scene.pos_x_shape) == 0 ||
		ft_isint((char*)widgets->scene.pos_y_shape) == 0 ||
		ft_isint((char*)widgets->scene.pos_z_shape) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_pos_s),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#FF0000\" size=\"13\"> Position : </span>",
				-1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_pos_s),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\" size=\"13\"> Position : </span>",
				-1, NULL, NULL, NULL));
	return (ret);
}

int		check_rot_shape(t_widgets *widgets)
{
	int	ret;

	ret = 0;
	if (ft_isint((char*)widgets->scene.rot_x_shape) == 0 ||
		ft_isint((char*)widgets->scene.rot_y_shape) == 0 ||
		ft_isint((char*)widgets->scene.rot_z_shape) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_rot_s),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#FF0000\" size=\"13\"> Rotation : </span>",
				-1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_rot_s),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\" size=\"13\"> Rotation : </span>",
				-1, NULL, NULL, NULL));
	return (ret);
}

int		check_radius_shape(t_widgets *widgets)
{
	int	ret;

	ret = 0;
	if (ft_isint((char*)widgets->scene.radius) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_radius_s),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#FF0000\" size=\"13\"> Radius : </span>",
				-1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_radius_s),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\" size=\"13\"> Radius : </span>",
				-1, NULL, NULL, NULL));
	return (ret);
}

int		check_input_shape(t_widgets *widgets)
{
	int	ret;

	ret = 0;
	if (g_strcmp0(widgets->scene.shape, "$") == 0)
		return (ret);
	else
	{
		ret = check_pos_shape(widgets) +
			check_rot_shape(widgets) +
			check_radius_shape(widgets);
		return (ret);
	}
}
