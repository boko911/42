/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:29:32 by nbuhler           #+#    #+#             */
/*   Updated: 2018/03/21 16:29:35 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

int		check_input_texture_elarge(t_widgets *widgets)
{
	int	ret;

	ret = 0;
	if (ft_isint((char*)widgets->scene.elarge1) == 0 ||
		ft_isint((char*)widgets->scene.elarge2) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_elarge),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#FF0000\" size=\"13\"> E LARGE : </span>",
				-1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_elarge),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\" size=\"13\"> E LARGE : </span>",
				-1, NULL, NULL, NULL));
	return (ret);
}

int		check_input_texture_begin(t_widgets *widgets)
{
	int	ret;

	ret = 0;
	if (ft_isint((char*)widgets->scene.begin1) == 0 ||
		ft_isint((char*)widgets->scene.begin2) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_begin),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#FF0000\" size=\"13\"> BEGIN : </span>",
				-1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_begin),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\" size=\"13\"> BEGIN : </span>",
				-1, NULL, NULL, NULL));
	return (ret);
}

int		check_input_texture(t_widgets *widgets)
{
	int	ret;

	ret = 0;
	if (ft_strlen((char*)widgets->scene.texture_id) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_texture_id),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#FF0000\" size=\"13\"> Texture ID : </span>",
				-1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_texture_id),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\" size=\"13\"> Texture ID : </span>",
				-1, NULL, NULL, NULL));
	ret += check_input_texture_begin(widgets) +
			check_input_texture_elarge(widgets);
	return (ret);
}
