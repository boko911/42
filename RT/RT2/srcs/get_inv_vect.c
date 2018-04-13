/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inv_vect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 16:41:10 by agrosset          #+#    #+#             */
/*   Updated: 2018/02/16 14:22:53 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_mtx			get_inv_vect(t_mtx *mtx)
{
	t_mtx			ret;

	ret = mtx_init(3, 1);
	ret.mtx[0] = 1. / mtx->mtx[0];
	ret.mtx[1] = 1. / mtx->mtx[1];
	ret.mtx[2] = 1. / mtx->mtx[2];
	return (ret);
}
