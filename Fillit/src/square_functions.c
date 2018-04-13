/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 20:14:25 by barnout           #+#    #+#             */
/*   Updated: 2017/01/07 13:52:47 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

char	**squarecpy(char **src, int n)
{
	char	**square;
	int		i;
	int		j;

	square = (char**)malloc(n * sizeof(char*));
	if (square == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		square[i] = (char *)malloc(n * sizeof(char));
		if (square[i] == NULL)
			return (NULL);
		j = 0;
		while (j < n)
		{
			square[i][j] = src[i][j];
			j++;
		}
		i++;
	}
	return (square);
}

char	**new_square(int n)
{
	char	**square;
	int		i;
	int		j;

	square = (char**)malloc(n * sizeof(char*));
	if (square == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		square[i] = (char *)malloc(n * sizeof(char));
		if (square[i] == NULL)
			return (NULL);
		j = 0;
		while (j < n)
		{
			square[i][j] = '.';
			j++;
		}
		i++;
	}
	return (square);
}

void	print_square(char **square, int n)
{
	int	line;
	int	column;

	line = 0;
	column = 0;
	if (square != NULL)
	{
		while (line < n)
		{
			while (column < n)
			{
				ft_putchar(square[line][column]);
				column++;
			}
			ft_putchar('\n');
			line++;
			column = 0;
		}
	}
}
