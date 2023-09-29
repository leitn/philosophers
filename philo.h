/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:17:26 by letnitan          #+#    #+#             */
/*   Updated: 2023/09/29 16:40:06 by letnitan         ###   ########.fr       */
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
# include <sys/time.h>

/*----------------------------STRUCTURES----------------------------*/

typedef struct s_philo{
	// int				philo_id;
	int				*right_fork;
	int				*left_fork;
	long long		time_of_eating;
	int				dead;
}	t_philo;

typedef struct s_data{
	int				nb_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*forks;
	t_philo			philosopher;
}	t_data;


/*-------------------------------MAIN-------------------------------*/

//main.c
void	do_nothing_but_make(t_data *data);
int			ft_to_eat(t_data *data);
void		ft_routine(t_data *data);


/*-----------------------STRUCTURES-MANAGEMENT-----------------------*/

//init_args.c
int			ft_check_args(int argc, char *argv[]);
int			*ft_argc_malloc(int argc);
int			*ft_parsing_arguments(char **argv, int argc);
void		ft_init_args(int argc, char *argv[], t_data *data);

//init_data.c
void		ft_init_data(t_data *data);


//free_data.c
void		ft_free_data(t_data *data);


/*-------------------------------UTILS-------------------------------*/

//time.c
long long	ft_get_time(void);





#endif
