/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_createscalemtx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 14:37:56 by agrosset          #+#    #+#             */
/*   Updated: 2016/08/08 13:54:37 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_mtx	mtx_createscalemtx(double scalex, double scaley, double scalez)
{
	t_mtx	mtx;

	mtx = mtx_init(4, 4);
	mtx.mtx[0] = scalex;
	mtx.mtx[5] = scaley;
	mtx.mtx[10] = scalez;
	mtx.mtx[15] = 1;
	return (mtx);
}
