/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 22:22:18 by barnout           #+#    #+#             */
/*   Updated: 2017/01/07 13:09:03 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		*init_functions_tab(void)
{
	char	**(**put_t)(char **square, int n, t_position x, char c);

	put_t = malloc(19 * sizeof(void *));
	if (put_t == NULL)
		return (NULL);
	put_t[0] = put_t0;
	put_t[1] = put_t1;
	put_t[2] = put_t2;
	put_t[3] = put_t3;
	put_t[4] = put_t4;
	put_t[5] = put_t5;
	put_t[6] = put_t6;
	put_t[7] = put_t7;
	put_t[8] = put_t8;
	put_t[9] = put_t9;
	put_t[10] = put_t10;
	put_t[11] = put_t11;
	put_t[12] = put_t12;
	put_t[13] = put_t13;
	put_t[14] = put_t14;
	put_t[15] = put_t15;
	put_t[16] = put_t16;
	put_t[17] = put_t17;
	put_t[18] = put_t18;
	return (put_t);
}

t_function	*init_put_t_tab(int size, int *pieces)
{
	char		**(**put_t)(char **square, int n, t_position x, char c);
	t_function	*put_piece;
	int			i;
	int			j;

	put_piece = malloc(size * sizeof(t_function));
	if (put_piece == NULL)
		return (NULL);
	put_t = init_functions_tab();
	i = 0;
	j = 0;
	while (i < size)
	{
		while ((pieces[i] % 19) != j && j < 19)
			j++;
		(put_piece[i]).f = put_t[j];
		(put_piece[i]).id = pieces[i];
		j = 0;
		i++;
	}
	return (put_piece);
}
