/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ccone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 13:01:04 by agrosset          #+#    #+#             */
/*   Updated: 2016/09/12 15:54:27 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_alloc_cone(t_cone **obj, t_list **lst)
{
	if ((*obj = (t_cone *)ft_memalloc(sizeof(t_cone))) == NULL)
		return (return_print("malloc error", 0));
	if ((*lst = ft_lstnewfrom(*obj, sizeof(*obj))) == NULL)
	{
		free(obj);
		return (return_print("malloc error", 0));
	}
	return (1);
}

int		ft_delete_cone(t_list **lst, t_cone **obj)
{
	free(*lst);
	free(*obj);
	return (0);
}
