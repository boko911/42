# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/25 12:44:37 by agrosset          #+#    #+#              #
#    Updated: 2018/02/14 14:32:54 by acoudray         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#OUT=LINUX
OUT=MAC
NAME=rt
SRCFOLDER= srcs/

INTERFACEFOLDER = interface/
INTER = $(INTERFACEFOLDER)interface_RT

SRCFILES= \
		cone.c \
		cylinder.c \
		plane.c \
		sphere.c \
		\
		ft_init_camera.c \
		ft_init_cone.c \
		ft_init_cylinder.c \
		ft_init_env.c \
		ft_init_img.c \
		ft_init_lexrac.c \
		ft_init_material.c \
		ft_init_plane.c \
		ft_init_sphere.c \
		ft_init_texture.c \
		ft_init_win.c \
		\
		ft_parse_args.c \
		ft_parse_file.c \
		ft_parse_file2.c\
		ft_parse_scene.c \
		ft_parse_camera.c \
		ft_parse_light.c \
		ft_parse_perturbation.c \
		ft_parse_image.c \
		ft_parse_texture.c \
		ft_parse_material.c \
		ft_parse_cone.c \
		ft_parse_cylinder.c \
		ft_parse_plane.c \
		ft_parse_sphere.c \
		parse_helper.c \
		parse_helper_2.c \
		\
		ft_check_filters.c \
		get_material.c \
		mtx_createscalemtx.c \
		set_objenv.c \
		transform_object.c \
		ft_israndom.c \
		ft_random_mat.c \
		ft_random_shape.c \
		\
		add_to_queue.c \
		destruct_env.c \
		clean_scene.c \
		main.c \
		mtx_createrotmtx.c \
		norm_vect.c \
		print_usage.c \
		program.c \
		return_print.c \
		save_to_bmp.c \
		set_vector.c \
		update_title.c \
		\
		aabb.c \
		get_inv_vect.c \
		compute_color.c \
		compute_light.c \
		dot_vect.c \
		find_closest.c \
		get_normal.c \
		invert_ray.c \
		phong.c \
		ft_get_nuance.c \
		\
		perturbation_helper.c \
		perturbation_helper2.c \
		perturbation.c \
		perturbation2.c \
		perturbation3.c \
		perturbation4.c \
		\
		texture_helper.c \
		texture_obj.c \
		texture.c \
		\
		ft_check_blindly.c \
		ft_check_blindly_p2.c \
		render_scene.c \
		set_img_pixel.c \
		solve_quadratic.c \
		vect_reflect.c \
		\
		rgb_equal_rgb.c \
		rgb_add.c \
		rgb_clamp.c \
		rgb_clamp_rgb.c \
		rgb_div.c \
		rgb_mult.c \
		rgb_new.c \
		\
		sdl_loop.c \
		lock_mult_thread.c\
		xml.c\
		xml2.c\
		xml3.c\
		xml4.c

INCFOLDER=./include/
INCFILES=keycodes.h \
		 quadric_shortcuts.h \
		 rt.h rt_class.h rt_fct.h
INC=$(addprefix $(INCFOLDER),$(INCFILES))

OBJFOLDER=obj/
OBJ=$(addprefix $(OBJFOLDER),$(subst .c,.o,$(SRCFILES)))
SRC=$(addprefix $(SRCFOLDER),$(SRCFILES))

LIBBMPFOLDER=./libbmp
LIBBMP=$(LIBBMPFOLDER)/libbmp.a

LIBFTFOLDER=./libft
LIBFT=$(LIBFTFOLDER)/libft.a

INTERFACEFOLDER = ./interface
INTER=interface_RT

LIBMTXFOLDER=./libmtx
LIBMTX=$(LIBMTXFOLDER)/libmtx.a

LIBSDLFOLDER=./SDL2-2.0.4
EFLAGS=-Wall -Werror -Wextra -g
IFLAGS=-I$(LIBFTFOLDER) -I$(LIBMTXFOLDER)/include \
		 -I$(LIBBMPFOLDER)/include -I$(INCFOLDER)

PKGCONFIG = $(shell which pkg-config)
CFLAGS2 = $(shell $(PKGCONFIG) --cflags libxml-2.0)
LIBS = $(shell $(PKGCONFIG) --libs libxml-2.0)

ifeq ($(OUT),MAC)
  IFLAGS+= -I./SDL2.framework/Headers
  LFLAGS=-L$(LIBFTFOLDER) -lft -L$(LIBMTXFOLDER) -lmtx -L$(LIBBMPFOLDER)\
		 -lbmp -lpthread -L./SDL2.framework/Versions/Current -F. \
		 -framework SDL2 -framework Cocoa
  EDITLIB=install_name_tool \
  		 -change @executable_path/../Frameworks/SDL2.framework/SDL2 \
		 @executable_path/SDL2.framework/SDL2 $(NAME)\
		 && install_name_tool -change @rpath/SDL2.framework/Versions/A/SDL2 \
		 @executable_path/SDL2.framework/SDL2 $(NAME)
else
  PATHSOSDL=-Wl,-R`pwd`/$(LIBSDLFOLDER)/build/.libs
  IFLAGS+= -I$(LIBSDLFOLDER)/include
  LFLAGS=-L$(LIBFTFOLDER) -lft -L$(LIBMTXFOLDER) -lmtx -L$(LIBBMPFOLDER) \
  		 -lbmp -lm -lpthread $(PATHSOSDL) -L`pwd`/$(LIBSDLFOLDER)/build/.libs -lSDL2
  DYNSDL=libSDL2-2.0.so.0
endif
CFLAGS=-D $(OUT)

GREEN		=	\033[32m
RED			=	\033[31m
DEFAULT		=	\033[37m

.PHONY: all clean fclean re

$(NAME): $(LIBFT) $(LIBMTX) $(LIBBMP) $(INTER) $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LIBS) $(PARSE) $(SDL) $(LFLAGS)
	@echo "$(GREEN)$(NAME)$(DEFAULT) created."
	@$(EDITLIB)

all: $(NAME)


$(OBJFOLDER)%.o: $(SRCFOLDER)%.c $(INC)
	@if ! [ -d "$(OBJFOLDER)" ]; then mkdir $(OBJFOLDER); fi
	@gcc $(CFLAGS) -c $< $(EFLAGS) $(IFLAGS) -o $@ $(CFLAGS2)
	@echo "$(GREEN). $(DEFAULT)\c"

$(LIBFT):
	@make -C $(LIBFTFOLDER) all

$(LIBMTX):
	@make -C $(LIBMTXFOLDER) all

$(LIBBMP):
	@make -C $(LIBBMPFOLDER) all

$(INTER):
	@make -C $(INTERFACEFOLDER) all

clean:
	@rm -rf $(OBJFOLDER)
	@make -C $(INTERFACEFOLDER) fclean
	@make -C $(LIBFTFOLDER) fclean
	@make -C $(LIBMTXFOLDER) fclean
	@make -C $(LIBBMPFOLDER) fclean
	@echo "$(RED).o $(DEFAULT) are now deleted for $(NAME)."

fclean:
	@rm -rf $(OBJFOLDER)
	@make -C $(INTERFACEFOLDER) fclean
	@make -C $(LIBFTFOLDER) fclean
	@make -C $(LIBMTXFOLDER) fclean
	@make -C $(LIBBMPFOLDER) fclean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME)$(DEFAULT) is now deleted for $(NAME)."

re: fclean all
