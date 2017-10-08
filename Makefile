# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggane <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/04 11:16:35 by ggane             #+#    #+#              #
#    Updated: 2017/10/08 15:31:52 by ggane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf
SRC= src/errors.c \
	 src/check00.c \
	 src/check01.c \
	 src/fd_basic_functions.c \
	 src/3d_map_coordinates.c \
	 src/isometric_projection.c \
	 src/image_management.c \
	 src/window_display.c \
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
		make -C $(LIBFT) -j 8
		make -C $(MLX) -j 8
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L $(LIBFT)/ -lft -L $(MLX)/ -lmlx $(MLXFLAGS)

%.o: %.c
		$(CC) $(CFLAGS) -I $(INC_OS) -I $(INC) $< -c -o $@
clean:
		make -C $(LIBFT)/ clean
		make -C $(MLX)/ clean
		rm -f $(OBJ)

fclean: clean
		make -C $(LIBFT)/ fclean
		rm -f $(NAME)

re: fclean all
