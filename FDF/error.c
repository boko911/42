/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 18:49:02 by nbuhler           #+#    #+#             */
/*   Updated: 2017/04/24 18:49:05 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>

int					ft_check_input(const char **argv)
{
	const	char	*str;
	int				result;
	int				i;
	struct stat		buf;

	str = *argv;
	result = 0;
	i = 0;
	stat(str, &buf);
	while (str[i] != '\0')
	{
		if (str[i] == '.' && str[i + 1] == 'f' && str[i + 2] == 'd'
			&& str[i + 3] == 'f' && str[i + 4] == '\0')
			result = 1;
		i++;
	}
	if (!S_ISREG(buf.st_mode))
		result = 0;
	return (result);
}

void				ft_error(int nb)
{
	if (nb == 2)
		ft_putstr("ERROR NEED A FILE!");
	if (nb == 1)
		ft_putstr("ERROR WRONG FILE!");
	if (nb == 3)
		ft_putstr("ERROR WRONG FILE!");
	exit(0);
}

void				ft_check_tab(char **tab)
{
	int			i;
	int			j;
	long long	nbr;
	int			tour;
	int			sign;

	i = -1;
	while (tab[++i])
	{
		tour = 1;
		nbr = 0;
		j = -1;
		sign = (tab[i][j] == '-') ? -1 : 1;
		if (tab[i][j] == '-' || tab[i][j] == '+')
			j++;
		while (tab[i][++j])
		{
			if (tour > 10 || !ft_isdigit(tab[i][j]))
				ft_error(3);
			nbr = nbr * 10 + tab[i][j] - '0';
			tour++;
		}
		if ((nbr *= sign) > INT_MAX || nbr < INT_MIN)
			ft_error(3);
	}
}
