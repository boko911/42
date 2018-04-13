/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:47:05 by nbuhler           #+#    #+#             */
/*   Updated: 2018/03/20 18:47:13 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

char			*image_2(t_widgets *widgets)
{
	char		*text_image;

	text_image = ft_strjoin(widgets->scene.text_image, "image id ");
	text_image = ft_strjoin(text_image,
		(char*)widgets->scene.img_id);
	text_image = ft_strjoin(text_image, " name ");
	text_image = ft_strjoin(text_image,
		(char*)widgets->scene.path_img);
	text_image = ft_strjoin(text_image, "\n");
	return (text_image);
}

char			*image_1(t_widgets *widgets)
{
	char		*text_image;

	text_image = "--Image declarations\nimage id ";
	text_image = ft_strjoin(text_image,
		(char*)widgets->scene.img_id);
	text_image = ft_strjoin(text_image, " name ");
	text_image = ft_strjoin(text_image,
		(char*)widgets->scene.path_img);
	text_image = ft_strjoin(text_image, "\n");
	return (text_image);
}

char			*mult_strjoin_image(t_widgets *widgets)
{
	char	*text_image;

	if (widgets->scene.count_img == 1)
		text_image = image_1(widgets);
	if (widgets->scene.count_img >= 2)
		text_image = image_2(widgets);
	return (text_image);
}
