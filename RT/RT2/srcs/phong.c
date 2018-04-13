/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 12:41:32 by agrosset          #+#    #+#             */
/*   Updated: 2018/03/08 15:22:35 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	g_x;
int	g_y;

static void	phong_p2(t_phpa *ph, t_obj *obj, double d[2], double p)
{
	if (obj->mat->ft_perturbation != NULL)
		rgb_add(ph->diffuse,
			ft_max((ph->light->color.r) * obj->mat->k_diffuse *
			ft_get_nuance(ph, obj, 'r', 0) * d[0] * p, 0.0),
			ft_max((ph->light->color.g) * obj->mat->k_diffuse *
			ft_get_nuance(ph, obj, 'g', 0) * d[0] * p, 0.0),
			ft_max((ph->light->color.b) * obj->mat->k_diffuse *
			ft_get_nuance(ph, obj, 'b', 0) * d[0] * p, 0.0));
	rgb_add(ph->specular,
		ft_max(ph->light->color.r * obj->mat->k_spec * d[1] * p
			* ph->coef_refrac, 0.0),
		ft_max(ph->light->color.g * obj->mat->k_spec * d[1] * p
			* ph->coef_refrac, 0.0),
		ft_max(ph->light->color.b * obj->mat->k_spec * d[1] * p
			* ph->coef_refrac, 0.0));
}

void		phong(t_phpa *ph)
{
	t_mtx	r;
	t_ray	inv[2];
	t_obj	*obj;
	double	d[2];
	double	p;

	inv[0] = invert_ray(*ph->lray);
	r = vect_reflect(inv[0].dir, ph->normal);
	p = ft_fclamp((ph->light->power / POW2(ph->lray->t)), 0.0, 1.0);
	inv[1] = invert_ray(*ph->ray);
	obj = ph->ray->obj_closest;
	d[0] = ft_max(DOTV(ph->normal, inv[0].dir), 0.0);
	d[1] = ft_max(pow(DOTV(r, inv[1].dir), obj->mat->shine), 0.0);
	phong_p2(ph, obj, d, p);
}
