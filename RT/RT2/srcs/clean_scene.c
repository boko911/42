/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 10:43:04 by agrosset          #+#    #+#             */
/*   Updated: 2018/03/29 18:02:32 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	rm_lst_content(void *elem, size_t s)
{
	(void)s;
	free(elem);
}

static void	rm_lst_material(void *elem, size_t s)
{
	(void)s;
	free(((t_material *)elem)->name);
	free(((t_material *)elem)->texture);
	free(elem);
}

static void	rm_lst_texture(void *elem, size_t s)
{
	(void)s;
	ft_memdel((void **)(&((t_texture *)elem)->name));
	ft_memdel(&elem);
}

static void	rm_lst_surface(void *elem, size_t s)
{
	(void)s;
	free(((t_surface *)elem)->name);
	SDL_FreeSurface(((t_surface *)elem)->surface);
	free(elem);
}

void		clean_scene(t_scene *scene)
{
	if (scene == NULL)
		return ;
	if (scene->camera)
		free(scene->camera);
	ft_lstdel(&scene->objects, rm_lst_content);
	ft_lstdel(&scene->lights, rm_lst_content);
	ft_lstdel(&scene->materials, rm_lst_material);
	ft_lstdel(&scene->surface, rm_lst_surface);
	ft_lstdel(&scene->ph.fttexture, rm_lst_content);
	ft_lstdel(&scene->texture, rm_lst_texture);
	ft_lstdel(&scene->ph.perturbation, rm_lst_content);
	free(scene);
}
