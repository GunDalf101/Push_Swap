NAME		= gnl.a

SRCS		=	get_next_line.c\
				get_next_line_utils.c

OBJS		= $(SRCS:.c=.o)

INCS		=	get_next_line.h

FLAGS		= -Wall -Werror -Wextra

all: $(NAME)

%.o : %.c $(INCS)
	cc $(FLAGS) -c $<

$(NAME):$(OBJS)
	@ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
