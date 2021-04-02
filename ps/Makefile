NAME			=	push_swap
SRCS_DIR		=	./srcs/
SRCS			=	main.c			\
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
					chunk.c			\
					ft_rooftop.c	\
					swap_to.c		\
					get_pos.c		\
					algo.c			\
					backtrack.c
SRCS_BASENAME	=	$(addprefix $(SRCS_DIR), $(SRCS))
OBJS			=	$(SRCS_BASENAME:.c=.o)
CC					=	gcc
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
