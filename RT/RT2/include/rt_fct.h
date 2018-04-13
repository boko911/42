/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_fct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 13:02:41 by agrosset          #+#    #+#             */
/*   Updated: 2018/04/02 15:01:38 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_FCT_H
# define RT_FCT_H

double			cone_inter(t_obj *obj, t_ray ray);
t_mtx			cone_normal(t_obj *obj, t_inter *inter, t_ray *ray);

double			cylinder_inter(t_obj *obj, t_ray ray);
t_mtx			cylinder_normal(t_obj *obj, t_inter *inter, t_ray *ray);

double			plane_inter(t_obj *obj, t_ray ray);
t_mtx			plane_normal(t_obj *obj, t_inter *inter, t_ray *ray);

double			sphere_inter(t_obj *obj, t_ray ray);
t_mtx			sphere_normal(t_obj *obj, t_inter *inter, t_ray *ray);

/*
** init/
*/

int				ft_init_camera(t_camera *camera);

t_env			*ft_init_env(void);

int				ft_init_img(t_env *env, t_img *img, int width, int height);

void			ft_init_lexrac(t_lex_fra *re_flefra);

void			ft_init_material(t_material *mat);

void			init_sphere(t_env *env, t_tobj *tobj, t_sphere *obj, int *i);
int				ft_alloc_sphere(t_sphere **obj, t_list **lst);
void			last_setup(t_sphere *obj);

void			ft_init_plane(t_env *env, t_tobj *tobj, t_plane *obj, int *i);
int				ft_delete_plane(t_list **lst, t_plane **obj);
int				ft_alloc_plane(t_plane **obj, t_list **lst);

void			ft_init_cylinder(t_env *env, t_tobj *tobj, t_cylinder *obj,
	int *i);
int				ft_delete_cylinder(t_list **lst, t_cylinder **obj);
int				ft_alloc_cylinder(t_cylinder **obj, t_list **lst);

int				ft_alloc_cone(t_cone **obj, t_list **lst);
int				ft_delete_cone(t_list **lst, t_cone **obj);

int				ft_delete_sphere(t_list **lst, t_sphere **obj);

int				ft_init_win(t_env *env);

int				ft_init_texture(t_texture **text, t_env *env);
int				ft_init_texture_p2(t_list **lst, t_texture *text);

/*
** parse/
*/

int				ft_random_shape_spe(t_env *env, char **line);
int				ft_random_shape(t_env *env, char **line);
char			*ft_israndom(char **str, int min, int max, int id);

int				ft_delete_line_array(char **line, int return_state);

int				ft_parse_args(t_env *env, int argc, char **argv);
int				ft_parse_file(t_env *env, char *file);

int				ft_parse_scene(t_env *env, char **line);
int				ft_parse_camera(t_env *env, char **line);
int				ft_parse_light(t_env *env, char **line);
int				ft_parse_image(t_env *env, char **line);
int				ft_parse_texture(t_env *env, char **line);
int				ft_parse_material(t_env *env, char **line);
int				ft_parse_cone(t_env *env, char **line);
int				ft_parse_cylinder(t_env *env, char **line);
int				ft_parse_plane(t_env *env, char **line);
int				ft_parse_sphere(t_env *env, char **line);
int				parse_filter(char **line, int *i, int *filter);

int				ft_random_mat(t_env *env, const char *id, t_material **mat);
int				check_filter(t_color *color, t_env *env);

t_material		*get_material(t_env *env, const char *id);

t_mtx			mtx_createscalemtx(double scalex, double scaley,
									double scalez);

int				parse_mtx_trans(char **line, int *i, t_mtx *v);
int				parse_mtx_rot(char **line, int *i, t_mtx *v);
int				parse_n(char **line, int *i, double *a, int id);
int				ft_parse_perturbation(char **line, int *i,
					t_color (**ft_perturbation)(t_phpa *, t_obj *));

int				parse_resolution(char **line, int *i, t_res *res);
int				parse_vector3(char **line, int *i, t_mtx *v);
int				parse_color(char **line, int *i, t_color *rgb);
int				parse_double(char **line, int *i, double *a, int id);
int				parse_int(char **line, int *i, int *a);
int				parse_shine(char **line, int *i, double *a, int id);

t_objenv		set_objenv(t_env *env, t_obj *obj, t_tobj *tobj);

void			transform_object(t_obj *obj, t_tobj *tobj);

/*
**	prog/
*/

void			add_to_queue(t_env *env, void (*method)(t_env *env));

void			ft_check_blindly(t_env *env, t_color *color);
int				ft_is_inscene(t_mtx light_pos, t_mtx cam_pos, t_mtx *beg_end);

void			destruct_env(t_env *env);
void			ft_exit(t_env *env, int i);
void			clean_scene(t_scene *scene);

t_mtx			mtx_createrotmtx(double rotx, double roty, double rotz);

t_mtx			norm_vect(t_mtx mtx);

void			print_usage(char *binary_name);

void			program(int argc, char **argv);

int				return_print(char *str, int return_state);

void			save_to_bmp(t_env *env);

void			set_vector(t_mtx *mtx, double x, double y, double z);

void			update_title(t_env *env);

/*
** render /
*/

char			aabb(t_ray *ray, t_obj *obj);

t_color			compute_color(t_env *env, t_ray *ray, t_lex_fra reflerefra);

t_color			compute_light(t_scene *scene, t_ray *ray);

char			find_closest(t_scene *scene, t_ray *ray);
char			find_closest_light(t_scene *scene, t_ray *ray,
	double *t_coef_refrac, t_obj *obj_closet);
char			find_closest_blindly(t_scene *scene, t_ray *ray, double t,
	double *coef_refrac);

double			dot_vect(t_mtx *vect1, t_mtx *vect2);

t_mtx			get_normal(t_ray ray);

t_ray			invert_ray(t_ray ray);

void			phong(t_phpa *ph);

double			ft_get_nuance(t_phpa *ph, t_obj *obj, char c, int a);

t_color			ft_perturbation_uni(t_phpa *ph, t_obj *obj);
t_color			ft_perturbation_random(t_phpa *ph, t_obj *obj);
t_color			ft_perturbation_half_rnd_two_color(t_phpa *ph, t_obj *obj);
t_color			ft_perturbation_colone_for_all(t_phpa *ph, t_obj *obj);
t_color			ft_perturbation_line_for_all(t_phpa *ph, t_obj *obj);
t_color			ft_perturbation_dam_for_all(t_phpa *ph, t_obj *obj);
t_color			ft_perturbation_colone(t_phpa *ph, t_obj *obj);
t_color			ft_perturbation_line(t_phpa *ph, t_obj *obj);
t_color			ft_perturbation_dam(t_phpa *ph, t_obj *obj);
t_color			ft_perturbation_sqare(t_phpa *ph, t_obj *obj);
t_color			ft_perturbation_a_trous(t_phpa *ph, t_obj *obj);

t_color			*ft_choose_by_two_coord(int x, int y,
					int *frequence, t_obj *obj);
t_color			*ft_choose_by_one_coord(int coord, int frequence, t_obj *obj);
t_perturbation	*get_perturbation(t_phpa *ph, t_obj *obj,
	t_color (*fct_call)(t_phpa *, t_obj *));

t_color			ft_texture_img(t_phpa *ph, t_obj *obj);
void			ft_spherical_mapping(t_fttexture *fttexture, t_obj *obj,
	t_phpa *ph, int *x_y);
void			ft_texture_plane(t_fttexture *fttexture, t_obj *obj,
	t_phpa *ph, int *x_y);

t_fttexture		*get_imgtext(t_phpa *ph, t_obj *obj);

void			*render_scene(void *arg);
t_mtx			get_inv_vect(t_mtx *mtx);

void			set_img_pixel(t_img *img, int x, int y, t_color color);

char			solve_quadratic(double *abc, double *t);

t_mtx			vect_reflect(t_mtx i, t_mtx n);
t_mtx			vect_refract(int *bol, t_mtx dir, t_mtx normal, double ior);

/*
** rgb/
*/

void			rgb_add(t_color *color, float r, float g, float b);
void			rgb_add_rgb(t_color *colora, t_color colorb);

void			rgb_clamp(t_color *color);
t_color			rgb_clamp_rgb(t_color c_src);

void			rgb_div(t_color *color, double n);

void			rgb_equal_rgb(t_color *color_dest, t_color *color_src);

void			rgb_mult(t_color *color, double mult);
t_color			rgb_mult_cpy(t_color color, double mult);

t_color			rgb_new(float r, float g, float b);

/*
** sdl/
*/

void			sdl_loop(t_env *env);
void			ft_lock_mult_thread (t_env *env);
void			ft_unlock_mult_thread (t_env *env);

/*
** unused/
*/

void			print_memory(const void *addr, size_t size);
double			find_dist(t_ray ray, t_obj *obj);
t_mtx			mtx_applyrot(t_mtx *mtx, double rotx, double roty,
				double rotz);
void			set_mlx_hooks(t_env *env);
int				expose_hook(t_env *env);
int				loop_hook(t_env *env);
int				key_hook(int keycode, t_env *env);
int				mouse_hook(int button, int x, int y, t_env *env);
void			translate_xml_to_char(char *file);
int				get_next_line_file(t_env *env, int fd);
void			parse_scene_arg(t_xml *xml, char *arg,
				xmlDocPtr doc, xmlNodePtr cur);
void			parse_scene(t_xml *xml, xmlDocPtr doc, xmlNodePtr cur);
void			parse_camera(t_xml *xml, xmlDocPtr doc, xmlNodePtr cur);
void			parse_shape(t_xml *xml, xmlDocPtr doc, xmlNodePtr cur);
void			parse_light(t_xml *xml, xmlDocPtr doc, xmlNodePtr cur);
void			parse_image(t_xml *xml, xmlDocPtr doc, xmlNodePtr cur);
void			parse_texture(t_xml *xml, xmlDocPtr doc, xmlNodePtr cur);
void			parse_material(t_xml *xml, xmlDocPtr doc, xmlNodePtr cur);
int				is_xml(char *argv);

#endif
