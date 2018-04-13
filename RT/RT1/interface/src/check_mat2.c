/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mat2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 06:36:31 by nbuhler           #+#    #+#             */
/*   Updated: 2018/02/02 06:36:32 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

int		check_refraction_mat(t_widgets *widgets)
{
	int	ret;

	ret = 0;
	if (ft_isint((char*)widgets->scene.refraction1) == 0 ||
		ft_isint((char*)widgets->scene.refraction2) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_refraction),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#FF0000\" size=\"13\"> Refraction : </span>",
				-1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_refraction),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\" size=\"13\"> Refraction : </span>",
				-1, NULL, NULL, NULL));
	return (ret);
}

int		check_name_mat(t_widgets *widgets)
{
	int	ret;

	ret = 0;
	if (ft_strlen((char*)widgets->scene.mat_name) == 0)
	{
		ret = 1;
		gtk_label_set_markup(GTK_LABEL(widgets->l_name_m),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#FF0000\" size=\"13\"> Nom du Matériel : </span>",
				-1, NULL, NULL, NULL));
	}
	else
		gtk_label_set_markup(GTK_LABEL(widgets->l_name_m),
			g_locale_to_utf8("<span face=\"American Typewriter Semi-Bold\"\
				foreground=\"#000000\" size=\"13\"> Nom du Matériel : </span>",
				-1, NULL, NULL, NULL));
	return (ret);
}

int		check_input_mat(t_widgets *widgets)
{
	int	ret;

	ret = 0;
	ret = check_ambiant_mat(widgets) +
		check_diffuse_mat(widgets) +
		check_specular_mat(widgets) +
		check_shininess_mat(widgets) +
		check_reflexion_mat(widgets) +
		check_refraction_mat(widgets) +
		check_name_mat(widgets);
	if (g_strcmp0(widgets->scene.texture_mat, "sans texture") == 0)
		widgets->scene.with_texture = 1;
	else
		widgets->scene.with_texture = 0;
	return (ret);
}
