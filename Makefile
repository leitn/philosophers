# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 14:04:24 by letnitan          #+#    #+#              #
#    Updated: 2023/09/19 14:09:44 by letnitan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
PRINTF = libftprintf.a
LIBFT = libft.a
SRC_FILES =	main.c

SRCS = $(SRC_FILES)
OBJS = ${SRCS:.c=.o}

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -pthread
INCLUDE = -I include
RM = rm -rf

all:	$(NAME)

bonus:	$(NAMES) $(NAMEC)

$(NAME) : $(OBJS)
		@make -C ft_printf
		@make -C libft
		$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) ft_printf/$(PRINTF) libft/$(LIBFT) -o $(NAME)


clean :
		@make clean -C ft_printf
		@make clean -C libft
		${RM} ${OBJS}

fclean : clean
		@make fclean -C ft_printf
		@make fclean -C libft
		${RM} $(NAME)
		${RM} $(PRINTF)
		${RM} $(LIBFT)

re : fclean all

.PHONY:		all bonus clean fclean re
