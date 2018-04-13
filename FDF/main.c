/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 12:19:25 by nbuhler           #+#    #+#             */
/*   Updated: 2017/04/17 12:19:28 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char const *argv[])
{
	int		fd;
	t_data	*data;
	t_fdf	fdf;
	t_draw	draw;
	t_env	e;

	if (argc == 2 && (ft_check_input(&argv[1]) == 1))
	{
		fd = open(argv[1], O_RDONLY);
		ft_parsing(fd, &data);
		close(fd);
		draw = ft_init_draw(data);
		if (draw.xf == 0 || draw.yf == 0)
		{
			ft_error(1);
			exit(0);
		}
		fdf = ft_init_fdf(&fdf);
		e = ft_init_env(&fdf, &draw);
		ft_setup(&e);
	}
	else
		ft_error(1);
	return (0);
}
