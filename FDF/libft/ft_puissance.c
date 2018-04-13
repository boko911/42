/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puissance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 10:52:16 by nbuhler           #+#    #+#             */
/*   Updated: 2016/11/30 10:52:20 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float		ft_puissance(int n, int expo)
{
	float	res;
	int		neg;
	int		i;

	i = 1;
	neg = 0;
	if (n == 0)
		return (0);
	if (expo == 0)
		return (1);
	res = n;
	if (expo < 0)
	{
		expo = -expo;
		neg = 1;
	}
	while (i < expo)
	{
		res = res * n;
		i++;
	}
	if (neg == 1)
		return (1 / res);
	return (res);
}
