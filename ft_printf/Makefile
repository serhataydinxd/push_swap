NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
INC		= -I .


SRCS	= ft_printf.c ft_putnbr_base.c ft_putptr.c ft_putunbr.c ft_putchar.c ft_putnbr.c ft_putstr.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
