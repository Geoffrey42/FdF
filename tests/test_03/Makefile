# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggane <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/08 17:29:33 by ggane             #+#    #+#              #
#    Updated: 2017/10/08 17:51:58 by ggane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= test03
SRC= launcher.c
OBJ= $(SRC:.c=.o)
CC= gcc
INC= ../../inc
LIBFT= ../../libft

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIBFT) -j 8
		$(CC) $(OBJ) -o $(NAME) -L $(LIBFT)/ -lft

%.o: %.c
		$(CC) -I $(INC) $< -c -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
