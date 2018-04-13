/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_reflect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 15:53:32 by agrosset          #+#    #+#             */
/*   Updated: 2018/01/29 13:55:43 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_mtx	vect_reflect(t_mtx dir, t_mtx normal)
{
	return (mtx_sub(dir, mtx_mult(normal, 2 * DOTV(normal, dir))));
}

t_mtx	vect_refract(int *bol, t_mtx dir, t_mtx normal, double ior)
{
	t_refract	refract;

	refract.a = DOTV(dir, normal);
	refract.cosi = ft_fclamp(refract.a, -1, 1);
	refract.etai = 1;
	refract.etat = ior;
	refract.n = normal;
	if (refract.cosi < 0)
		refract.cosi = -refract.cosi;
	else
	{
		ft_swap((void *)&refract.etai, (void *)&refract.etat);
		refract.n = mtx_negate(normal);
	}
	refract.eta = refract.etai / refract.etat;
	refract.k = 1 - refract.eta * refract.eta *
	(1 - refract.cosi * refract.cosi);
	if (refract.k < 0)
	{
		*bol = 0;
		return (mtx_init(4, 1));
	}
	*bol = 1;
	return (mtx_add(mtx_mult(dir, refract.eta),
	mtx_mult(refract.n, (refract.eta * refract.cosi - sqrt(refract.k)))));
}
