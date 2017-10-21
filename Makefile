# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggane <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/04 11:16:35 by ggane             #+#    #+#              #
#    Updated: 2017/10/21 17:36:06 by ggane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf
SRC= src/check_errors.c \
	 src/check_errors_utils.c \
	 src/file_manipulation_utils.c \
	 src/main.c
CC= gcc
CFLAGS= -Wall -Werror -Wextra
OBJ= $(SRC:.c=.o)
LIBFT= libft
INC= inc
TESTS= tests
TEST_SCRIPT=compile.sh

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
		make -C $(TESTS)/test_00/ clean
		rm -f $(OBJ)

fclean: clean
		make -C $(LIBFT)/ fclean
		make -C $(TESTS)/test_00/ fclean
		rm -f $(NAME)

testall: 
		make -C $(TESTS)/test_00
		./$(TESTS)/test_00/$(TEST_SCRIPT)

test00:
		make -C $(TESTS)/test_00
		./$(TESTS)/test_00/$(TEST_SCRIPT)

re: fclean all
