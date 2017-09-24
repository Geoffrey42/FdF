# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggane <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/04 11:16:35 by ggane             #+#    #+#              #
#    Updated: 2017/03/15 15:08:07 by ggane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf
SRC= src/main.c
CC= gcc
CFLAGS= -Wall -Werror -Wextra
OBJ= $(SRC:.c=.o)
LIBFT= libft

ifeq ($(shell uname), Linux)
    INC= inc_linux
    MLX= mlx_linux
    MLXFLAGS= -lXext -lX11
else
    INC= inc_osx
    MLX= mlx_osx
    MLXFLAGS= -framework OpenGL -framework Appkit
endif

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIBFT) -j 8
		make -C $(MLX) -j 8
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L $(LIBFT)/ -lft -L $(MLX)/ -lmlx $(MLXFLAGS)

%.o: %.c
		$(CC) $(CFLAGS) -I $(INC) $< -c -o $@
clean:
		make -C $(LIBFT)/ clean
		make -C $(MLX)/ clean
		rm -f $(OBJ)

fclean: clean
		make -C $(LIBFT)/ fclean
		rm -f $(NAME)

re: fclean all
