/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sjt_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 11:00:37 by barnout           #+#    #+#             */
/*   Updated: 2016/12/23 23:55:13 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_array		*add_left_directions(int *tab)
{
	t_array	*array;
	int		i;

	array = (t_array *)malloc(tab[0] * sizeof(t_array));
	if (array == NULL)
		return (NULL);
	i = 1;
	while (i <= tab[0])
	{
		(array[i - 1]).nb = tab[i];
		(array[i - 1]).direction = '<';
		i++;
	}
	return (array);
}

static int			largest_mobile_int_range(t_array *array, int size)
{
	int		i;
	int		largest_mobile_int;

	i = 0;
	largest_mobile_int = 0;
	while (i < size)
	{
		largest_mobile_int = is_mobile_int(array, size, i) ? \
			ft_max(largest_mobile_int, (array[i]).nb) : largest_mobile_int;
		i++;
	}
	i = 0;
	if (largest_mobile_int == 0)
		return (55);
	while ((array[i]).nb != largest_mobile_int)
		i++;
	return (i);
}

static t_array		*swap_mobile(t_array *array, int range)
{
	t_array	tmp;

	if ((array[range]).direction == '<')
	{
		tmp = array[range - 1];
		array[range - 1] = array[range];
		array[range] = tmp;
	}
	else
	{
		tmp = array[range + 1];
		array[range + 1] = array[range];
		array[range] = tmp;
	}
	return (array);
}

static	t_array		*change_directions(t_array *array, int size, \
												int largest_mobile_int)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((array[i]).nb > largest_mobile_int)
			(array[i]).direction = ((array[i]).direction == '<') ? '>' : '<';
		i++;
	}
	return (array);
}

t_list				*sjt_algo(int *tab)
{
	t_array	*array;
	int		range;
	int		largest_mobile_int;
	t_list	*solutions;

	array = add_left_directions(tab);
	solutions = init_solutions(array, tab[0]);
	add_solution(&solutions, array, tab[0]);
	range = largest_mobile_int_range(array, tab[0]);
	largest_mobile_int = (range == 55) ? 0 : (array[range]).nb;
	while (largest_mobile_int > 0)
	{
		array = swap_mobile(array, range);
		add_solution(&solutions, array, tab[0]);
		array = change_directions(array, tab[0], largest_mobile_int);
		range = largest_mobile_int_range(array, tab[0]);
		largest_mobile_int = (range == 55) ? 0 : (array[range]).nb;
	}
	return (solutions);
}
