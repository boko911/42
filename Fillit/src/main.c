/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:39:04 by nbuhler           #+#    #+#             */
/*   Updated: 2017/01/07 13:07:09 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*read_analyze(int argc, char **argv)
{
	int		fd;
	char	*str;
	int		*tab;
	int		tmp;
	int		nbpart;

	tab = NULL;
	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) == -1)
		ft_putstr("./fillit one_valid_file\n");
	else
	{
		str = ft_fill_str(fd);
		nbpart = ft_nbpart(str);
		if ((tmp = ft_error(str, nbpart)) == 0 && \
				(tab = ft_part_id(str, nbpart)) == NULL)
		{
			ft_putstr("error\n");
		}
		if (tmp != 0)
			ft_putstr("error\n");
	}
	return (tab);
}

int		main(int argc, char **argv)
{
	int		*pieces;
	int		size;
	char	**square;
	t_list	*permutation;
	t_list	*tmp;

	if ((pieces = read_analyze(argc, argv)) == NULL)
		return (0);
	size = ft_size(pieces[0]);
	square = NULL;
	tmp = sjt_algo(ascending_order(pieces));
	while (square == NULL)
	{
		permutation = tmp;
		square = try_this_size(pieces, permutation, &size);
	}
	print_square(square, size - 1);
	return (0);
}
