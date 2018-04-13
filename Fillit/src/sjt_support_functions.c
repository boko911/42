/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sjt_support_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 21:06:35 by barnout           #+#    #+#             */
/*   Updated: 2016/12/23 23:48:00 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_mobile_int(t_array *array, int size, int i)
{
	if (i == 0 && (array[i]).direction == '<')
		return (0);
	if (i == size - 1 && (array[i]).direction == '>')
		return (0);
	if ((array[i]).direction == '<' && (array[i]).nb <= (array[i - 1]).nb)
		return (0);
	if ((array[i]).direction == '>' && (array[i]).nb <= (array[i + 1]).nb)
		return (0);
	return (1);
}

void	*add_solution(t_list **solutions, t_array *array, int size)
{
	int		i;
	int		*tab;
	t_list	*new_elem;

	i = 0;
	tab = (int *)malloc(size * sizeof(int));
	if (tab == NULL)
		return (NULL);
	while (i < size)
	{
		tab[i] = (array[i]).nb;
		i++;
	}
	new_elem = ft_lstnew(tab, size * sizeof(int));
	ft_lstadd(solutions, new_elem);
	return (solutions);
}

void	*init_solutions(t_array *array, int size)
{
	int		i;
	int		*tab;
	t_list	*new_elem;

	i = 0;
	tab = (int *)malloc(size * sizeof(int));
	if (tab == NULL)
		return (NULL);
	while (i < size)
	{
		tab[i] = (array[i]).nb;
		i++;
	}
	new_elem = ft_lstnew(tab, size * sizeof(int));
	return (new_elem);
}
