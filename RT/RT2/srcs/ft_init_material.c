/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_material.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 14:15:07 by agrosset          #+#    #+#             */
/*   Updated: 2016/08/12 14:26:53 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ft_init_material(t_material *mat)
{
	mat->color1 = rgb_new(1, 1, 1);
	mat->color1 = rgb_new(0, 0, 0);
	mat->shine = 100;
	mat->k_ambiant = 1;
	mat->k_spec = 1;
	mat->k_diffuse = 0.9;
	mat->refle = 0;
	mat->refra = 0;
	mat->n = 1.0;
	mat->name = NULL;
	mat->ft_perturbation = &ft_perturbation_uni;
	mat->texture = NULL;
}
