# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 14:04:24 by letnitan          #+#    #+#              #
#    Updated: 2023/10/04 16:06:17 by letnitan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC_FILES =	main.c \
			init_args.c \
			time.c \
			init_data.c \
			free_data.c \
			eat.c \
			sleep.c \
			die.c \
			think.c \
			utils.c \

SRCS = $(SRC_FILES)
OBJS = ${SRCS:.c=.o}

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -pthread
RM = rm -rf

all:	$(NAME)


$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


clean :
		${RM} ${OBJS}

fclean : clean
		${RM} $(NAME)
		${RM} $(PRINTF)
		${RM} $(LIBFT)
		rm -rf *.o

re : fclean all

.PHONY:		all clean fclean re
