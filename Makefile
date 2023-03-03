# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdesseau <sdesseau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 20:13:21 by stan              #+#    #+#              #
#    Updated: 2023/03/03 18:36:55 by sdesseau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= container
CC		:= clang++
FLAGS	:= -Wall -Werror -Wextra -std=c++98

SRCS	:= example_main.cpp
SRCS_TESTS := tests/main_tests.cpp

OBJS	:= ${SRCS:.cpp=.o}
OBJS_TESTS	:= ${SRCS_TESTS:.cpp=.o}

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

# ${NAME}:	${OBJS}
# 			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
# 			${CC} ${FLAGS} -o $(NAME) $(SRCS)
# 			@echo "$(GREEN)$(NAME) created[0m ✔️"

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o $(NAME) $(SRCS_TESTS)
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all
		

.PHONY:		all clean fclean re