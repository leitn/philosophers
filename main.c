/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:57:04 by letnitan          #+#    #+#             */
/*   Updated: 2023/09/20 16:06:26 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	*ft_parsing_arguments(char **argv, int argc)
{
	int	i;
	int	j;
	int	*intarg;

	i = 1;
	j = 0;
	if (argc == 5)
		intarg = malloc(4 * sizeof(int));
	else if (argc == 6)
		intarg = malloc(5 * sizeof(int));
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			else
				exit(EXIT_FAILURE);
		}
		i++;
		j = 0;
	}
	intarg[0] = ft_atoi(argv[1]);
	intarg[1] = ft_atoi(argv[2]);
	intarg[2] = ft_atoi(argv[3]);
	intarg[3] = ft_atoi(argv[4]);
	if (argc == 6)
		intarg[4] = ft_atoi(argv[5]);
	return (intarg);
}

void	*thread_routine(void *data)
{
	t_main		*t_m;

	t_m = (t_main *)data;
	pthread_mutex_lock(&t_m->print_mutex);
	printf("\nThread [Count == %i]: Le plus grand ennui c'est d'exister sans vivre.\n ",
		t_m->counter);
	t_m->counter = t_m->counter + 1;
	pthread_mutex_unlock(&t_m->print_mutex);
	return (NULL);
}

void	ft_create_threads(int i, t_main *t_m)
{
	pthread_t	tid;

	pthread_create(&tid, NULL, thread_routine, &t_m);
	t_m->nb_threads = t_m->nb_threads + 1;
	i = i + 1;
	// printf("\n - Philosopher Number %i has been created\n count == %i\n", i,
	// 	t_m->counter);
}

void	ft_start(t_arg t_arg, t_main *t_m)
{
	int	i;

	i = 0;
	while (i < t_arg.number_of_philosophers)
	{
		ft_create_threads(i, t_m);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		*arguments;
	t_arg	t_arg;
	t_main	t_m;

	if (argc <= 4 || argc > 6)
	{
		ft_printf("invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	t_m.counter = 0;
	pthread_mutex_init(&t_m.print_mutex, NULL);
	pthread_mutex_init(&t_m.counter_mutex, NULL);
	arguments = ft_parsing_arguments(argv, argc);
	ft_printf("\nnumber_of_philosophers == %d philosophers\n", arguments[0]);
	t_arg.number_of_philosophers = arguments[0];
	ft_printf("\ntime_to_die == %dms\n", arguments[1]);
	t_arg.time_to_die = arguments[1];
	ft_printf("\ntime_to_eat == %dms\n", arguments[2]);
	t_arg.time_to_eat = arguments[2];
	ft_printf("\ntime_to_sleep == %dms\n", arguments[3]);
	if (argc == 6)
	{
		ft_printf("\nnumber_of_times_each_philosopher_must_eat == %d times\n",
			arguments[4]);
		t_arg.nb_times_philos_must_eat = arguments[4];
	}
	ft_start(t_arg, &t_m);
	pthread_mutex_destroy(&t_m.print_mutex);
	pthread_mutex_destroy(&t_m.counter_mutex);
	return (0);
}

// Un Philosopher = 1 Fourchette, un mutex par fourchette
// timestamp_in_ms
