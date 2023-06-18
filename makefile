# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 16:52:14 by ojebbari          #+#    #+#              #
#    Updated: 2023/06/18 11:24:43 by ojebbari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c indexing.c instruction.c algo_sort_print.c sort_min.c \
		utils1.c utils2.c
CFLAGS = -Wall -Wextra -Werror
CC = cc
NAME = push_swap
BONUS_NAME = checker
RM = rm -fr
BNS = ./bns/checker.c ./bns/utils1_bonus.c ./bns/utils2_bonus.c    \
		./bns/indexing_bonus.c ./bns/get_next_line/get_next_line.c \
		./bns/get_next_line/get_next_line_utils.c ./bns/instructions_bonus.c \

OBJ = $(SRC:.c=.o)
OBJBNS = $(BNS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make bonus -C liibft
	@$(CC) $(CFLAGS) $(OBJ) ./liibft/libft.a -o $@

bonus : $(OBJBNS)
	@make bonus -C liibft
	@$(CC) $(CFLAGS) $(OBJBNS) ./liibft/libft.a -o $(BONUS_NAME) 

$(OBJ) : push_swap.h 
$(OBJBNS) : ./bns/checker.h ./bns/get_next_line/get_next_line.h

clean :
	@cd ./liibft && make clean
	@$(RM) $(OBJ)

fclean : clean
	@cd ./liibft && make fclean
	@$(RM) $(NAME)
	@$(RM) $(OBJBNS)

re : fclean all