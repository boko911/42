/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:24:35 by nbuhler           #+#    #+#             */
/*   Updated: 2017/01/07 13:08:43 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			ft_nbchar(char *str)
{
	int	i;
	int cont;

	i = 0;
	cont = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			cont++;
		i++;
	}
	return (cont);
}

int			ft_nbpart(char *str)
{
	int i;
	int cont;

	i = 0;
	cont = 0;
	while (str[i])
	{
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
			cont++;
		i++;
	}
	return (cont);
}

char		*bsnstr(char *str)
{
	int		i;
	int		x;
	char	*newstr;

	i = 0;
	x = 0;
	newstr = malloc(sizeof(*str) * ft_nbchar(str) * 10);
	while (str[i])
	{
		if (str[i] == '\n')
			newstr[x++] = fill_bsnstr(str, i);
		i++;
	}
	newstr[x] = '\0';
	return (newstr);
}

char		fill_bsnstr(char *str, int i)
{
	char	new;

	if (i == 0 && str[i] == '\n')
		new = 48;
	if (((str[i - 1] == '.' || str[i - 1] == '#') &&
		(str[i + 1] == '.' || str[i + 1] == '#')))
		new = 49;
	if ((str[i + 1] == '\n' || str[i + 1] == '\0') && (str[i - 1] == '.'
		|| str[i - 1] == '#'))
		new = 50;
	if (str[i - 1] == '\n' && (((str[i + 1] == '.' || str[i + 1] == '#'))))
		new = 51;
	if ((str[i - 1] == '\n') && str[i + 1] == '\n')
		new = 52;
	return (new);
}

int			ft_bsntest(char *str)
{
	size_t	i;
	size_t	k;
	char	*good;

	i = 0;
	k = 0;
	good = "11123";
	while (str[i])
	{
		while (k < 5 && (i + k) < ft_strlen(str))
		{
			if (str[i + k] != good[k])
				return (1);
			k++;
		}
		k = 0;
		i = i + 5;
	}
	return (0);
}
