NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror


SRCS	= disorder.c parser.c main.c atoi.c selection_sort.c radix_sort.c \
		  push.c rotate.c rrotate.c swap.c utils.c flag_parser.c adaptive.c \
		  print_bench.c chunk_based.c
OBJS	= $(SRCS:.c=.o)

PRINTF_DIR  = ft_printf
PRINTF  = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(PRINTF_DIR) -c $< -o $@

clean:
	rm -rf $(OBJS)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
