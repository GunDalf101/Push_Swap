# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 07:50:23 by mbennani          #+#    #+#              #
#    Updated: 2022/11/01 16:13:00 by mbennani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_printf.c \
			  flags.c \
			  ft_printarg.c \
			  ft_puts.c \
			  ft_hex.c \

OBJS		= $(SRCS:.c=.o)

INCS		= ft_printf.h

FLAGS		= -Wall -Werror -Wextra

all: $(NAME)

%.o : %.c $(INCS)
	cc $(FLAGS) -c $<

$(NAME):$(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean bonus