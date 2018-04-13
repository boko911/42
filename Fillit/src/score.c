/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 10:54:11 by barnout           #+#    #+#             */
/*   Updated: 2017/01/07 14:10:30 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_size(int nb)
{
	int		i;

	i = 0;
	while (i * i < nb)
		i++;
	if (i * i == nb)
		return (2 * i);
	return ((2 * i) - 1);
}

int		ft_square_score(char **square, int size)
{
	int		line;
	int		column;
	int		score;

	line = 0;
	column = 0;
	score = -1;
	while (line < size)
	{
		while (column < size)
		{
			if (square[line][column] == '.')
			{
				score += (line * 4) + column + 1;
			}
			column++;
		}
		line++;
		column = 0;
	}
	return (score);
}

int		ft_score(int *permutation, int *pieces, int alpha, int sq_score)
{
	int		i;
	int		toto;
	int		tmp;

	i = 0;
	toto = 0;
	while (i < pieces[0] && pieces[i + 1] == permutation[i])
	{
		toto++;
		i++;
	}
	tmp = i;
	while (i < pieces[0] && pieces[tmp + 1] != permutation[i])
		i++;
	if (alpha == 0)
		alpha = 27;
	toto = (toto + 1) * 1000000 + (sq_score * 1000) \
		- (i * 100) + (alpha * 10000);
	i = tmp + 1;
	tmp = i;
	while (i < pieces[0] && pieces[tmp + 1] != permutation[i])
		i++;
	toto = toto - (30 * i);
	return (toto);
}
