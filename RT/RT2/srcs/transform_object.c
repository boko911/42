/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 14:22:25 by agrosset          #+#    #+#             */
/*   Updated: 2016/08/08 13:57:29 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	transform_object(t_obj *obj, t_tobj *tobj)
{
	tobj->ftrans = mtx_product(tobj->trans, mtx_product(tobj->rot,
		tobj->scale));
	tobj->i_trans = mtx_invert(tobj->trans);
	tobj->i_rot = mtx_invert(tobj->rot);
	tobj->i_scale = mtx_invert(tobj->scale);
	tobj->i_ftrans = mtx_invert(tobj->ftrans);
	obj->trans = *tobj;
}
