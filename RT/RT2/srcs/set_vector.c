/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 12:07:55 by agrosset          #+#    #+#             */
/*   Updated: 2016/08/08 13:57:14 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		set_vector(t_mtx *mtx, double x, double y, double z)
{
	if (mtx == NULL)
		return ;
	*mtx = mtx_init(4, 1);
	mtx->mtx[0] = x;
	mtx->mtx[1] = y;
	mtx->mtx[2] = z;
	mtx->mtx[3] = 1;
}
