# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/05 11:36:38 by rhutchin          #+#    #+#              #
#    Updated: 2019/06/17 15:47:25 by rhutchin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

SRC = ft_printf.c srcs/ft_newformat.c

OBJ = ft_printf.o ft_newformat.o

INCL = ./incl/ft_printf.h libft/libft.a

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC)
	ar rv $(NAME) $(OBJ) $(INCL)
	ranlib $(NAME)
	gcc -Wall -Werror -Wextra main.c $(NAME) $(INCL) -I./libft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f a.out

re: fclean all

