/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_class.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 13:02:41 by agrosset          #+#    #+#             */
/*   Updated: 2018/02/14 14:34:59 by acoudray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_CLASS_H
# define RT_CLASS_H

typedef struct			s_color
{
	float				r;
	float				g;
	float				b;
}						t_color;

typedef struct			s_xml
{
	char				*scene;
}						t_xml;

typedef struct			s_lex_fra
{
	int					nb_reflex;
	int					nb_refrac;
	double				coef_reflex;
	double				coef_refrac;
	t_mtx				normal;
}						t_lex_fra;

typedef struct			s_refract
{
	double				cosi;
	double				etai;
	double				etat;
	t_mtx				n;
	double				eta;
	double				k;
	double				a;
}						t_refract;

typedef struct			s_surface
{
	SDL_Surface			*surface;
	char				*name;
}						t_surface;

typedef struct			s_texture
{
	t_surface			*surface;
	char				*name;
	int					begin_x;
	int					begin_y;
	double				elarge_x;
	double				elarge_y;
}						t_texture;

typedef struct			s_inter
{
	double				t;
	t_mtx				pos;
}						t_inter;

typedef struct			s_tobj
{
	t_mtx				rot;
	t_mtx				trans;
	t_mtx				scale;
	t_mtx				ftrans;
	t_mtx				i_rot;
	t_mtx				i_trans;
	t_mtx				i_scale;
	t_mtx				i_ftrans;
}						t_tobj;

typedef struct			s_ray
{
	t_mtx				dir;
	t_mtx				invdir;
	t_mtx				pos;
	struct s_obj		*obj_closest;
	double				t;
	double				pene;
}						t_ray;

typedef struct			s_obj
{
	double				(*inter)(struct s_obj *obj, t_ray ray);
	t_mtx				(*normal)(struct s_obj *obj,
		t_inter *inter, t_ray *ray);
	t_mtx				aabb[2];
	t_tobj				trans;
	struct s_material	*mat;
}						t_obj;

typedef struct			s_res
{
	int					width;
	int					height;
}						t_res;

typedef struct			s_camera
{
	t_mtx				dir;
	t_mtx				pos;
	t_mtx				x_indent;
	t_mtx				y_indent;
	t_mtx				vp_up_left;
	double				vp_width;
	double				vp_height;
	double				vp_dist;
	double				rotx;
	double				roty;
	double				rotz;
	double				fov;
	int					antialiasing;
	t_res				res;
}						t_camera;

typedef struct			s_light
{
	t_color				color;
	t_mtx				pos;
	double				power;
}						t_light;

typedef struct			s_phpa
{
	t_ray				*lray;
	t_ray				*ray;
	t_color				*color;
	t_color				*specular;
	t_color				*diffuse;
	t_light				*light;
	t_camera			*camera;
	t_mtx				normal;
	double				coef_refrac;
	int					x;
	int					y;
	t_list				*perturbation;
	t_list				*texture;
	t_list				*fttexture;
}						t_phpa;

typedef struct			s_fttexture
{
	t_obj				*obj;
	t_texture			*texture;
	void				(*fct_getcolor_imgtext)(struct s_fttexture *fttexture,
		t_obj *obj, t_phpa *ph, int *x_y);
}						t_fttexture;

typedef struct			s_perturbation
{
	t_obj				*obj;
	t_color				(* fct_call)(t_phpa *phpa, t_obj *obj);
	int					frequence[2];
}						t_perturbation;

typedef struct			s_material
{
	char				*name;
	double				shine;
	double				k_ambiant;
	double				k_spec;
	double				k_diffuse;
	double				refle;
	double				refra;
	double				k_opacity;
	double				n;
	t_color				color1;
	t_color				color2;
	t_color				(* ft_perturbation)(t_phpa *phpa, t_obj *obj);
	char				*texture;
}						t_material;

typedef struct			s_sphere
{
	double				(*inter)(t_obj *objet, t_ray ray);
	t_mtx				(*normal)(t_obj *obj, t_inter *inter, t_ray *ray);
	t_mtx				aabb[2];
	t_tobj				trans;
	t_material			*mat;
	double				radius;
	double				h1;
	double				h2;
}						t_sphere;

typedef struct			s_cylinder
{
	double				(*inter)(t_obj *objet, t_ray ray);
	t_mtx				(*normal)(t_obj *obj, t_inter *inter, t_ray *ray);
	t_mtx				aabb[2];
	t_tobj				trans;
	t_material			*mat;
	double				radius;
	double				h;
}						t_cylinder;

typedef struct			s_cone
{
	double				(*inter)(t_obj *objet, t_ray ray);
	t_mtx				(*normal)(t_obj *obj, t_inter *inter, t_ray *ray);
	t_mtx				aabb[2];
	t_tobj				trans;
	t_material			*mat;
	double				angle;
	double				h1;
	double				h2;
}						t_cone;

typedef struct			s_plane
{
	double				(*inter)(t_obj *objet, t_ray ray);
	t_mtx				(*normal)(t_obj *obj, t_inter *inter, t_ray *ray);
	t_mtx				aabb[2];
	t_tobj				trans;
	t_material			*mat;
}						t_plane;

typedef struct			s_scene
{
	t_list				*objects;
	t_list				*lights;
	t_list				*materials;
	t_camera			*camera;
	t_color				bgcolor;
	t_color				i_ambiant;
	double				ambbaseimpact;
	double				ambcoefimpact;
	int					max_ref;
	int					filter;
	t_ray				cam_ray;
	int					blind;
	int					x;
	int					y;
	t_phpa				ph;
	t_list				*surface;
	t_list				*texture;
}						t_scene;

typedef struct			s_img
{
	SDL_Texture			*img;
	SDL_Renderer		*renderer;
	pthread_mutex_t		mutex;
	t_res				res;
}						t_img;

typedef struct			s_audiodata
{
	Uint8				*pos;
	Uint32				lenght;
}						t_audiodata;

typedef struct			s_env
{
	SDL_Window			*win;
	SDL_Renderer		*renderer;
	t_img				bg_img;
	char				loop;
	int					n_threads;
	int					real_n_threads;
	char				print_time;
	char				*new_title;
	unsigned int		processed_pixels;
	struct timeval		clocks[2];
	pthread_t			*threads;
	pthread_t			clockthread;
	pthread_mutex_t		mutex;
	t_scene				*scene;
	t_material			base_material;
	char				*outputname;
	t_list				*queue;
	pthread_mutex_t		queuemutex;
	int					play_sound;
	int					finish;
	int					width;
	int					height;
	SDL_AudioDeviceID	device;
	SDL_AudioSpec		wavspec;
	Uint8				*wavstart;
	Uint32				wavlenght;
	t_audiodata			audio;

}						t_env;

typedef struct			s_objenv
{
	t_env				*env;
	t_tobj				*tobj;
	t_obj				*obj;
}						t_objenv;

#endif
