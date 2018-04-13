/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 14:13:02 by nbuhler           #+#    #+#             */
/*   Updated: 2017/04/17 14:13:05 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "libft/includes/libft.h"

typedef struct		s_data
{
	int				x;
	int				y;
	int				*z;
	struct s_data	*next;
}					t_data;

typedef	struct		s_draw
{
	int				decalx;
	int				decaly;
	int				xoffset;
	int				yt;
	int				xi;
	int				xf;
	int				yi;
	int				yf;
	int				w_t;
	int				h_t;
	int				xmin;
	int				xmax;
	int				dx;
	int				xinc;
	int				ymin;
	int				ymax;
	int				dy;
	int				yinc;
	int				z;
	t_data			*data;
	t_data			*tmp;
}					t_draw;

typedef	struct		s_fdf
{
	int				width;
	int				height;
	void			*mlx;
	void			*win;
	int				menu;
	int				color;
}					t_fdf;

typedef	struct		s_env
{
	t_fdf			*fdf;
	t_draw			*draw;
	int				keycode;
}					t_env;

int					ft_check_input(const char **argv);
void				ft_fill_list(t_data **data, char **tab, int x, int y);
int					ft_find_xf(t_data *data);
int					ft_find_yf(t_data *data);
int					ft_nb_element(char *str, char c);
void				ft_parsing(int fd, t_data **data);
void				ft_trace_dxsup(t_fdf *fdf, t_draw *draw);
void				ft_trace_dysup(t_fdf *fdf, t_draw *draw);
void				ft_put_pixel(t_fdf *fdf, t_draw *draw);
void				ft_draw_lines(t_fdf *fdf, t_draw *draw, int i);
void				ft_draw(t_env *e);
t_fdf				ft_init_fdf(t_fdf *fdf);
t_draw				ft_init_draw(t_data *data);
t_env				ft_init_env(t_fdf *fdf, t_draw *draw);
void				ft_cal_tuile(t_fdf *fdf, t_draw *draw);
void				ft_center_plan(t_fdf *fdf, t_draw *draw);
void				ft_calcul(t_env *e);
int					my_key_funct(int keycode, t_env *e);
void				ft_move(int x, int y, int z, t_env *e);
void				ft_refresh(t_env *e);
void				change_color(int keycode, t_env *e);
void				zoom(int keycode, t_env *e);
void				ft_setup(t_env *e);
void				ft_menu_1(t_fdf *fdf);
void				ft_menu_2(t_fdf *fdf);
void				ft_error(int nb);
void				ft_check_tab(char **tab);

#endif
