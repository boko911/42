/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_to_bmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 13:48:25 by agrosset          #+#    #+#             */
/*   Updated: 2016/09/06 15:16:03 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	fill_image(t_image *image, char *pixels)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = image->width * image->height * 4;
	while (i < image->width * image->height * 4)
	{
		set_pixel(image, ((j - i) / 4) % image->width,
			((j - i) / 4) / image->width,
			get_rgb(pixels[i + 2], pixels[i + 1], pixels[i]));
		i += 4;
	}
}

void		save_to_bmp(t_env *env)
{
	char	*pixels;
	t_image	*image;
	int		pitch;

	if (!env->outputname)
		return ;
	env->new_title = "rt @42 - Saving...";
	add_to_queue(env, update_title);
	pitch = env->bg_img.res.width * 4;
	if (!(image = create_image(env->bg_img.res.width, env->bg_img.res.height))
		|| !(pixels = ft_memalloc(image->width * image->height * 5)))
	{
		ft_putendl("malloc error");
		return ;
	}
	ft_putendl("Starting GPU mem copy");
	SDL_RenderReadPixels(env->bg_img.renderer, NULL,
		SDL_PIXELFORMAT_RGB888, pixels, pitch);
	ft_putendl("End of GPU mem copy");
	fill_image(image, pixels);
	free(pixels);
	env->new_title = "rt @42 - Saved!";
	if (save_to_bmp_24(env->outputname, image))
		env->new_title = "rt @42 - Save failed!";
	add_to_queue(env, update_title);
}
