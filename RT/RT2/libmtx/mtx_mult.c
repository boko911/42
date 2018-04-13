/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 12:14:05 by agrosset          #+#    #+#             */
/*   Updated: 2016/06/07 13:34:01 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmtx.h"

t_mtx		mtx_mult(t_mtx mtx, double mult)
{
	int		i;
	t_mtx	out;

	out = mtx_init(mtx.rows, mtx.cols);
	i = -1;
	while (++i < mtx.cols * mtx.rows)
		out.mtx[i] = mtx.mtx[i] * mult;
	return (out);
}
