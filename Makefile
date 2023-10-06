# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 14:04:24 by letnitan          #+#    #+#              #
#    Updated: 2023/10/06 10:47:41 by letnitan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC_FILES =	srcs/main.c \
			srcs/init_args.c \
			srcs/time.c \
			srcs/init_data.c \
			srcs/free_data.c \
			srcs/eat.c \
			srcs/sleep.c \
			srcs/die.c \
			srcs/think.c \
			srcs/utils.c \
			srcs/get_info.c \
			srcs/set_info.c \

SRCS = $(SRC_FILES)
OBJS = ${SRCS:.c=.o}

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -pthread -g3

RM = rm -rf

all:	$(NAME)


$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


clean :
		${RM} ${OBJS}

fclean : clean
		${RM} $(NAME)
		rm -rf *.o

re : fclean all

.PHONY:		all clean fclean re
