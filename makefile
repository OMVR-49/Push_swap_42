# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 16:52:14 by ojebbari          #+#    #+#              #
#    Updated: 2023/06/13 00:33:48 by ojebbari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c 
CFLAGS = -Wall -Wextra -Werror 
CC = cc
NAME = push_swap
BONUS_NAME = checker
RM = rm -fr
BNS = checker.c

OBJ = $(SRC:.c=.o)
OBJBNS = $(BNS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make bonus -C liibft
	@$(CC) $(CFLAGS) $(OBJ) ./liibft/libft.a -o $@

bonus : $(BONUS_NAME) $(OBJBNS)
	@$(CC) $(CFLAGS) $(OBJBNS) -o $(BONUS_NAME) 
	
$(OBJ) : push_swap.h
$(OBJBNS) : push_swap_bonus.h

clean :
	@cd ./liibft && make clean
	@$(RM) $(OBJ)

fclean : clean
	@cd ./liibft && make fclean
	@$(RM) $(NAME)
	@$(RM) $(OBJBNS)

re : fclean all