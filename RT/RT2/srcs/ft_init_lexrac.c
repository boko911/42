/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_lexrac.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 16:41:10 by agrosset          #+#    #+#             */
/*   Updated: 2016/09/19 14:47:59 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_lexrac(t_lex_fra *re_flefra)
{
	re_flefra->nb_reflex = 0;
	re_flefra->nb_refrac = 0;
	re_flefra->coef_reflex = 1.0;
	re_flefra->coef_refrac = 1.0;
}
