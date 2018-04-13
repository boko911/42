/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:29:15 by nbuhler           #+#    #+#             */
/*   Updated: 2016/11/15 16:29:18 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int		ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	negative;

	nbr = 0;
	i = 0;
	negative = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	return ((negative == 1) ? (-nbr) : (nbr));
}
