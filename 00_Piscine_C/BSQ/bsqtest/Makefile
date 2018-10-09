NAME = bsq
CC = gcc
RM = rm -rf
FLAGS = -Wall -Werror -Wextra
OPTIONS = -c -I $(HEADER_PATH)
HEADER_PATH = ./includes/
SRCS_PATH = ./srcs/
OBJS = *.o
SRCS = $(SRCS_PATH)*.c

all: $(NAME)

$(NAME):
		$(CC) $(FLAGS) -g $(OPTIONS) $(SRCS)
		$(CC) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
