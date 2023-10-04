/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:17:26 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/04 18:52:13 by letnitan         ###   ########.fr       */
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
struct	s_data;

typedef struct s_philo{
	int				philo_id;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	long long		time_of_eating;
	int				dead;
	struct s_data	*data;
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
void		*ft_routine(void *ph_philo);
int			ft_start_routine(t_data	*data);

//eat.c
int			ft_to_eat(t_data *data);
int			ft_right_handed(t_philo *philo);
int			ft_left_handed(t_philo *philo);

/*-----------------------STRUCTURES-MANAGEMENT-----------------------*/

//init_args.c
int			ft_check_args(int argc, char *argv[]);
int			*ft_argc_malloc(int argc);
int			*ft_parsing_arguments(char **argv, int argc);
int			ft_init_args(int argc, char *argv[], t_data *data);

//init_data.c
int			ft_init_philos_threads(t_data *data);
int			ft_init_philos(t_data *data);
int			ft_init_forks(t_data *data);
int			ft_init_data(t_data *data);


//free_data.c
void		ft_free_data(t_data *data);


/*-------------------------------UTILS-------------------------------*/

// utils.c
int			ft_atoi(char *str);
void		ft_error(t_data	*data);
int			ft_pthread_join(t_data *data);

//time.c
long long	ft_get_time(void);




#endif
