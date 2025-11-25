# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 12:47:10 by oguizol           #+#    #+#              #
#    Updated: 2025/11/24 10:07:57 by oguizol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
	  managlst.c \
	  managstr.c \
	  managconv.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_itoa.c \
	  unsiitoa.c \
	  ft_toupper.c \
	  hexatostring.c \
	  pointtostring.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

%.c%.o:
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus