/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 16:22:40 by agrosset          #+#    #+#             */
/*   Updated: 2016/08/16 16:24:48 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_lstaddend(t_list *alst, t_list *new)
{
	if (alst == NULL || new == NULL)
		return ;
	while (alst->next)
		alst = alst->next;
	alst->next = new;
}
