/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 20:14:15 by barnout           #+#    #+#             */
/*   Updated: 2017/01/07 14:09:26 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**try_this_piece(char **old_square, char **new_square, int *p)
{
	if (new_square != NULL)
	{
		p[0]++;
		return (new_square);
	}
	else
	{
		return (old_square);
	}
}

void	x_init(t_position *x)
{
	x->line = 0;
	x->column = 0;
}

char	put_letter(int *ref, int id)
{
	int		i;

	i = 1;
	while (ref[i] != id)
		i++;
	return ('A' + i - 1);
}

char	**apply_piece(char **square, char **new_square, int *p, int *alpha)
{
	char	**tmp;

	tmp = square;
	square = try_this_piece(square, new_square, p);
	if (p[0] == *alpha && *alpha != 0)
	{
		square = tmp;
		p[0]--;
		*alpha = 0;
	}
	return (square);
}

char	**try_this_order(int size, int *pieces, int *ref, int alpha)
{
	char		**square;
	t_position	x;
	int			p[0];
	t_function	*put_t;

	x_init(&x);
	p[0] = 0;
	square = new_square(size);
	put_t = init_put_t_tab(ref[0], pieces);
	while (x.line < size)
	{
		while (x.column < size && p[0] < ref[0])
		{
			square = apply_piece(square, (*((put_t[p[0]]).f))(squarecpy(\
	square, size), size, x, put_letter(ref, (put_t[p[0]]).id)), p, &alpha);
			x.column++;
		}
		x.line++;
		x.column = 0;
	}
	free(put_t);
	if (p[0] == ref[0])
		return (square);
	free(square);
	return (NULL);
}
