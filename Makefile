# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 14:04:24 by letnitan          #+#    #+#              #
#    Updated: 2023/10/07 13:18:16 by letnitan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC_FILES =	main \
			init_args\
			time \
			init_data \
			free_data\
			eat \
			sleep \
			die \
			think \
			utils \
			get_info \
			set_info \
			monitor \

SRC_DIR = srcs/
OBJ_DIR = objects/
OBJS = $(addprefix $(OBJ_DIR),  $(addsuffix .o, $(SRC_FILES)))
# ${SRCS:.c=.o}

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -pthread -g3

RM = rm -rf

all:	$(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
		${RM} ${OBJ_DIR}

fclean : clean
		${RM} $(NAME)
		rm -rf *.o

re : fclean all

.PHONY:		all clean fclean re
