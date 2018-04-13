/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:02:58 by nbuhler           #+#    #+#             */
/*   Updated: 2016/12/07 16:03:00 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int n)
{
	int i;

	i = 0;
	if (n == 0 || n < 0)
		return (0);
	else
	{
		while (i * i < n)
		{
			i++;
		}
		if ((n % i) == 0)
			return (i);
		else
			return (0);
	}
}
