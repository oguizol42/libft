# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 14:48:23 by oguizol           #+#    #+#              #
#    Updated: 2025/11/05 18:31:44 by oguizol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_strlen.c \
	  ft_memset.c \

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
#	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME)

%.c%.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all