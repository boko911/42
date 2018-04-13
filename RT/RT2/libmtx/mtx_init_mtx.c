/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_init_mtx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:09:23 by agrosset          #+#    #+#             */
/*   Updated: 2016/05/24 15:35:46 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmtx.h"

t_mtx		mtx_init_mtx(t_mtx mtx)
{
	t_mtx	out;
	int		i;

	out.cols = mtx.cols;
	out.rows = mtx.rows;
	i = -1;
	while (++i < mtx.cols * mtx.rows && i < SIZE_OF_MTX)
		out.mtx[i] = mtx.mtx[i];
	return (out);
}
