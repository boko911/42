/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tetriminos4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 22:22:20 by barnout           #+#    #+#             */
/*   Updated: 2016/12/31 13:03:51 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**put_t15(char **square, int n, t_position x, char c)
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
	if (--x.column < 0)
		return (NULL);
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	return (square);
}

char	**put_t16(char **square, int n, t_position x, char c)
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
	if (++x.line == n)
		return (NULL);
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	return (square);
}

char	**put_t17(char **square, int n, t_position x, char c)
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
	if (--x.column < 0)
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

char	**put_t18(char **square, int n, t_position x, char c)
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
	if (--x.column < 0)
		return (NULL);
	if (square[x.line][x.column] == '.')
		square[x.line][x.column] = c;
	else
		return (NULL);
	return (square);
}
