/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:40:44 by nbuhler           #+#    #+#             */
/*   Updated: 2017/01/03 21:38:53 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*ft_final_tab_int(int *tab, int len)
{
	int		*new_tab;
	int		i;
	int		j;
	int		toto;

	new_tab = (int *)malloc((len + 1) * sizeof(int));
	if (new_tab == NULL)
		return (NULL);
	new_tab[0] = len;
	new_tab[1] = tab[0];
	i = 2;
	while (i <= len)
	{
		j = 1;
		toto = 0;
		while (j < i)
		{
			if (tab[j - 1] == tab[i - 1])
				toto++;
			j++;
		}
		new_tab[i] = tab[i - 1] + (19 * toto);
		i++;
	}
	return (new_tab);
}
