/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 06:36:15 by nbuhler           #+#    #+#             */
/*   Updated: 2018/02/02 06:36:18 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

int		check_ambiant_mat(t_widgets *widgets)
{
	int	ret;

	ret = 0;
	if (ft_isint((char*)widgets->scene.ambiant) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_ambiant),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#FF0000\" size=\"13\"> Ambiant : </span>",
				-1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_ambiant),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\" size=\"13\"> Ambiant : </span>",
				-1, NULL, NULL, NULL));
	return (ret);
}

int		check_diffuse_mat(t_widgets *widgets)
{
	int	ret;

	ret = 0;
	if (ft_isint((char*)widgets->scene.diffuse) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_diffuse),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#FF0000\" size=\"13\"> Diffuse : </span>",
				-1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_diffuse),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\" size=\"13\"> Diffuse : </span>",
				-1, NULL, NULL, NULL));
	return (ret);
}

int		check_specular_mat(t_widgets *widgets)
{
	int	ret;

	ret = 0;
	if (ft_isint((char*)widgets->scene.specular) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_specular),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#FF0000\" size=\"13\"> Specular : </span>",
				-1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_specular),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\" size=\"13\"> Specular : </span>",
				-1, NULL, NULL, NULL));
	return (ret);
}

int		check_shininess_mat(t_widgets *widgets)
{
	int	ret;

	ret = 0;
	if (ft_isint((char*)widgets->scene.shininess) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_shininess),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#FF0000\" size=\"13\"> Brillance : </span>",
				-1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_shininess),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\" size=\"13\"> Brillance : </span>",
				-1, NULL, NULL, NULL));
	return (ret);
}

int		check_reflexion_mat(t_widgets *widgets)
{
	int	ret;

	ret = 0;
	if (ft_isint((char*)widgets->scene.reflexion) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_reflexion),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#FF0000\" size=\"13\"> Reflexion : </span>",
				-1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_reflexion),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\" size=\"13\"> Reflexion : </span>",
				-1, NULL, NULL, NULL));
	return (ret);
}
