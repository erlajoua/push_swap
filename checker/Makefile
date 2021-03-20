# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/07 18:52:30 by erlajoua          #+#    #+#              #
#    Updated: 2021/03/19 09:47:54 by erlajoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	checker

SRCS 		= 	srcs/main.c					\
				srcs/parsing.c				\
				srcs/get_next_line.c		\
				srcs/get_next_line_utils.c	\
				srcs/utils.c						\

INCL 		=	headers/checker.h

OBJS		=	$(SRCS:.c=.o)

PUSHSWAP 	=	../

PUSH_SRCS	=	$(addprefix $(PUSHSWAP)srcs/, ft_atoi.c)		\
				$(addprefix $(PUSHSWAP)srcs/, ft_list.c)		\
				$(addprefix $(PUSHSWAP)srcs/, ft_list2.c)		\
				$(addprefix $(PUSHSWAP)srcs/, display.c)		\
				$(addprefix $(PUSHSWAP)srcs/, parsing.c)		\
				$(addprefix $(PUSHSWAP)srcs/, is_char.c)		\
				$(addprefix $(PUSHSWAP)srcs/, ft_split.c)		\
				$(addprefix $(PUSHSWAP)srcs/, manage_tab.c)		\
				$(addprefix $(PUSHSWAP)srcs/, op_push.c)		\
				$(addprefix $(PUSHSWAP)srcs/, op_swap.c)		\
				$(addprefix $(PUSHSWAP)srcs/, op_rotate.c)		\
				$(addprefix $(PUSHSWAP)srcs/, op_rrotate.c)		\
				$(addprefix $(PUSHSWAP)srcs/, sort_three.c)		\
				$(addprefix $(PUSHSWAP)srcs/, sort_five.c)		\
				$(addprefix $(PUSHSWAP)srcs/, sort_general.c)	\
				$(addprefix $(PUSHSWAP)srcs/, print_list.c)

PUSH_OBJS 	=	$(PUSH_SRCS:.c=.o)

CC 			= 	clang
FLAGS 		= 	-Wall -Wextra

%.o:		%.c
			$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS) $(PUSH_OBJS) $(INCL)
			@$(MAKE) -C $(PUSHSWAP)
			$(CC) $(FLAGS) $(OBJS) $(PUSH_OBJS) -o $@

clean :
			rm -rf $(OBJS)
			@$(MAKE) clean -C $(PUSHSWAP)

fclean : 	clean
			rm -rf $(NAME)
			@$(MAKE) fclean -C $(PUSHSWAP)

re:			fclean all


.PHONY: 		clean fclean all re

