# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 12:47:10 by oguizol           #+#    #+#              #
#    Updated: 2025/11/20 08:47:57 by oguizol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
	  managlst.c \
	  managstr.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

%.c%.o:
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
#	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
