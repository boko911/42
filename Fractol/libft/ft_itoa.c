/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:57:03 by nbuhler           #+#    #+#             */
/*   Updated: 2016/11/19 15:57:14 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_lennewstr(int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
		i++;
	while (n /= 10)
		i++;
	return (i);
}

static	char	*ft_fill_str_itoa(int n, char *str, size_t len)
{
	size_t	mult;

	mult = 1;
	while (len-- > 0)
	{
		if ((ft_lennewstr(mult)) <= ft_lennewstr(n))
		{
			mult *= 10;
			str[len] = ((n % mult) / (mult / 10)) + '0';
		}
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	len = ft_lennewstr(n);
	str = (char *)malloc(sizeof(*str) * len + 1);
	if (!str)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str = ft_fill_str_itoa(n, str, len);
	str[len] = '\0';
	return (str);
}
