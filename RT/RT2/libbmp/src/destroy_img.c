/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 11:44:51 by agrosset          #+#    #+#             */
/*   Updated: 2016/08/23 16:16:41 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbmp.h"
#include <stdlib.h>

void	destroy_image(t_image *img)
{
	if (!img)
		return ;
	if (img->data)
		free(img->data);
	img->data = NULL;
	free(img);
}
