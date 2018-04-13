/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 22:08:15 by nbuhler           #+#    #+#             */
/*   Updated: 2017/01/07 13:07:33 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	ft_findchar(char *str, int num)
{
	while (str[num] != '#')
		num++;
	return (num);
}

static	int	ft_fill_part_id(char *str, int j, int i)
{
	int		new;
	int		tmp;

	if ((tmp = ft_fill_part1(str, j, i)) != -1)
		new = tmp;
	else if ((tmp = ft_fill_part2(str, j, i)) != -1)
		new = tmp;
	else if ((tmp = ft_fill_part3(str, j, i)) != -1)
		new = tmp;
	else
		new = -1;
	return (new);
}

int			*ft_part_id(char *str, int nbpart)
{
	int		j;
	int		i;
	int		k;
	int		*tab;
	int		*final;

	i = 0;
	j = 0;
	k = 0;
	tab = (int *)malloc(sizeof(int) * (nbpart));
	while (i < nbpart)
	{
		j = ft_findchar(str, (i * 21));
		tab[k++] = ft_fill_part_id(str, j, i * 21);
		i++;
	}
	final = ft_final_tab_int(tab, nbpart);
	if (ft_check26(final) == 0)
		return (NULL);
	return (final);
}
