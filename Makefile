NAME = push_swap
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
OBJECTS = $(SOURCES:.c=.o)
INCLUDES = push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

all: libft ft_printf $(NAME)

$(NAME):$(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(CFLAGS) $(LIBFT) $(PRINTF)

%.o: %.c push_swap.h
	$(CC) -c $<

libft:
	@make -C libft bonus

ft_printf:
	@make -C ft_printf

clean:
	rm -f $(OBJECTS)
	@make -C ft_printf clean
	@make -C libft clean
	
fclean: clean
	rm -f server client ft_printf/ft_printf.a libft/libft.a

re: fclean all

.PHONY: all bonus ft_printf libft clean fclean re