# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggane <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/08 17:29:33 by ggane             #+#    #+#              #
#    Updated: 2017/10/21 19:19:45 by ggane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= test00
SRC= launcher.c \
	 ../../src/check_errors.c \
	 ../../src/check_errors_utils.c \
	 ../../src/file_manipulation_utils.c
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
