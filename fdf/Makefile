# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 14:48:19 by sait-ben          #+#    #+#              #
#    Updated: 2016/12/28 16:46:15 by sait-ben         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FUNCTIONS = main.c \
			split_number.c \
			fdf.c
			

INCLUDE = fdf.h

FLAGS = -Wall -Werror -Wextra -lmlx -framework OpenGL -framework AppKit

LIB = Libft/libft.a

all : $(NAME)

$(NAME) :
	@make -C ./Libft/
	gcc $(FLAGS) -o $(NAME) -I $(INCLUDE) $(FUNCTIONS) $(LIB)

clean :
	@make -C ./Libft/ clean
	rm -rf all

fclean :	clean
	@make -C ./Libft/ fclean
	rm -rf $(NAME)

re :	fclean all
