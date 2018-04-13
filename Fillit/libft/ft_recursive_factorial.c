/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:02:46 by nbuhler           #+#    #+#             */
/*   Updated: 2016/12/07 16:02:47 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_recursive_factorial(int nb)
{
	if (nb >= 2 && nb <= 12)
		return (nb * ft_recursive_factorial(nb - 1));
	if (nb == 0 || nb == 1)
		return (1);
	else
		return (0);
}
