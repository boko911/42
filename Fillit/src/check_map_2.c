/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:02:21 by nbuhler           #+#    #+#             */
/*   Updated: 2017/01/07 12:13:07 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check26(int *tab)
{
	int		i;

	i = 0;
	while (i <= tab[0])
	{
		if (tab[i] == -1)
			return (0);
		i++;
	}
	return (1);
}

int			ft_map_is_null(char *str)
{
	if (ft_strlen(str) == 6)
		return (1);
	else
		return (0);
}
