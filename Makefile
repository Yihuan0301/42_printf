# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yihzhang <yihzhang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 21:51:06 by yihzhang          #+#    #+#              #
#    Updated: 2025/11/21 23:23:30 by yihzhang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = printf_base_nbr.c printf_base_ptr.c printf_char.c printf_str.c ft_printf.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

#1.compile:To make .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
#2.link:To build libft, use .o files above
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean flean re
