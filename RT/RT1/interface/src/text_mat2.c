/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_mat2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:14:22 by nbuhler           #+#    #+#             */
/*   Updated: 2018/03/22 17:14:26 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

char			*is_texture(char *text, t_widgets *widgets)
{
	char		*text_material;

	text_material = text;
	if (widgets->scene.with_texture == 0)
	{
		text_material = ft_strjoin(text, " texture ");
		text_material = ft_strjoin(text,
		(char*)widgets->scene.texture_mat);
	}
	return (text_material);
}
