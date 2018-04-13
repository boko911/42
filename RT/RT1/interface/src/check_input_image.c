/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:37:07 by nbuhler           #+#    #+#             */
/*   Updated: 2018/03/20 17:37:09 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

static int	check_input_image_pathimg(t_widgets *widgets)
{
	int		ret;

	ret = 0;
	if (widgets->scene.path_img == NULL)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_load_image),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#FF0000\" size=\"13\"> Load Image : </span>",
				-1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_load_image),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\" size=\"13\"> Load Image : </span>",
				-1, NULL, NULL, NULL));
	return (ret);
}

static int	check_input_image_imgid(t_widgets *widgets)
{
	int		ret;

	ret = 0;
	if (ft_strlen((char*)widgets->scene.img_id) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_imgid),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#FF0000\" size=\"13\"> Image ID : </span>",
				-1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_imgid),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\" size=\"13\"> Image ID : </span>",
				-1, NULL, NULL, NULL));
	return (ret);
}

int			check_input_image(t_widgets *widgets)
{
	int		ret;

	ret = 0;
	ret = check_input_image_pathimg(widgets) +
		check_input_image_imgid(widgets);
	return (ret);
}
