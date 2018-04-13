/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tetriminos2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 22:07:17 by barnout           #+#    #+#             */
/*   Updated: 2016/12/31 13:02:30 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**put_t5(char **square, int n, t_position x, char c)
{
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	if (++x.column == n)
		return (NULL);
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	if (++x.column == n)
		return (NULL);
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	if (--x.line < 0)
		return (NULL);
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	return (square);
}

char	**put_t6(char **square, int n, t_position x, char c)
{
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	if (++x.line == n)
		return (NULL);
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	if (++x.column == n)
		return (NULL);
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	if (++x.column == n)
		return (NULL);
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	return (square);
}

char	**put_t7(char **square, int n, t_position x, char c)
{
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	if (++x.line == n)
		return (NULL);
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	x.line--;
	if (++x.column == n)
		return (NULL);
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	if (++x.column == n)
		return (NULL);
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	return (square);
}

char	**put_t8(char **square, int n, t_position x, char c)
{
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	if (++x.column == n)
		return (NULL);
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	x.column--;
	if (++x.line == n)
		return (NULL);
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	if (++x.line == n)
		return (NULL);
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	return (square);
}

char	**put_t9(char **square, int n, t_position x, char c)
{
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	if (++x.column == n)
		return (NULL);
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	if (++x.line == n)
		return (NULL);
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	if (++x.line == n)
		return (NULL);
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	return (square);
}
