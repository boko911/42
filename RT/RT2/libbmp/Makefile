# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrosset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/22 10:37:14 by agrosset          #+#    #+#              #
#    Updated: 2016/08/23 16:18:08 by agrosset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libbmp.a
SRCFOLDER=src/
SRCFILES=create_img.c \
	  destroy_img.c \
	  get_closest_index_palette.c \
	  rgb.c \
	  save_to_bmp.c \
	  set_pixel.c
INCFOLDER=include/
INC=$(addprefix $(INCFOLDER),$(INCFILES))
OBJFOLDER=obj/
OBJ=$(addprefix $(OBJFOLDER),$(subst .c,.o,$(SRCFILES)))
SRC=$(addprefix $(SRCFOLDER),$(SRCFILES))
FLAGS=-Wall -Werror -Wextra

GREEN		=	\033[32m
RED			=	\033[31m
DEFAULT		=	\033[37m

.PHONY: all clean fclean re

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GREEN)$(NAME)$(DEFAULT) created."
	@echo "$(GREEN). $(DEFAULT)\c"

all: $(NAME)

$(OBJFOLDER)%.o: $(SRCFOLDER)%.c $(INC)
	@if ! [ -d "$(OBJFOLDER)" ]; then mkdir $(OBJFOLDER); fi
	@gcc -I $(INCFOLDER) -c $(FLAGS) $< -o $@
	@echo "$(GREEN). $(DEFAULT)\c"

clean:
	@rm -rf $(OBJFOLDER)
	@echo "$(RED).o $(DEFAULT) are now deleted for $(NAME)."

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME)$(DEFAULT) is now deleted."

re: fclean all
