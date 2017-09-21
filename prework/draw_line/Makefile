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

NAME= draw_line 
SRC= draw_line.c
CC= gcc
CFLAGS= -Wall -Werror -Wextra
INC= ../../inc
OBJ= $(SRC:.c=.o)
LIBFT= ../../libft
MLX= ../../minilibx_macos

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIBFT) -j 8
		make -C $(MLX) -j 8
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L $(LIBFT)/ -lft -L $(MLX)/ -lmlx -framework OpenGL -framework Appkit

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
