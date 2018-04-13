/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 06:05:30 by nbuhler           #+#    #+#             */
/*   Updated: 2018/04/02 16:03:44 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

char			*ft_strdup(const char *s1)
{
	int			i;
	char		*s2;
	int			strlen;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
		strlen = i;
	}
	i = 0;
	if (!(s2 = (char*)malloc((strlen + 1) * sizeof(*s1))))
		exit(-1);
	if (!s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int				ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int				check_string(char *str)
{
	int			i;
	int			count_dot;

	i = 0;
	count_dot = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] == '.' && count_dot == 0)
				count_dot++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int				ft_isint(char *str)
{
	long long	nb;
	int			sign;

	nb = 0;
	while (*str && *str == ' ')
		str++;
	sign = (*str == '-' ? -1 : 1);
	if (*str == '-' || *str == '+')
		str++;
	if (check_string(str) == 1)
	{
		while (*str)
		{
			if ((sign * (nb = nb * 10 + (*str - '0'))) > INT_MAX
				|| (sign * nb) < INT_MIN)
				return (0);
			str++;
		}
	}
	else
		return (0);
	return (1);
}
