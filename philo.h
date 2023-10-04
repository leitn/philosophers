/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:17:26 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/04 15:39:29 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
/*-----------------------------INCLUDES-----------------------------*/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/*----------------------------STRUCTURES----------------------------*/

typedef struct s_philo{
	int				philo_id;
	int				*right_fork;
	int				*left_fork;
	long long		time_of_eating;
	int				dead;
	t_data			*data;
}	t_philo;

typedef struct s_data{
	int				nb_philo;
	int				nb_meals;
	long			start_time;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				nb_must_eat;
	pthread_mutex_t	mut_nb_philos;
	pthread_mutex_t	mut_die_time;
	pthread_mutex_t	mut_eat_time;
	pthread_mutex_t	mut_sleep_t;
	pthread_mutex_t	mut_print;
	pthread_mutex_t	mut_start_t;
	pthread_mutex_t	*forks;
	pthread_t		*philo_threads;
	t_philo			*philos;
}	t_data;


/*-------------------------------MAIN-------------------------------*/

//main.c
void		do_nothing_but_make(t_data *data);
int			ft_to_eat(t_data *data);
void		ft_routine(t_data *data);


/*-----------------------STRUCTURES-MANAGEMENT-----------------------*/

//init_args.c
int			ft_check_args(int argc, char *argv[]);
int			*ft_argc_malloc(int argc);
int			*ft_parsing_arguments(char **argv, int argc);
void		ft_init_args(int argc, char *argv[], t_data *data);

//init_data.c
int			ft_init_data(t_data *data);


//free_data.c
void		ft_free_data(t_data *data);


/*-------------------------------UTILS-------------------------------*/

// utils.c
int			ft_atoi(char *str);

//time.c
long long	ft_get_time(void);




#endif
