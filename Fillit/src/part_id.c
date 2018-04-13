/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:43:30 by nbuhler           #+#    #+#             */
/*   Updated: 2017/01/07 13:29:06 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fill_part1(char *str, int j, int i)
{
	int	part_id;

	part_id = -1;
	if (str[j + 1] == '#' && str[j + 2] == '#' && str[j + 3] == '#' \
			&& j + 3 - i < 21)
		part_id = 0;
	else if (str[j + 1] == '#' && str[j + 2] == '#' && str[j + 7] == '#' \
			&& j + 7 - i < 21)
		part_id = 2;
	else if (str[j + 1] == '#' && str[j + 2] == '#' && str[j + 5] == '#' \
			&& j + 5 - i < 21)
		part_id = 7;
	else if (str[j + 1] == '#' && str[j + 2] == '#' && str[j + 6] == '#' \
			&& j + 6 - i < 21)
		part_id = 13;
	else if (str[j + 1] == '#' && str[j + 6] == '#' && str[j + 11] == '#' \
			&& j + 11 - i < 21)
		part_id = 9;
	return (part_id);
}

int		ft_fill_part2(char *str, int j, int i)
{
	int	part_id;

	part_id = -1;
	if (str[j + 5] == '#' && str[j + 10] == '#' && str[j + 15] == '#' \
			&& j + 15 - i < 21)
		part_id = 1;
	else if (str[j + 5] == '#' && str[j + 10] == '#' && str[j + 11] == '#' \
			&& j + 11 - i < 21)
		part_id = 3;
	else if (str[j + 5] == '#' && str[j + 9] == '#' && str[j + 10] == '#' \
			&& j + 10 - i < 21)
		part_id = 4;
	else if (str[j + 3] == '#' && str[j + 4] == '#' && str[j + 5] == '#' \
			&& j + 5 - i < 21)
		part_id = 5;
	else if (str[j + 1] == '#' && str[j + 5] == '#' && str[j + 10] == '#' \
			&& j + 10 - i < 21)
		part_id = 8;
	else if (str[j + 5] == '#' && str[j + 6] == '#' && str[j + 10] == '#' \
			&& j + 10 - i < 21)
		part_id = 11;
	else if (str[j + 4] == '#' && str[j + 5] == '#' && str[j + 10] == '#' \
			&& j + 10 - i < 21)
		part_id = 12;
	return (part_id);
}

int		ft_fill_part3(char *str, int j, int i)
{
	int	part_id;

	part_id = -1;
	if (str[j + 5] == '#' && str[j + 6] == '#' && str[j + 7] == '#' \
			&& j + 7 - i < 21)
		part_id = 6;
	else if (str[j + 4] == '#' && str[j + 5] == '#' && str[j + 6] == '#' \
			&& j + 6 - i < 21)
		part_id = 10;
	else if (str[j + 1] == '#' && str[j + 6] == '#' && str[j + 7] == '#' \
			&& j + 7 - i < 21)
		part_id = 14;
	else if (str[j + 1] == '#' && str[j + 4] == '#' && str[j + 5] == '#' \
			&& j + 5 - i < 21)
		part_id = 15;
	else if (str[j + 5] == '#' && str[j + 6] == '#' && str[j + 11] == '#' \
			&& j + 11 - i < 21)
		part_id = 16;
	else if (str[j + 4] == '#' && str[j + 5] == '#' && str[j + 9] == '#' \
			&& j + 9 - i < 21)
		part_id = 17;
	else if (str[j + 1] == '#' && str[j + 5] == '#' && str[j + 6] == '#' \
			&& j + 6 - i < 21)
		part_id = 18;
	return (part_id);
}
