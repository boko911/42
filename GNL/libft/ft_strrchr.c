/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:17:49 by nbuhler           #+#    #+#             */
/*   Updated: 2016/11/16 15:17:50 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s;

	s = (char *)str;
	s = s + ft_strlen(str);
	while (*s != (char)c && s != str)
		s--;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
