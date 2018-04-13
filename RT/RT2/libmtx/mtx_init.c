/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:09:23 by agrosset          #+#    #+#             */
/*   Updated: 2016/05/24 15:35:46 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmtx.h"

t_mtx		mtx_init(int rows, int cols)
{
	t_mtx	mtx;
	int		i;

	mtx.cols = cols;
	mtx.rows = rows;
	i = -1;
	while (++i < cols * rows && i < SIZE_OF_MTX)
		mtx.mtx[i] = 0;
	return (mtx);
}
