# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggane <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/04 11:16:35 by ggane             #+#    #+#              #
#    Updated: 2017/11/25 01:47:52 by ggane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf
SRC= src/check_errors.c \
	 src/check_errors_utils.c \
	 src/check_lines_nb.c \
	 src/draw_lines.c \
	 src/isometric_projection.c \
	 src/zoom.c \
	 src/display_mode.c \
	 src/window.c \
	 src/key_events.c \
	 src/function_pointers.c \
	 src/line_management.c \
	 src/file_manipulation_utils.c \
	 src/data_structure.c \
	 src/map_coordinates.c \
	 src/type_conversion_utils.c \
	 src/delete_utils.c \
	 src/print_utils.c \
	 src/comparison_utils.c \
	 src/main.c
CC= gcc
CFLAGS= -Wall -Werror -Wextra
OBJ= $(SRC:.c=.o)
LIBFT= libft
INC= inc

ifeq ($(shell uname), Linux)
    INC_OS= inc_linux
    MLX= mlx_linux
    MLXFLAGS= -lXext -lX11
else
    INC_OS= inc_osx
    MLX= mlx_osx
    MLXFLAGS= -framework OpenGL -framework Appkit
endif

all: $(NAME)

$(NAME): $(OBJ)
		@make -s -C $(LIBFT) -j 8
		@echo "compilation $(LIBFT)"
		@make -s -C $(MLX) -j 8
		@echo "compilation $(MLX)"
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L $(LIBFT)/ -lft -L $(MLX)/ -lmlx $(MLXFLAGS)
		@echo "compilation $(NAME)"

%.o: %.c
		@$(CC) $(CFLAGS) -I $(INC_OS) -I $(INC) $< -c -o $@
clean:
		@make -s -C $(LIBFT)/ clean
		@echo "$(LIBFT) cleaned"
		@make -s -C $(MLX)/ clean
		@echo "$(MLX) cleaned"
		@rm -f $(OBJ)
		@echo ".obj files deleted"

fclean: clean
		@make -s -C $(LIBFT)/ fclean
		@rm -f $(NAME)
		@echo "$(NAME) deleted"

re: fclean all
