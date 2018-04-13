/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:08:55 by nbuhler           #+#    #+#             */
/*   Updated: 2017/02/03 19:08:57 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10000
# include "libft/includes/libft.h"

typedef	struct	s_gnl
{
	int			fd;
	char		*str;
}				t_gnl;

int				get_next_line(int fd, char **line);

#endif
