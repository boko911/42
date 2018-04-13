/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cam2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 06:27:25 by nbuhler           #+#    #+#             */
/*   Updated: 2018/02/02 06:27:27 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

int			check_s_ambiant(t_widgets *widgets)
{
	int		ret;

	ret = 0;
	if (ft_isint((char*)widgets->scene.scene_ambiant) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_s_ambiant),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#FF0000\" size=\"13\">   Scène Ambiant : </span>",
				-1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_s_ambiant),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\" size=\"13\">   Scène Ambiant : </span>",
				-1, NULL, NULL, NULL));
	return (ret);
}

int			check_b_ambiant(t_widgets *widgets)
{
	int		ret;

	ret = 0;
	if (ft_isint((char*)widgets->scene.base_impact_ambiant) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_b_ambiant),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
			foreground=\"#FF0000\" size=\"13\">"\
			"  Base Impact Ambiant : </span>",
			-1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_b_ambiant),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\" size=\"13\"\
				>  Base Impact Ambiant : </span>", -1, NULL, NULL, NULL));
	return (ret);
}

int			check_c_ambiant(t_widgets *widgets)
{
	int		ret;

	ret = 0;
	if (ft_isint((char*)widgets->scene.coef_impact_ambiant) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_c_ambiant),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#FF0000\" size=\"13\"\
				>  Coef Impact Ambiant : </span>", -1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_c_ambiant),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\" size=\"13\"\
				>  Coef Impact Ambiant : </span>", -1, NULL, NULL, NULL));
	return (ret);
}

int			check_max_r(t_widgets *widgets)
{
	int		ret;

	ret = 0;
	if (ft_isint((char*)widgets->scene.max_reflexion) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_max_r),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#FF0000\"size=\"13\"\
				>             Max Reflection : </span>", -1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_max_r),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\"size=\"13\"\
				>             Max Reflection : </span>", -1, NULL, NULL, NULL));
	return (ret);
}

int			check_input_cam(t_widgets *widgets)
{
	int		ret;

	ret = 0;
	ret = check_screen(widgets) +
	check_pos_cam(widgets) +
	check_rot_cam(widgets) +
	check_fov(widgets) +
	check_antialiasing(widgets) +
	check_s_ambiant(widgets) +
	check_b_ambiant(widgets) +
	check_c_ambiant(widgets) +
	check_max_r(widgets);
	return (ret);
}
