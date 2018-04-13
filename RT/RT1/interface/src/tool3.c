/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 06:12:51 by nbuhler           #+#    #+#             */
/*   Updated: 2018/04/02 19:02:35 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void			*ft_memset(void *s, int c, size_t n)
{
	char		*s1;
	size_t		i;

	s1 = (char *)s;
	i = 0;
	while (i < n)
	{
		s1[i] = c;
		i++;
	}
	return (s);
}

static	size_t	ft_lennewstr(int n)
{
	size_t		i;

	i = 1;
	if (n < 0)
		i++;
	while (n /= 10)
		i++;
	return (i);
}

void			*ft_memalloc(size_t size)
{
	void		*str;
	size_t		i;

	i = 0;
	if (!(str = malloc(size)))
		exit(-1);
	if (!str)
		return (NULL);
	ft_memset(str, 0, size);
	return (str);
}

static	char	*ft_fill_str_itoa(int n, char *str, size_t len)
{
	size_t		mult;

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
	char		*str;
	size_t		len;

	len = ft_lennewstr(n);
	if (!(str = (char *)malloc(sizeof(*str) * len + 1)))
		exit(-1);
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
