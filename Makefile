# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/07 18:52:30 by erlajoua          #+#    #+#              #
#    Updated: 2021/03/18 11:47:41 by erlajoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = 	srcs/ft_atoi.c \
		srcs/ft_list.c \
		srcs/ft_list2.c \
		srcs/main.c \
		srcs/parsing.c \
		srcs/manage_tab.c \
		srcs/op_push.c \
		srcs/op_swap.c \
		srcs/op_rotate.c \
		srcs/op_rrotate.c \
		srcs/sort_three.c \
		srcs/sort_five.c \
		srcs/sort_general.c \
		srcs/print_list.c

INCL =	headers/push_swap.h

OBJS = $(SRCS:.c=.o)

CC = clang
FLAGS = -Wall -Wextra

%.o:		%.c
			$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJS) $(INCL)
			$(CC) $(FLAGS) $(OBJS) -o $@

clean :
			rm -rf $(OBJS)

fclean : 	clean
			rm -rf $(NAME)

re:			fclean all

.PHONY: 		clean fclean all re

