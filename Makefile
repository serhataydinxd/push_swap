NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror


SRCS	= adaptive.c atoi.c chunk_based.c disorder.c fake_selection_sort.c flag_parser.c \
		  main.c parser.c parser_utils.c print_bench.c push.c radix_sort.c rotate.c \
		  rrotate.c selection_sort.c swap.c utils.c
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
