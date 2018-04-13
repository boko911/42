/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 12:06:42 by agrosset          #+#    #+#             */
/*   Updated: 2016/06/16 16:06:46 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmtx.h"

t_mtx		mtx_sub(t_mtx mtx1, t_mtx mtx2)
{
	int		x;
	int		y;
	t_mtx	out;

	out = mtx_init(mtx1.rows, mtx1.cols);
	if (mtx1.cols != mtx2.cols || mtx1.rows != mtx2.rows)
		return (out);
	x = -1;
	while (++x < mtx1.cols)
	{
		y = -1;
		while (++y < mtx1.rows)
			out.mtx[x + y * out.cols] = mtx1.mtx[x + y * out.cols]
				- mtx2.mtx[x + y * out.cols];
	}
	return (out);
}
