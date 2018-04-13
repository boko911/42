/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_material.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 10:27:24 by agrosset          #+#    #+#             */
/*   Updated: 2018/01/29 15:17:19 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_material		*get_material(t_env *env, const char *id)
{
	t_list		*material;
	t_material	*mat;

	mat = NULL;
	if (!ft_strcmp(id, "~") || !ft_strcmp(id, "~*") ||
	!ft_strcmp(id, "~+") || !ft_strcmp(id, "~/"))
	{
		if (ft_random_mat(env, id, &mat))
			return (mat);
	}
	else
	{
		material = env->scene->materials;
		while (material)
		{
			if (!ft_strcmp(id, ((t_material *)material->content)->name))
				return (((t_material *)material->content));
			material = material->next;
		}
	}
	ft_putendl("erreur de malloc ou pas de mat trouve");
	return (&env->base_material);
}
