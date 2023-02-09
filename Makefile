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

bonus: libft ft_printf get_next_line $(NAMEBNS)
	@if [ $$? -eq 0 ]; then \
		echo "\033[3m\033[1m\033[42m\033[31m~~Nothing to be done for 'bonus' anymore~~\033[0m"; \
	fi

$(NAME):$(OBJECTS)
	@$(CC) -o $@ $(OBJECTS) $(CFLAGS) $(LIBFT) $(PRINTF)
	@echo "\033[47m\033[30m\033[1m           \`$@ linked\`           \033[0m"

$(NAMEBNS):$(OBJECTSBNS)
	@$(CC) -o $@ $(OBJECTSBNS) $(CFLAGS) $(LIBFT) $(PRINTF) $(GNL)
	@echo "\033[47m\033[30m\033[1m            \`$@ linked\`              \033[0m"

%_bonus.o: %_bonus.c push_swap_bonus.h
	@$(CC) -c $(CFLAGS) $<
	@echo "\033[33m$< compiled \033[0m"

%.o: %.c push_swap.h
	@$(CC) -c $(CFLAGS) $<
	@echo "\033[33m$< compiled \033[0m"

get_next_line:
	@make -s -C gnl
	@echo "\033[35m$@ have been made \033[0m"

libft:
	@echo '                                             _______________________'
	@echo '   _______________________-------------------                        \'
	@echo ' /:--__                                                              |'
	@echo '||< > |                                   ___________________________/'
	@echo '| \__/_________________-------------------                         |'
	@echo '|                                                                  |'
	@echo ' |                  THE SCROLL OF INFINITE WISDOM                   |'
	@echo ' |                                                                  |'
	@echo ' |       Three Rings for the Elven-kings under the sky,             |'
	@echo '  |        Seven for the Dwarf-lords in their halls of stone,        |'
	@echo '  |      Nine for Mortal Men doomed to die,                          |'
	@echo '  |        One for the Dark Lord on his dark throne                  |'
	@echo '  |      In the Land of Mordor where the Shadows lie.                 |'
	@echo '   |       One Ring to rule them all, One Ring to find them,          |'
	@echo '   |       One Ring to bring them all and in the darkness bind them   |'
	@echo '   |     In the Land of Mordor where the Shadows lie.                |'
	@echo '  |                                                                  |'
	@echo '  |                                             -----------          |'
	@echo '  |                                            )) GunDalf ((          |'
	@echo '  |                                             -----------           |'
	@echo '  |                                              ____________________|_'
	@echo '  |  ___________________-------------------------                       \'
	@echo '  |/ --_                                                                 |'
	@echo '  ||[ ]||                                            ___________________/'
	@echo '   \===/___________________--------------------------'
	@echo ''
	@make -s -C libft bonus
	@echo "\033[35m$@ have been made \033[0m"

ft_printf:
	@make -s -C ft_printf
	@echo "\033[35m$@ have been made \033[0m";

clean:
	@rm -f $(OBJECTS) $(OBJECTSBNS)
	@make -s -C ft_printf clean
	@make -s -C libft clean
	@make -s -C gnl clean
	@echo "\033[3m\033[1m\033[42m\033[31m~~   The objects have been cleaned   ~~\033[0m"; \
	
fclean: clean
	@make -s -C ft_printf fclean
	@make -s -C libft fclean
	@make -s -C gnl fclean
	@rm -f pushswap checker
	@echo "\033[3m\033[1m\033[42m\033[31m~~The directory have been fully wiped~~\033[0m"; \

re: fclean all

.PHONY: all bonus ft_printf libft clean fclean re get_next_line