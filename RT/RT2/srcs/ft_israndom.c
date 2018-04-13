/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_israndom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 12:24:06 by agrosset          #+#    #+#             */
/*   Updated: 2018/03/29 18:01:53 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static	void	ft_random_double(char **str, int min, int max, int id)
{
	double	random_d;
	int		add;

	add = (id == 5) ? -9 : 0;
	random_d = rand() % ((max + add) + 1 - min) + min;
	if (id == 5)
		while (random_d > 1.0)
			random_d /= 10.0;
	*str = ft_ftoa(random_d);
	return ;
}

static void		ft_random_int(char **str, int min, int max, int id)
{
	int		random;
	int		pos_or_neg;
	int		add;

	random = rand();
	pos_or_neg = rand();
	add = (id == 2) ? 90 : 0;
	add = (id == 5) ? -9 : 0;
	if (id == 0 || id == 1 || id == 2 || id == 5)
	{
		random = rand() % ((max + add) + 1 - min) + min;
		if (id == 1 && pos_or_neg % 2 == 0)
			random = -random;
	}
	else if (id == 3)
		random = (pos_or_neg % 2 == 0) ? 1 : 0;
	*str = ft_itoa(random);
}

char			*ft_israndom(char **str, int min, int max, int id)
{
	if (**str == '~')
	{
		free(*str);
		*str = NULL;
		if (id != 4 && id != 5)
			ft_random_int(str, min, max, id);
		else
			ft_random_double(str, min, max, id);
	}
	return (*str);
}
