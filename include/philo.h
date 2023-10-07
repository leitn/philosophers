/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:17:26 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/07 13:17:11 by letnitan         ###   ########.fr       */
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

typedef enum e_status{
	THINKING = 0,
	EATING = 1,
	SLEEPING = 2,
	DIED = 3,
	FULL = 4,
	NOTHING = 5,
}	t_status;

struct	s_data;

typedef struct s_philo{
	int				philo_id;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	long long		time_of_eating;
	t_status		status;
	pthread_mutex_t	mut_status;
	pthread_mutex_t	mut_t_eating;
	pthread_mutex_t	mut_nb_meals;
	int				nb_meals;
	struct s_data	*data;
}	t_philo;

typedef struct s_data{
	long			nb_philo;
	long long		start_time;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				nb_max_meals;
	int				finished_dinner;
	pthread_mutex_t	mut_nb_philos;
	pthread_mutex_t	mut_start_t;
	pthread_mutex_t	mut_die_time;
	pthread_mutex_t	mut_eat_time;
	pthread_mutex_t	mut_sleep_t;
	pthread_mutex_t	mut_max_meals;
	pthread_mutex_t	mut_finished;
	pthread_mutex_t	mut_print;
	pthread_mutex_t	*forks;
	pthread_t		*philo_threads;
	pthread_t		monitor;
	t_philo			*philos;
}	t_data;

/*-------------------------------MAIN-------------------------------*/
//main.c
int			ft_pthread_join(t_data *data);
void		*ft_routine(void *ph_philo);
int			philosophers_problem(t_data *data);
int			ft_start_routine(t_data	*data);

//eat.c
void		unlock_forks(t_philo *philo);
int			take_left_fork(t_philo *philo);
int			take_right_fork(t_philo *philo);
int			ft_right_handed(t_philo *philo);
int			ft_left_handed(t_philo *philo);
int			ft_eat(t_philo	*philo);

//sleep.c
int			ft_sleep(t_philo *philo);

//die.c
int			is_someone_dead(t_data *data);
int			death_status(t_philo *philo);

//think.c
int			ft_think(t_philo *philo);

//monitor.c
int			finished_eating(t_data *data);
int			is_that_one_dead(t_philo *philo);
int			valar_morghulis(t_data *data);
void		ft_monitor(t_data *data);

/*-----------------------STRUCTURES-MANAGEMENT-----------------------*/

//init_args.c
int			ft_check_args(int argc, char *argv[]);
int			*ft_argc_malloc(void);
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
void		print_with_mutex(char *str, t_data *data);
void		print_mandatory_format(t_data *data, int id, char *str);

//time.c
void		eat_usleep(long long eat_time);
void		sleep_usleep(long long sleep_time);
void		ft_time_of_eating(t_philo *philo);
long long	ft_get_time(void);

//get_info.c
t_status	get_status(t_philo *philo);
long long	ft_get_last_meal_time(t_philo *philo);
long long	ft_get_time_to_eat(t_philo *philo);
long long	ft_get_time_to_die(t_philo *philo);
long long	ft_get_time_to_sleep(t_philo *philo);
long		ft_get_nb_philos(t_data *data);
long long	ft_get_start_time(t_data *data);
int			ft_get_nb_max_meals(t_data *data);

//set_info.c
void		set_status(t_philo *philo, t_status status);
void		set_nb_meals(t_philo *philo);
void		set_finished(t_data *data);
long long	ft_set_last_meal_time(t_philo *philo);


#endif
