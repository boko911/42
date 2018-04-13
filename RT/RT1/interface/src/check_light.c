/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 06:52:56 by nbuhler           #+#    #+#             */
/*   Updated: 2018/02/02 06:52:57 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

int				check_pos_light(t_widgets *widgets)
{
	int			ret;

	ret = 0;
	if (ft_isint((char*)widgets->scene.pos_x_light) == 0 ||
		ft_isint((char*)widgets->scene.pos_y_light) == 0 ||
		ft_isint((char*)widgets->scene.pos_z_light) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_pos_l),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#FF0000\"size=\"13\"> Position : </span>",
				-1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_pos_l),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\" size=\"13\"> Position : </span>",
				-1, NULL, NULL, NULL));
	return (ret);
}

int				check_intensity_light(t_widgets *widgets)
{
	int			ret;

	ret = 0;
	if (ft_isint((char*)widgets->scene.intensity) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_intensity),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#FF0000\" size=\"13\"> Intensité : </span>",
				-1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_intensity),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\" size=\"13\"> Intensité : </span>",
				-1, NULL, NULL, NULL));
	return (ret);
}

int				check_input_light(t_widgets *widgets)
{
	int			ret;

	ret = 0;
	ret = check_pos_light(widgets) + check_intensity_light(widgets);
	return (ret);
}
