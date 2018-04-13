/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 17:01:21 by agrosset          #+#    #+#             */
/*   Updated: 2018/04/04 14:27:25 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static Uint32	obtenir_pixel(SDL_Surface *surface, int x, int y)
{
	int		bpp;
	Uint8	*p;

	bpp = surface->format->BytesPerPixel;
	p = (Uint8 *)surface->pixels + (y * surface->pitch) + (x * bpp);
	if (bpp == 1)
		return (*p);
	if (bpp == 2)
		return (*(Uint16 *)p);
	if (bpp == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return (p[0] << 16 | p[1] << 8 | p[2]);
		else
			return (p[0] | p[1] << 8 | p[2] << 16);
	}
	if (bpp == 4)
		return (*(Uint32 *)p);
	return (0);
}

static void		ft_pixel_to_color(Uint32 pixel, SDL_Surface *surface,
	t_color *color)
{
	Uint8	rgba[4];
	int		int_nuance;

	SDL_GetRGBA(pixel, surface->format, &rgba[0], &rgba[1], &rgba[2], &rgba[3]);
	int_nuance = (int)rgba[0];
	color->r = (double)int_nuance / 255.0;
	int_nuance = (int)rgba[1];
	color->g = (double)int_nuance / 255.0;
	int_nuance = (int)rgba[2];
	color->b = (double)int_nuance / 255.0;
}

static void		set_pos_elerg(int *x_y, t_fttexture *imgtexture)
{
	SDL_Surface *surface;

	surface = imgtexture->texture->surface->surface;
	x_y[0] *= imgtexture->texture->elarge_x;
	x_y[1] *= -imgtexture->texture->elarge_y;
	while (x_y[0] < 0)
		x_y[0] += surface->h;
	while (x_y[1] < 0)
		x_y[1] += surface->w;
	x_y[0] = (x_y[0] + imgtexture->texture->begin_x) % surface->w;
	x_y[1] = (x_y[1] + imgtexture->texture->begin_y) % surface->h;
}

t_color			fct_getcolor_imgtext(t_fttexture *imgtexture, t_obj *obj,
	t_phpa *ph)
{
	t_color	color;
	int		x_y[2];
	Uint32	pixel;

	color = rgb_new(0, 0, 0);
	imgtexture->fct_getcolor_imgtext(imgtexture, obj, ph, x_y);
	set_pos_elerg(x_y, imgtexture);
	pixel = obtenir_pixel(imgtexture->texture->surface->surface,
		x_y[0], x_y[1]);
	ft_pixel_to_color(pixel, imgtexture->texture->surface->surface, &color);
	return (color);
}

t_color			ft_texture_img(t_phpa *ph, t_obj *obj)
{
	t_fttexture	*imgtexture;

	if ((imgtexture = get_imgtext(ph, obj)) == NULL)
		return (obj->mat->color1);
	return (fct_getcolor_imgtext(imgtexture, obj, ph));
}
