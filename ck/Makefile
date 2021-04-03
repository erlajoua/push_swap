# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 11:34:43 by erlajoua          #+#    #+#              #
#    Updated: 2021/04/03 11:34:44 by erlajoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	checker
SRCS_DIR		=	./srcs/
SRCS			=	main.c					\
					parsing.c				\
					get_next_line.c			\
					get_next_line_utils.c

PS_SRCS_DIR		=	../ps/srcs/

SRCS_BASENAME	=	$(addprefix $(SRCS_DIR), $(SRCS))			\
					$(addprefix $(PS_SRCS_DIR), op_push.c)		\
					$(addprefix $(PS_SRCS_DIR), op_rotate.c)	\
					$(addprefix $(PS_SRCS_DIR), op_rrotate.c)	\
					$(addprefix $(PS_SRCS_DIR), op_swap.c)		\
					$(addprefix $(PS_SRCS_DIR), ft_list.c)		\
					$(addprefix $(PS_SRCS_DIR), ft_split.c)		\
					$(addprefix $(PS_SRCS_DIR), ft_atoi.c)		\
					$(addprefix $(PS_SRCS_DIR), is_char.c)
OBJS			=	$(SRCS_BASENAME:.c=.o)

CC					=	clang

FLAGS				=	-Wall -Werror -Wextra

.c.o		:
			$(CC) -c $< -o $(<:.c=.o) $(FLAGS)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CC) $(OBJS) $(FLAGS) -o $(NAME)
			@echo [$(NAME)] : Created !

clean		:
			rm -rf $(OBJS)

fclean		:	clean
			rm -f $(NAME)
			@echo [$(NAME)] : Deleted !

re			:	fclean all

.PHONY: 		clean fclean all re
