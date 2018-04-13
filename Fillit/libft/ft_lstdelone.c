/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:59:40 by nbuhler           #+#    #+#             */
/*   Updated: 2016/11/27 14:59:42 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*list;
	t_list	*tmp;

	list = *alst;
	if (list)
	{
		tmp = list->next;
		del(list->content, list->content_size);
		list = tmp;
	}
	*alst = NULL;
}
