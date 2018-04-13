/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_support_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 12:59:06 by barnout           #+#    #+#             */
/*   Updated: 2017/01/07 13:09:44 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*ft_tab_cpy(int *old_tab)
{
	int	*tab;
	int	i;

	tab = (int *)malloc((old_tab[0] + 1) * sizeof(int));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i <= old_tab[0])
	{
		tab[i] = old_tab[i];
		i++;
	}
	return (tab);
}

int		*ascending_order(int *old_tab)
{
	int		i;
	int		tmp;
	int		*tab;

	tab = ft_tab_cpy(old_tab);
	i = 1;
	while (i < tab[0])
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = tmp;
			i = 0;
		}
		i++;
	}
	return (tab);
}

char	**find_square(int *pieces, int size, t_list **permutation, int *sc)
{
	int		alpha;
	char	**tampon;
	char	**square;

	alpha = 0;
	square = NULL;
	while (alpha <= pieces[0])
	{
		if ((tampon = try_this_order(size, (*permutation)->content, \
						pieces, alpha)) != NULL)
		{
			if (ft_score((*permutation)->content, pieces, alpha, \
						ft_square_score(tampon, size)) > *sc)
			{
				square = tampon;
				*sc = ft_score((*permutation)->content, \
						pieces, alpha, ft_square_score(square, size));
			}
		}
		alpha++;
	}
	*permutation = (*permutation)->next;
	return (square);
}

char	**try_this_size(int *pieces, t_list *permutation, int *size)
{
	int		previous_score[1];
	char	**tampon;
	char	**square;

	*previous_score = -1;
	square = NULL;
	while (permutation != NULL)
	{
		if ((tampon = find_square(pieces, *size, &permutation, \
						previous_score)) != NULL)
			square = tampon;
	}
	size[0]++;
	return (square);
}
