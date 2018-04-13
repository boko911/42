/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 20:14:07 by barnout           #+#    #+#             */
/*   Updated: 2017/01/05 22:03:09 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**put_t0(char **square, int n, t_position x, char c)
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
	if (++x.column == n)
		return (NULL);
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	return (square);
}

char	**put_t1(char **square, int n, t_position x, char c)
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

char	**put_t2(char **square, int n, t_position x, char c)
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
	if (++x.line == n)
		return (NULL);
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	return (square);
}

char	**put_t3(char **square, int n, t_position x, char c)
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
	return (square);
}

char	**put_t4(char **square, int n, t_position x, char c)
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
	if (++x.line == n)
		return (NULL);
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	if (--x.column < 0)
		return (NULL);
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	return (square);
}
