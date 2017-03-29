# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/06 16:38:19 by sait-ben          #+#    #+#              #
#    Updated: 2017/03/29 12:39:01 by sait-ben         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES1 = fdf.c \
	   main.c \
	   split_number.c \
	   projection.c \

SRC_PATH = ./srcs/

CFILES1 = $(FILES1:%=./srcs/%)

OBJ_PATH = ./obj/

OBJ_FILE = $(FILES1:%.c=%.o)

OBJ = $(OBJ_FILE:%=$(OBJ_PATH)%)

NAME = fdf

LIB_PATH = ./libft/

LIB = libft.a

FLAGS = -Werror -Wextra -Wall

MLX = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

$(OBJ_PATH)%.o: $(SRC_PATH)%.c ./includes/fdf.h
	    @mkdir -p $(OBJ_PATH)
		gcc $(FLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(LIB_PATH)$(LIB) $(OBJ)
	    gcc -L ./libft/ -lft -o $(NAME) $(MLX) $(OBJ)

$(LIB_PATH)$(LIB):
	    make -C $(LIB_PATH)

clean:
	    /bin/rm -rf $(OBJ_PATH)
	    make -C ./libft/ clean
fclean: clean
	    /bin/rm -f $(NAME)
		make -C ./libft/ fclean

re: fclean all
