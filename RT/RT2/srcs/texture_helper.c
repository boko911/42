/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 17:01:21 by agrosset          #+#    #+#             */
/*   Updated: 2018/04/02 19:24:26 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	ft_init_imgtexture_p2(t_obj *obj, t_fttexture **ret_texture,
	t_list *actuel)
{
	(*ret_texture)->texture = (t_texture *)actuel->content;
	(*ret_texture)->obj = obj;
	if (obj->inter == &plane_inter)
		(*ret_texture)->fct_getcolor_imgtext = &ft_texture_plane;
	else
		(*ret_texture)->fct_getcolor_imgtext = &ft_spherical_mapping;
}

static int	ft_init_imgtexture(t_phpa *ph, t_obj *obj,
	t_fttexture **ret_texture)
{
	t_list		*actuel;
	t_texture	*texture;

	actuel = ph->texture;
	if (actuel != NULL)
	{
		if (((*ret_texture) =
			(t_fttexture *)ft_memalloc(sizeof(t_fttexture))) == NULL)
			return_print("malloc error", 0);
		while (actuel != NULL)
		{
			texture = (t_texture *)actuel->content;
			if (!ft_strcmp(texture->name, obj->mat->texture))
				break ;
			actuel = actuel->next;
		}
	}
	else
		return (0);
	ft_init_imgtexture_p2(obj, ret_texture, actuel);
	return (1);
}

static int	ft_alloc_lst(t_list **lst_new, t_fttexture **ret_texture)
{
	if ((*lst_new = ft_lstnew((void *)*ret_texture,
		sizeof(t_fttexture))) == NULL)
	{
		free(*ret_texture);
		ft_putendl("malloc error: t_list texture");
		return (0);
	}
	return (1);
}

t_fttexture	*get_imgtext(t_phpa *ph, t_obj *obj)
{
	t_list		*lst_new;
	t_list		*actuel;
	t_fttexture	*ret_texture;

	actuel = ph->fttexture;
	while (actuel != NULL)
	{
		ret_texture = (t_fttexture *)actuel->content;
		if (ret_texture->obj == obj)
			return (ret_texture);
		actuel = actuel->next;
	}
	ret_texture = NULL;
	if (ft_init_imgtexture(ph, obj, &ret_texture) == 0)
		return (NULL);
	if (!ft_alloc_lst(&lst_new, &ret_texture))
		return (NULL);
	if (ph->fttexture == NULL)
		ph->fttexture = lst_new;
	else
		ft_lstadd(&ph->fttexture, lst_new);
	free(ret_texture);
	return ((t_fttexture *)lst_new->content);
}
