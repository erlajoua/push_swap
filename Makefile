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
PS_DIR				=	./ps/
CK_DIR				=	./ck/

all			:	$(PS_NAME) $(CK_NAME)

$(PS_NAME)	:
			make -C $(PS_DIR)
			mv $(PS_DIR)$(PS_NAME) ./

$(CK_NAME)	:
			make -C $(CK_DIR)
			mv $(CK_DIR)$(CK_NAME) ./

clean		:
			make clean -C $(PS_DIR)
			make clean -C $(CK_DIR)

fclean		:	clean
			rm -f $(PS_NAME)
			rm -f $(CK_NAME)

re			:	fclean all

.PHONY: 		clean fclean all re
