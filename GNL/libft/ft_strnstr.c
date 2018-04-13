/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:37:25 by nbuhler           #+#    #+#             */
/*   Updated: 2016/11/16 13:37:28 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (ft_strlen((char *)s2) == 0)
		return ((char *)s1);
	if (ft_strlen((char *)s1) == 0)
		return (NULL);
	while (s1[i] && i < n)
	{
		j = 0;
		while (s2[j] == s1[i + j] && (i + j) < n)
		{
			if (s2[j + 1] == '\0' && ((size_t)ft_strlen((char *)s2)) <= n)
				return (&((char*)s1)[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
