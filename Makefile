# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggane <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/04 11:16:35 by ggane             #+#    #+#              #
#    Updated: 2017/10/22 20:36:40 by ggane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf
SRC= src/check_errors.c \
	 src/check_errors_utils.c \
	 src/draw_line.c \
	 src/draw_directly_in_window.c \
	 src/file_manipulation_utils.c \
	 src/data_structure.c \
	 src/map_coordinates.c \
	 src/delete_utils.c \
	 src/main.c
CC= gcc
CFLAGS= -Wall -Werror -Wextra
OBJ= $(SRC:.c=.o)
LIBFT= libft
INC= inc
TESTS= tests
TEST_SCRIPT= compile.sh

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
		@make -s -C $(TESTS)/test00/ clean
		@echo "$(TESTS)/test00 cleaned"
		@make -s -C $(TESTS)/test01/ clean
		@echo "$(TESTS)/test01 cleaned"
		@make -s -C $(TESTS)/test02/ clean
		@echo "$(TESTS)/test02 cleaned"
		@rm -f $(OBJ)
		@echo ".obj files deleted"

fclean: clean
		@make -s -C $(LIBFT)/ fclean
		@make -s -C $(TESTS)/test00/ fclean
		@make -s -C $(TESTS)/test01/ fclean
		@make -s -C $(TESTS)/test02/ fclean
		@rm -f $(NAME)
		@echo "$(NAME) deleted"

testall: 
		@make -s -C $(TESTS)/test00
		@./$(TESTS)/test00/$(TEST_SCRIPT)
		@make -s -C $(TESTS)/test01
		@./$(TESTS)/test01/$(TEST_SCRIPT)
		@make -s -C $(TESTS)/test02
		@./$(TESTS)/test02/$(TEST_SCRIPT)

test00:
		@make -C $(TESTS)/test00
		@./$(TESTS)/test00/$(TEST_SCRIPT)

test01:
		@make -C $(TESTS)/test01
		@./$(TESTS)/test01/$(TEST_SCRIPT)

test02:
		@make -C $(TESTS)/test02
		@./$(TESTS)/test02/$(TEST_SCRIPT)

re: fclean all
