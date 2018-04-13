/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 13:06:07 by nbuhler           #+#    #+#             */
/*   Updated: 2017/04/28 13:06:10 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "libft/includes/libft.h"

# define PTR_MOTION_MASK (1L<<6)
# define MOTION_NOTIFY 6

typedef struct	s_fractal
{
	long double x1;
	long double x2;
	long double y1;
	long double y2;
	long double zr;
	long double zi;
	long double cr;
	long double ci;
	long double tmp;
}				t_fractal;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*pxl;
	int			width;
	int			height;
	int			bpp;
	int			s_line;
	int			ed;
	int			ite_max;
	long double	z;
	long double	x;
	long double	y;
	int			mouse_x;
	int			mouse_y;
	int			color;
	int			type;
	int			mouse;
	int			menu;
	t_fractal	*fractal;
}				t_env;

void			ft_enadisa_mouse(t_env *e);
void			ft_center_plan(t_env *e);
void			ft_check_argv(const char *str);
void			ft_init_fractal_mandelbrot(t_env *e);
void			put_pxl(t_env *e, int x, int y, unsigned int c);
int				ft_draw_cal_m(t_env *e, long double cr, long double ci);
int				ft_draw_cal_bship(t_env *e, long double cr, long double ci);
void			ft_draw_m(t_env *e);
void			ft_init_fractal_julia(t_env *e);
int				ft_draw_cal_j(t_env *e, long double zr, long double zi);
void			ft_draw_j(t_env *e);
int				mouse_move_hook(int x, int y, t_env *e);
void			ft_check_mouse(t_env *e);
int				mouse_click_hook(int k, int x, int y, t_env *e);
void			ft_refresh(t_env *e);
void			ft_reset(t_env *e);
t_env			ft_init_env(t_env *e);
void			ft_setup(t_env *e);
void			ft_move(t_env *e, int k);
void			ft_change_color(t_env *e, int k);
void			ft_deepness(t_env *e, int k);
int				my_key_funct(int k, t_env *e);
void			ft_display_menu(t_env *e);
void			ft_zoom_in(t_env *e);
void			ft_zoom_out(t_env *e);
void			ft_menu(t_env *e);
void			ft_error(int error);

#endif
