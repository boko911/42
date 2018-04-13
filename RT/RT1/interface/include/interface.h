/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 06:49:45 by nbuhler           #+#    #+#             */
/*   Updated: 2018/02/02 06:49:47 by nbuhler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

# include <gtk/gtk.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

typedef	struct		s_scene
{
	FILE			*fichier;
	gdouble			thread;
	gchar			*thread_text;
	gchar			*path;
	int				sound;
	int				bmp;
	int				count_light;
	int				count_shape;
	int				count_mat;
	int				count_img;
	int				count_texture;
	int				with_texture;
	char			*commandline;
	const gchar		*width;
	const gchar		*height;
	const gchar		*pos_x_cam;
	const gchar		*pos_y_cam;
	const gchar		*pos_z_cam;
	const gchar		*rot_x_cam;
	const gchar		*rot_y_cam;
	const gchar		*rot_z_cam;
	const gchar		*fov;
	const gchar		*antialiasing;
	const gchar		*filtre;
	const gchar		*color_r;
	const gchar		*color_g;
	const gchar		*color_b;
	const gchar		*scene_ambiant;
	const gchar		*base_impact_ambiant;
	const gchar		*coef_impact_ambiant;
	const gchar		*max_reflexion;
	char			*text_cam;
	gchar			*text_background;
	const gchar		*pos_x_light;
	const gchar		*pos_y_light;
	const gchar		*pos_z_light;
	const gchar		*color_r_light;
	const gchar		*color_g_light;
	const gchar		*color_b_light;
	const gchar		*intensity;
	gchar			*text_color_light;
	char			*text_light;
	const gchar		*shape;
	const gchar		*pos_x_shape;
	const gchar		*pos_y_shape;
	const gchar		*pos_z_shape;
	const gchar		*rot_x_shape;
	const gchar		*rot_y_shape;
	const gchar		*rot_z_shape;
	const gchar		*radius;
	const gchar		*color_r_shape;
	const gchar		*color_g_shape;
	const gchar		*color_b_shape;
	const gchar		*color2_r_shape;
	const gchar		*color2_g_shape;
	const gchar		*color2_b_shape;
	const gchar		*perturbation;
	const gchar		*texture_mat;
	const gchar		*ambiant;
	const gchar		*diffuse;
	const gchar		*specular;
	const gchar		*shininess;
	const gchar		*reflexion;
	const gchar		*refraction1;
	const gchar		*refraction2;
	const gchar		*filename;
	const gchar		*mat_name;
	const gchar		*material;
	const gchar		*l_cre_img;
	const gchar		*path_img;
	const gchar		*img_id;
	const gchar		*texture_id;
	const gchar		*texture;
	const gchar		*elarge1;
	const gchar		*elarge2;
	const gchar		*begin1;
	const gchar		*begin2;
	gchar			*text_color_shape;
	gchar			*text_color2_shape;
	char			*text_shape;
	char			*text_material;
	char			*text_image;
	char			*text_texture;
}					t_scene;

typedef struct		s_widgets
{
	char			*command;
	GtkBuilder		*builder;
	GtkWidget		*w_1;
	GtkWidget		*btn_ch_file;
	GtkWidget		*btn_quit;
	GtkWidget		*btn_cre_file;
	GtkWidget		*btn_exe_rt;
	GtkWidget		*btn_thread;
	GtkWidget		*btn_bmp;
	GtkWidget		*btn_sound;
	GtkWidget		*box_option;
	GtkAdjustment	*adjustement;
	GtkWidget		*w_2;
	GtkWidget		*l_reso;
	GtkWidget		*e_width;
	GtkWidget		*e_height;
	GtkWidget		*l_pos;
	GtkWidget		*e_pos_x_c;
	GtkWidget		*e_pos_y_c;
	GtkWidget		*e_pos_z_c;
	GtkWidget		*l_rot;
	GtkWidget		*e_rot_x_c;
	GtkWidget		*e_rot_y_c;
	GtkWidget		*e_rot_z_c;
	GtkWidget		*l_fov;
	GtkWidget		*e_fov;
	GtkWidget		*l_anti;
	GtkWidget		*e_anti;
	GtkWidget		*box_filtre;
	GtkWidget		*l_back;
	GtkWidget		*back_color_c;
	GdkRGBA			color;
	GtkWidget		*l_s_ambiant;
	GtkWidget		*e_s_ambiant;
	GtkWidget		*l_b_ambiant;
	GtkWidget		*e_b_ambiant;
	GtkWidget		*l_c_ambiant;
	GtkWidget		*e_c_ambiant;
	GtkWidget		*l_max_r;
	GtkWidget		*e_max_r;
	GtkWidget		*btn_add_c;
	GtkWidget		*btn_add_sl;
	GtkWidget		*w_3;
	GtkWidget		*l_pos_l;
	GtkWidget		*e_pos_x_l;
	GtkWidget		*e_pos_y_l;
	GtkWidget		*e_pos_z_l;
	GtkWidget		*l_color_l;
	GtkWidget		*btn_color_l;
	GtkWidget		*btn_add_l;
	GtkWidget		*btn_add_f;
	GtkWidget		*l_intensity;
	GtkWidget		*e_intensity;
	GtkWidget		*l_add_s;
	GdkRGBA			color2;
	GtkWidget		*w_4;
	GtkWidget		*l_shape;
	GtkWidget		*box_s_s;
	GtkWidget		*l_pos_s;
	GtkWidget		*e_pos_x_s;
	GtkWidget		*e_pos_y_s;
	GtkWidget		*e_pos_z_s;
	GtkWidget		*l_rot_s;
	GtkWidget		*e_rot_x_s;
	GtkWidget		*e_rot_y_s;
	GtkWidget		*e_rot_z_s;
	GtkWidget		*l_radius_s;
	GtkWidget		*e_radius_s;
	GtkWidget		*l_color_s;
	GtkWidget		*ch_color_s;
	GtkWidget		*ch_color2_s;
	GtkWidget		*box_perturbation;
	GtkWidget		*box_texture_mat;
	GtkWidget		*l_ambiant;
	GtkWidget		*e_ambiant;
	GtkWidget		*l_diffuse;
	GtkWidget		*e_diffuse;
	GtkWidget		*l_specular;
	GtkWidget		*e_specular;
	GtkWidget		*l_shininess;
	GtkWidget		*e_shininess;
	GtkWidget		*l_reflexion;
	GtkWidget		*e_reflexion;
	GtkWidget		*l_refraction;
	GtkWidget		*e_refraction1;
	GtkWidget		*e_refraction2;
	GtkWidget		*l_cre_img;
	GtkWidget		*l_load_image;
	GtkWidget		*ch_image;
	GtkWidget		*l_imgid;
	GtkWidget		*e_imgid;
	GtkWidget		*btn_add_img;
	GtkWidget		*g_cre_txt;
	GtkWidget		*l_texture_id;
	GtkWidget		*e_textureid;
	GtkWidget		*l_texture_img;
	GtkWidget		*box_texture;
	GtkWidget		*l_elarge;
	GtkWidget		*e_elarge1;
	GtkWidget		*e_elarge2;
	GtkWidget		*l_begin;
	GtkWidget		*e_begin1;
	GtkWidget		*e_begin2;
	GtkWidget		*btn_add_txt;
	GtkWidget		*l_save;
	GtkWidget		*l_cre_mat;
	GtkWidget		*l_add_f;
	GtkWidget		*e_filename;
	GtkWidget		*btn_add_s;
	GtkWidget		*btn_save_file;
	GtkWidget		*g_save_file;
	GtkWidget		*g_cre_mat;
	GtkWidget		*btn_cre_m;
	GtkWidget		*box_material;
	GtkWidget		*l_name_m;
	GtkWidget		*btn_ok_mat;
	GtkWidget		*e_name_mat;
	GtkWidget		*trash;
	GdkRGBA			color3;
	GdkRGBA			color4;

	t_scene			scene;
}					t_widgets;

size_t				ft_strlen(char *str);
char				*ft_strcpy(char *dest, char *src);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
char				*ft_strcat(char *dest, char *src);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strdup(const char *s1);
char				*ft_itoa(int n);
int					ft_isint(char *str);
void				connect_widgets_window_5(t_widgets *widgets);
void				connect_widgets_window_4(t_widgets *widgets);
void				connect_widgets_window_2(t_widgets *widgets);
void				connect_widgets_window_1(t_widgets *widgets);
void				connect_widgets(t_widgets *widgets);
void				get_input_cam(t_widgets *widgets);
int					check_input_cam(t_widgets *widgets);
void				save_text_cam(t_widgets *widgets);
void				get_input_light(t_widgets *widgets);
int					check_input_light(t_widgets *widgets);
char				*save_text_light(t_widgets *widgets);
void				get_input_shape(t_widgets *widgets);
void				get_input_image(t_widgets *widgets);
void				get_input_texture(t_widgets *widgets);
int					check_input_shape(t_widgets *widgets);
void				get_material(t_widgets *widgets);
void				get_shape(t_widgets *widgets);
void				get_info_exec(t_widgets *widgets);
void				hide_widget_shape(t_widgets *widgets);
void				show_widget_shape(t_widgets *widgets);
int					check_input_mat(t_widgets *widgets);
int					check_input_texture(t_widgets *widgets);
void				get_input_mat(t_widgets *widgets);
int					check_screen(t_widgets *widgets);
int					check_pos_cam(t_widgets *widgets);
int					check_rot_cam(t_widgets *widgets);
int					check_fov(t_widgets *widgets);
int					check_antialiasing(t_widgets *widgets);
char				*mult_strjoin(t_widgets *widgets);
int					check_ambiant_mat(t_widgets *widgets);
int					check_diffuse_mat(t_widgets *widgets);
int					check_specular_mat(t_widgets *widgets);
int					check_shininess_mat(t_widgets *widgets);
int					check_reflexion_mat(t_widgets *widgets);
char				*shape_1(char *text_original, t_widgets *widgets);
void				reinitialize_entries(t_widgets *widgets);
void				reinitialize_entries_light(t_widgets *widgets);
void				reinitialize_entries_cam(t_widgets *widgets);
void				reinitialize_entries_mat(t_widgets *widgets);
void				get_color_mat(t_widgets *widgets);
void				get_color2_mat(t_widgets *widgets);
void				get_input_image(t_widgets *widgets);
int					check_input_image(t_widgets *widgets);
void				show_widget_txt(t_widgets *widgets);
void				hide_widget_txt(t_widgets *widgets);
char				*mult_strjoin_image(t_widgets *widgets);
char				*mult_strjoin_texture(t_widgets *widgets);
void				reinitialize_entries_img(t_widgets *widgets);
char				*is_texture(char *text, t_widgets *widgets);
void				set_empty_char(t_widgets *widgets);

#endif
