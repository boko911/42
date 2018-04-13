/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 00:23:48 by nbuhler           #+#    #+#             */
/*   Updated: 2018/04/02 16:03:32 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

size_t			ft_strlen(char *str)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char			*ft_strcpy(char *dest, char *src)
{
	size_t		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char			*ft_strnew(size_t size)
{
	char		*str;

	if (!(str = (char*)ft_memalloc(size + 1)))
		exit(-1);
	if (!str)
		return (NULL);
	ft_memset(str, (int)'\0', size + 1);
	return (str);
}

char			*ft_strcat(char *dest, char *src)
{
	size_t		len;
	int			i;

	len = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}

char			*ft_strjoin(char *s1, char *s2)
{
	char		*str;

	if (!s1 || !s2)
		return (NULL);
	str = ft_strnew((ft_strlen(s1) + ft_strlen(s2)));
	if (!str)
		return (NULL);
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	return (str);
}
