/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 18:19:57 by nbuhler           #+#    #+#             */
/*   Updated: 2017/01/07 13:34:43 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		ft_error(char *str, int nbpart)
{
	int		toto;

	toto = 0;
	toto += ft_check_dot(str, nbpart);
	toto += ft_map_is_null(str);
	toto += ft_check_slash(str, nbpart);
	toto += ft_testchar(str);
	toto += ft_check_last_char(str);
	toto += ft_bsntest(bsnstr(str));
	return (toto);
}
