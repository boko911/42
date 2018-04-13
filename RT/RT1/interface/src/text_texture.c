/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 19:41:42 by nbuhler           #+#    #+#             */
/*   Updated: 2018/03/20 19:41:43 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

char			*texture_2(t_widgets *widgets)
{
	char		*text_texture;

	text_texture = ft_strjoin(widgets->scene.text_texture, "texture id ");
	text_texture = ft_strjoin(text_texture,
		(char*)widgets->scene.texture_id);
	text_texture = ft_strjoin(text_texture, " image ");
	text_texture = ft_strjoin(text_texture,
		(char*)widgets->scene.texture);
	text_texture = ft_strjoin(text_texture, " elarge ");
	text_texture = ft_strjoin(text_texture,
		(char*)widgets->scene.elarge1);
	text_texture = ft_strjoin(text_texture, " ");
	text_texture = ft_strjoin(text_texture,
		(char*)widgets->scene.elarge2);
	text_texture = ft_strjoin(text_texture, " begin ");
	text_texture = ft_strjoin(text_texture,
		(char*)widgets->scene.begin1);
	text_texture = ft_strjoin(text_texture, " ");
	text_texture = ft_strjoin(text_texture,
		(char*)widgets->scene.begin2);
	text_texture = ft_strjoin(text_texture, "\n");
	return (text_texture);
}

char			*texture_1(t_widgets *widgets)
{
	char		*text_texture;

	text_texture = "--Texture declarations\ntexture id ";
	text_texture = ft_strjoin(text_texture,
		(char*)widgets->scene.texture_id);
	text_texture = ft_strjoin(text_texture, " image ");
	text_texture = ft_strjoin(text_texture,
		(char*)widgets->scene.texture);
	text_texture = ft_strjoin(text_texture, " elarge ");
	text_texture = ft_strjoin(text_texture,
		(char*)widgets->scene.elarge1);
	text_texture = ft_strjoin(text_texture, " ");
	text_texture = ft_strjoin(text_texture,
		(char*)widgets->scene.elarge2);
	text_texture = ft_strjoin(text_texture, " begin ");
	text_texture = ft_strjoin(text_texture,
		(char*)widgets->scene.begin1);
	text_texture = ft_strjoin(text_texture, " ");
	text_texture = ft_strjoin(text_texture,
		(char*)widgets->scene.begin2);
	text_texture = ft_strjoin(text_texture, "\n");
	return (text_texture);
}

char			*mult_strjoin_texture(t_widgets *widgets)
{
	char	*text_texture;

	if (widgets->scene.count_texture == 1)
		text_texture = texture_1(widgets);
	if (widgets->scene.count_texture >= 2)
		text_texture = texture_2(widgets);
	return (text_texture);
}
