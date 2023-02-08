NAME = push_swap
NAMEBNS = checker
SOURCES = push_swap.c \
		ops_a.c \
		ops_b.c \
		ops_both.c \
		usables.c \
		sort_check.c \
		algorithm.c \
		fake_ops.c \
		algo_extention.c \
		algo_utils.c
SOURCESBNS = checker_bonus.c \
			parser_bonus.c \
			fake_ops_bonus.c \
			fake_ops2_bonus.c \
			fake_ops3_bonus.c \
			fake_sort_bonus.c
OBJECTS = $(SOURCES:.c=.o)
OBJECTSBNS = $(SOURCESBNS:.c=.o)
INCLUDES = push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
GNL = gnl/gnl.a

all: libft ft_printf $(NAME)
	@if [ $$? -eq 0 ]; then \
		echo "\033[3m\033[1m\033[42m\033[31m~~Nothing to be done for 'all' anymore~~\033[0m"; \
	fi

bonus: getline libft ft_printf $(NAMEBNS)
	@if [ $$? -eq 0 ]; then \
		echo "\033[3m\033[1m\033[42m\033[31m~~Nothing to be done for 'bonus' anymore~~\033[0m"; \
	fi

$(NAME):$(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(CFLAGS) $(LIBFT) $(PRINTF)

$(NAMEBNS):$(OBJECTSBNS)
	$(CC) -o $@ $(OBJECTSBNS) $(CFLAGS) $(LIBFT) $(PRINTF) $(GNL)

%_bonus.o: %_bonus.c push_swap_bonus.h
	$(CC) -c $(CFLAGS) $<

%.o: %.c push_swap.h
	$(CC) -c $(CFLAGS) $<

getline:
	@make -s -C gnl

libft:
	@make -s -C libft bonus

ft_printf:
	@make -s -C ft_printf

clean:
	rm -f $(OBJECTS) $(OBJECTSBNS)
	@make -C ft_printf clean
	@make -C libft clean
	@make -C gnl clean
	
fclean: clean
	@make -C ft_printf fclean
	@make -C libft fclean
	@make -C gnl fclean
	rm -f pushswap checker_bon

re: fclean all

.PHONY: all bonus ft_printf libft clean fclean re getline