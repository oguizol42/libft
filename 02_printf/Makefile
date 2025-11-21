# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 12:47:10 by oguizol           #+#    #+#              #
#    Updated: 2025/11/21 16:26:31 by oguizol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = prog

SRC = ft_printf.c \
	  managlst.c \
	  managstr.c \
	  managconv.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_itoa.c \
	  unsiitoa.c \
	  ft_toupper.c \
	  hexatostring.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -g3

%.c%.o:
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
#	ar rcs $(NAME) $(OBJ)
#	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus


# Mettre a jour: 
#	- remplacer  ligne 14 NAME = prog par NAME = libftprintf.a
#	- remplacer ligne 32 $(CC) $(OBJ) -o $(NAME) par ar rcs $(NAME) $(OBJ)