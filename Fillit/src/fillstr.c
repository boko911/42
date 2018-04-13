/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:55:25 by nbuhler           #+#    #+#             */
/*   Updated: 2017/01/03 20:29:54 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_strnew(size_t size)
{
	char	*str;

	str = ft_memalloc(size + 1);
	if (!str)
		return (NULL);
	ft_memset(str, (int)'\0', size);
	return (str);
}

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char		*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_realloc(char *str, size_t length)
{
	char	*newstr;

	newstr = ft_strnew(ft_strlen(str) + length + 1);
	ft_strcpy(newstr, str);
	return (newstr);
}

char		*ft_fill_str(int fd)
{
	char	buffer[2];
	char	*str;
	int		i;

	i = 0;
	while (read(fd, &buffer, 1) != 0)
	{
		buffer[1] = '\0';
		str = ft_realloc(str, ft_strlen(buffer));
		str[i] = buffer[0];
		i++;
	}
	return (str);
}
