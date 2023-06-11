# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 16:50:27 by ojebbari          #+#    #+#              #
#    Updated: 2023/06/05 16:50:29 by ojebbari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isdigit.c  ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
		ft_strrchr.c ft_strtrim.c ft_atoi.c ft_strlen.c ft_substr.c
SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c \
			 ft_lstlast.c 
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = libft.a
all: $(NAME)

%.o: %.c libft.h
		cc -Wall -Wextra -Werror -c -o $@ $<
$(NAME) : $(OBJS)
		ar rc $(NAME) $(OBJS)
clean :
		rm -rf $(OBJS) $(OBJS_BONUS)
fclean : clean
		rm -rf $(NAME)
bonus : $(OBJS_BONUS) $(OBJS)
		ar rc $(NAME) $?
re : fclean all