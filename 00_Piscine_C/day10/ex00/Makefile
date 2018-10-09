# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvigne <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/20 10:21:10 by bvigne            #+#    #+#              #
#    Updated: 2017/07/20 10:21:14 by bvigne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Wextra -Werror
C_SRC = ./srcs/
SRC = $(C_SRC)ft_putchar.c $(C_SRC)ft_strlen.c $(C_SRC)ft_putstr.c \
$(C_SRC)ft_swap.c $(C_SRC)ft_strcmp.c
C_HED = ./includes/
OBJ = ft_putchar.o ft_strlen.o ft_putstr.o ft_swap.o ft_strcmp.o
OPTION = -c -I $(C_HED)

all: $(NAME)

$(NAME):
		gcc $(FLAG) $(OPTION) $(SRC)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all
