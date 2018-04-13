/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 06:27:14 by nbuhler           #+#    #+#             */
/*   Updated: 2018/02/02 06:27:16 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

int			check_screen(t_widgets *widgets)
{
	int		ret;

	ret = 0;
	if (ft_isint((char*)widgets->scene.width) == 0 ||
		ft_isint((char*)widgets->scene.height) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_reso),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#FF0000\"size=\"13\">"\
				" Résolution de l'écran :     </span>", -1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_reso),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\"size=\"13\">"\
				" Résolution de l'écran :     </span>", -1, NULL, NULL, NULL));
	return (ret);
}

int			check_pos_cam(t_widgets *widgets)
{
	int		ret;

	ret = 0;
	if (ft_isint((char*)widgets->scene.pos_x_cam) == 0 ||
		ft_isint((char*)widgets->scene.pos_y_cam) == 0 ||
		ft_isint((char*)widgets->scene.pos_z_cam) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_pos),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
			foreground=\"#FF0000\"size=\"13\">      Position : </span>",\
			-1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_pos),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\"size=\"13\">      Position : </span>",
				-1, NULL, NULL, NULL));
	return (ret);
}

int			check_rot_cam(t_widgets *widgets)
{
	int		ret;

	ret = 0;
	if (ft_isint((char*)widgets->scene.rot_x_cam) == 0 ||
		ft_isint((char*)widgets->scene.rot_y_cam) == 0 ||
		ft_isint((char*)widgets->scene.rot_z_cam) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_rot),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#FF0000\"size=\"13\">     Rotation : </span>",
				-1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_rot),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\"size=\"13\">     Rotation : </span>",
				-1, NULL, NULL, NULL));
	return (ret);
}

int			check_fov(t_widgets *widgets)
{
	int		ret;

	ret = 0;
	if (ft_isint((char*)widgets->scene.fov) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_fov),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#FF0000\"size=\"13\">       F . O . V : </span>",
				-1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_fov),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
			foreground=\"#000000\" size=\"13\">       F . O . V : </span>",
			-1, NULL, NULL, NULL));
	return (ret);
}

int			check_antialiasing(t_widgets *widgets)
{
	int		ret;

	ret = 0;
	if (ft_isint((char*)widgets->scene.antialiasing) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_anti),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#FF0000\" size=\"13\">  Antialiasing : </span>",
				-1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_anti),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\" size=\"13\">  Antialiasing : </span>",
				-1, NULL, NULL, NULL));
	return (ret);
}
