# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlaurids <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/17 15:55:13 by nlaurids          #+#    #+#              #
#    Updated: 2020/01/08 12:34:19 by nlaurids         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_printfutils.c ft_printfutils2.c ft_parse.c ft_parse2.c \
	   ft_put.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I libftprintf.h

all:		$(NAME)

$(NAME):	$(OBJS) libftprintf.h
			ar -rc $(NAME) $?

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY =	all clean fclean re
