# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/17 15:12:18 by sait-ben          #+#    #+#              #
#    Updated: 2017/02/27 14:43:38 by sait-ben         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= ft_atoi.c \
		  ft_bzero.c \
		  ft_isalpha.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_itoa.c \
		  ft_itoa_base.c \
		  ft_memalloc.c \
		  ft_memccpy.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memdel.c \
		  ft_memmove.c \
		  ft_memset.c \
		  ft_putchar.c \
		  ft_putchar_fd.c \
		  ft_putendl.c \
		  ft_putendl_fd.c \
		  ft_putnbr.c \
		  ft_putnbr_fd.c \
		  ft_putstr.c \
		  ft_putstr_fd.c \
		  ft_sort_params.c \
		  ft_strcat.c \
		  ft_strchr.c \
		  ft_strclr.c \
		  ft_strcmp.c \
		  ft_strcpy.c \
		  ft_strdel.c \
		  ft_strdup.c \
		  ft_strequ.c \
		  ft_striter.c \
		  ft_striteri.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlen.c \
		  ft_strmap.c \
		  ft_strmapi.c \
		  ft_strncat.c \
		  ft_strncmp.c \
		  ft_strncpy.c \
		  ft_strnequ.c \
		  ft_strnew.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strsplit.c \
		  ft_strstr.c \
		  ft_strsub.c \
		  ft_strtrim.c \
		  ft_sqrt.c \
		  ft_swap.c \
		  ft_tolower.c \
		  ft_toupper.c \
		  get_next_line.c \
		  ft_printf.c \
		  convert.c \
		  option_detect.c \
		  options.c \
		  int_arg.c \
		  in_out.c \
		  init_flags.c \
		  s_arg.c \
		  cast.c \
		  dou_arg.c \
		  apply_options.c \
		  apply_options_bis.c \
		  in_out.c \
		  ft_maj.c \
		  w_putchar.c \
		  c_arg.c \
		  p_arg.c \
		  ft_itoa_base_uint.c \
		  pct_arg.c \
		  ft_valeur_absolue.c \
		  ft_strsubwchar.c \
		  apply_precision_p.c \
		  ft_atoi_max.c \
		  apply_zero.c \
		  apply_precision.c \
		  apply_options_ter.c 

OBJ_PATH = ./obj/

SOURCE_PATH = ./sources/

OBJ_FILE = $(SRCS:%.c=%.o)

OBJ	= $(OBJ_FILE:%=$(OBJ_PATH)%)

CFILES	= $(SRCS:%=./sources/%)

HEADER	= $(INC:%=./sources/%)

FLAGS = -Wextra -Werror -Wall

NAME = libft.a

INC = libft.h \
	  printf.h \
	  get_next_line.h \

$(OBJ_PATH)%.o: $(SOURCE_PATH)%.c $(HEADER)
	    @mkdir -p $(OBJ_PATH)
		gcc $(FLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	    ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
	    /bin/rm -rf $(OBJ_PATH)

fclean: clean
	    /bin/rm -f $(NAME)

re: fclean all
