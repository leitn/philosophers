/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:17:26 by letnitan          #+#    #+#             */
/*   Updated: 2023/09/25 14:54:20 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_main{
	int				nb_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	int				nb_threads;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	counter_mutex;
	int				counter;
}	t_main;

//main.c
int		*ft_parsing_arguments(char **argv, int argc);
void	*thread_routine(void *data);
void	ft_create_threads(int i, t_main *t_m);
void	ft_start(t_main *t_m);

#endif
