/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 12:59:00 by nbuhler           #+#    #+#             */
/*   Updated: 2017/01/04 20:05:36 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_dot(char *str, int nbpart)
{
	int i;
	int j;
	int contn;
	int contdot;

	i = -1;
	j = 0;
	while (++i < nbpart)
	{
		contn = 0;
		contdot = 0;
		while (contn < 2 && str[j])
		{
			if (str[j] == '\n')
				contn++;
			else
				contn = 0;
			if (str[j] == '.')
				contdot++;
			j++;
		}
		if (contdot != 12)
			return (1);
	}
	return (0);
}

int			ft_check_slash(char *str, int nbpart)
{
	int i;
	int j;
	int contn;
	int contslash;

	i = -1;
	j = 0;
	while (++i < nbpart)
	{
		contn = 0;
		contslash = 0;
		while (contn < 2 && str[j])
		{
			if (str[j] == '\n')
				contn++;
			else
				contn = 0;
			if (str[j] == '#')
				contslash++;
			j++;
		}
		if (contslash != 4)
			return (1);
	}
	return (0);
}

int			ft_check_last_char(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != '\n')
		return (1);
	else
		return (0);
}

int			ft_testchar(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
