# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggane <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/08 17:29:33 by ggane             #+#    #+#              #
#    Updated: 2017/10/12 19:40:55 by ggane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= test04
SRC= launcher.c \
	 ../../src/some_3d_coordinates_values.c \
	 ../../src/some_3d_coordinates_test_utils.c \
	 ../../src/some_3d_map_coordinates.c \
	 ../../src/check01.c \
	 ../../src/errors.c \
	 ../../src/fd_basic_functions.c \
	 ../../src/parsing_utils.c \
	 ../../src/check00.c
OBJ= $(SRC:.c=.o)
CC= gcc
INC= ../../inc
LIBFT= ../../libft

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIBFT) -j 8
		@echo $(OBJ)
		$(CC) $(OBJ) -o $(NAME) -L $(LIBFT)/ -lft

%.o: %.c
		$(CC) -I $(INC) -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
