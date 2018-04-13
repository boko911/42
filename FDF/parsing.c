/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 12:01:45 by nbuhler           #+#    #+#             */
/*   Updated: 2017/04/18 12:01:47 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_fill_list(t_data **data, char **tab, int x, int y)
{
	t_data	*new_maillon;
	t_data	*tmp;
	int		i;

	i = 0;
	new_maillon = (t_data*)ft_memalloc(sizeof(t_data));
	new_maillon->x = x;
	new_maillon->y = y;
	new_maillon->z = (int *)malloc(sizeof(int) * x);
	ft_check_tab(tab);
	while (i < x)
	{
		new_maillon->z[i] = ft_atoi(tab[i]);
		i++;
	}
	if (*data == NULL)
		*data = new_maillon;
	else
	{
		tmp = *data;
		while (tmp && tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_maillon;
	}
}

int			ft_find_xf(t_data *data)
{
	t_data	*tmp;
	int		i;
	int		cont;

	i = 0;
	cont = 0;
	tmp = data;
	while (tmp && tmp->next != NULL)
	{
		while (i < data->x)
			i++;
		cont = i;
		i = 0;
		tmp = tmp->next;
	}
	return (cont);
}

int			ft_find_yf(t_data *data)
{
	int		i;

	i = 0;
	while (data)
	{
		i++;
		data = data->next;
	}
	return (i);
}

int			ft_nb_element(char *str, char c)
{
	int		i;
	int		d;
	int		word;

	i = 0;
	d = 0;
	word = 0;
	while (str[i])
	{
		if (str[i++] != c)
		{
			if (d == 0)
			{
				d = 1;
				word++;
			}
		}
		else
			d = 0;
	}
	return (word);
}

void		ft_parsing(int fd, t_data **data)
{
	char	*line;
	int		column;
	int		i;

	i = 0;
	column = 0;
	while (get_next_line(fd, &line) > 0)
	{
		column = ft_nb_element(line, ' ');
		i++;
		ft_fill_list(data, ft_strsplit(line, ' '), column, i);
	}
}
