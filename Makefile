# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/07 18:52:30 by erlajoua          #+#    #+#              #
#    Updated: 2021/03/23 17:26:55 by erlajoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS_NAME				=	push_swap
CK_NAME				=	checker
PS_SRCS_DIR			=	./ps/srcs/
CK_SRCS_DIR			=	./ck/srcs/
PS_SRCS				= 	main.c			\
						ft_atoi.c		\
						ft_list.c		\
						ft_list2.c		\
						display.c		\
						parsing.c		\
						is_char.c		\
						ft_split.c		\
						manage_tab.c	\
						op_push.c		\
						op_swap.c		\
						op_rotate.c		\
						op_rrotate.c	\
						sort_three.c	\
						sort_five.c		\
						sort_onetwo.c	\
						get_values.c	\
						print_list.c	\
						chunk.c			\
						ft_rooftop.c	\
						swap_to.c		\
						get_pos.c		\
						algo.c			\
						backtrack.c
CK_SRCS				=	main.c					\
						parsing.c				\
						get_next_line.c			\
						get_next_line_utils.c	\
						utils.c
PS_SRCS_BASENAME	=	$(addprefix $(PS_SRCS_DIR), $(PS_SRCS))
CK_SRCS_BASENAME	=	$(addprefix $(CK_SRCS_DIR), $(CK_SRCS))		\
						$(addprefix $(PS_SRCS_DIR), parsing.c)		\
						$(addprefix $(PS_SRCS_DIR), op_push.c)		\
						$(addprefix $(PS_SRCS_DIR), op_rotate.c)	\
						$(addprefix $(PS_SRCS_DIR), op_rrotate.c)	\
						$(addprefix $(PS_SRCS_DIR), op_swap.c)	
PS_OBJS				=	$(PS_SRCS_BASENAME:.c=.o)
CK_OBJS				=	$(CK_SRCS_BASENAME:.c=.o)
CC					=	gcc
FLAGS				=	-Wall -Werror -Wextra #-fsanitize=address

.c.o		:
			$(CC) -c $< -o $(<:.c=.o) $(FLAGS)

all			:	$(PS_NAME)

$(PS_NAME)	:	$(PS_OBJS)
			$(CC) $(PS_OBJS) $(FLAGS) -o $(PS_NAME)
			@echo [$(PS_NAME)] : Created !

$(CK_NAME)	:	$(CK_OBJS)
			$(CC) $(CK_OBJS) $(FLAGS) -o $(CK_NAME)

checker		:	$(CK_NAME)

clean		:
			rm -rf $(PS_OBJS)
			rm -rf $(CK_OBJS)

fclean		:	clean
			rm -f $(PS_NAME)
			rm -f $(CK_NAME)

re			:	fclean all

.PHONY: 		clean fclean all re
