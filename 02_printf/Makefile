NAME = libftprintf.a

SRC = ft_printf.c \

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
