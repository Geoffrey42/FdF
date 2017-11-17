# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggane <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/08 17:29:33 by ggane             #+#    #+#              #
#    Updated: 2017/11/17 16:01:19 by ggane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= test03
SRC= launcher.c \
	../../src/isometric_projection.c \
	../../src/line_management.c \
	../../src/zoom.c \
	../../src/delete_utils.c \
	../../src/check_errors_utils.c \
	../../src/data_structure.c
OBJ= $(SRC:.c=.o)
CC= gcc
INC= ../../inc
LIBFT= ../../libft

ifeq ($(shell uname), Linux)
    INC_OS= ../../inc_linux
    MLX= ../../mlx_linux
    MLXFLAGS= -lXext -lX11
else
    INC_OS= ../../inc_osx
    MLX= ../../mlx_osx
    MLXFLAGS= -framework OpenGL -framework Appkit
endif

all: $(NAME)

$(NAME): $(OBJ)
		@make -C $(LIBFT) -j 8
		@$(CC) $(OBJ) -o $(NAME) -L $(LIBFT)/ -lft -L $(MLX)/ -lmlx $(MLXFLAGS)

%.o: %.c
		@$(CC) -I $(INC_OS) -I $(INC) $< -c -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
