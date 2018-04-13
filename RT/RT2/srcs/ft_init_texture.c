/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 14:15:07 by agrosset          #+#    #+#             */
/*   Updated: 2016/08/12 14:26:53 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	ft_init_texture(t_texture **text, t_env *env)
{
	if (env->scene == NULL)
		return (return_print("Error, a scene must be declared first", 0));
	if ((*text = (t_texture *)ft_memalloc(sizeof(t_texture))) == NULL)
		return (return_print("malloc error", 0));
	(*text)->surface = NULL;
	(*text)->begin_x = 0;
	(*text)->begin_y = 0;
	(*text)->elarge_x = 0.5;
	(*text)->elarge_y = 0.5;
	return (1);
}

int	ft_init_texture_p2(t_list **lst, t_texture *text)
{
	if ((*lst = ft_lstnewfrom(text, sizeof(*text))) == NULL)
	{
		ft_memdel((void **)&text);
		return (return_print("malloc error", 0));
	}
	return (1);
}
