# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/16 11:28:33 by fkoehler          #+#    #+#              #
#    Updated: 2016/12/12 18:42:47 by fkoehler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = check_tetri.c \
copy_tetris.c \
fill_square.c \
ft_small_square.c \
main.c \
put_blocks_up.c \
read_tetri.c \
set_tetri_size.c

NAME = fillit

FLAGS = -Wall -Werror -Wextra

LIBDIR = ./libft/

LIB = $(LIBDIR)libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	gcc $(FLAGS) $(OBJ) -L $(LIBDIR) -lft -o $(NAME)

$(LIB):
	make -C $(LIBDIR)

%.o: %.c
	gcc $(FLAGS) -c $< -I $(LIBDIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
