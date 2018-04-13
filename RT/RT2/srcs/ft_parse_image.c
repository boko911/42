/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 14:15:07 by agrosset          #+#    #+#             */
/*   Updated: 2018/03/29 17:56:40 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	ft_parse_image_3(char **line, int *i, t_surface *img)
{
	if (!ft_strcmp(line[i[0]], "id"))
	{
		if (line[i[0] + 1] == NULL || !(ft_strlen(line[i[0] + 1]) > 0))
			return (return_print("Error parsing material id", 0));
		else
		{
			if (!(img->name = ft_strdup(line[++i[0]])))
				return (return_print("malloc error", 0));
			i[1] += 1;
		}
	}
	return (1);
}

static int	ft_parse_image_2(char **line, int *i, t_surface *img)
{
	char	*src_img;

	if (!ft_strcmp(line[i[0]], "name"))
	{
		if (!(src_img = ft_strjoin("./img/", line[i[0] + 1])))
			return (return_print("Error malloc", 0));
		if (!(img->surface = SDL_LoadBMP(src_img)))
		{
			ft_memdel((void **)&src_img);
			return (return_print("Error malloc", 0));
		}
		ft_memdel((void **)&src_img);
		i[1] += 1;
	}
	return (ft_parse_image_3(line, i, img));
}

static int	ft_delete_img(t_list **lst, t_surface **img)
{
	free(*lst);
	free((*img)->name);
	if ((*img)->surface != NULL)
		SDL_FreeSurface((*img)->surface);
	return (0);
}

static void	ft_initimg(int *i, t_list **lst, t_surface **img)
{
	(*img)->name = NULL;
	(*img)->surface = NULL;
	*lst = NULL;
	i[0] = 0;
	i[1] = 0;
}

int			ft_parse_image(t_env *env, char **line)
{
	int			i[2];
	t_surface	*img;
	t_list		*lst;

	if (env->scene == NULL)
		return (return_print("Error, a scene must be declared first", 0));
	if ((img = (t_surface *)ft_memalloc(sizeof(t_surface))) == NULL)
		return (return_print("malloc error", 0));
	ft_initimg(i, &lst, &img);
	while (line[++i[0]])
		if (ft_parse_image_2(line, i, img) == 0)
			return (ft_delete_img(&lst, &img));
	if ((lst = ft_lstnewfrom(img, sizeof(*img))) == NULL)
	{
		ft_delete_img(&lst, &img);
		return (return_print("malloc error", 0));
	}
	if (env->scene->surface == NULL)
		env->scene->surface = lst;
	else
		ft_lstadd(&(env->scene->surface), lst);
	return (i[1] == 2 ? 1 : return_print("error t_surface imcomplete", 0));
}
