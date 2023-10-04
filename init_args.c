/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:57:09 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/04 15:54:50 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_args(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			else
				return (1);
		}
		i++;
		j = 0;
	}
	return (0);
}

int	*ft_argc_malloc(int argc)
{
	int	*intarg;

	if (argc == 5)
	{
		intarg = malloc(4 * sizeof(int));
		if (intarg == NULL)
			exit(EXIT_FAILURE);
	}
	if (argc == 6)
	{
		intarg = malloc(5 * sizeof(int));
		if (intarg == NULL)
			exit(EXIT_FAILURE);
	}

	return (intarg);
}

int	*ft_parsing_arguments(char **argv, int argc)
{
	int	i;
	int	*intarg;

	intarg = ft_argc_malloc(argc);
	if (ft_check_args(argc, argv) == 1)
	{
		free(intarg);
		return (1);
	}
	i = 0;
	while (i < 4)
	{
		intarg[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	intarg[4] = 0;
	if (argc == 6)
		intarg[4] = ft_atoi(argv[5]);
	return (intarg);
}


void	ft_init_args(int argc, char *argv[], t_data *data)
{
	int		*arguments;

	arguments = ft_parsing_arguments(argv, argc);
	printf("\nnumber_of_philosophers == %d philosophers\n", arguments[0]);
	data->nb_philo = arguments[0];
	printf("\ntime_to_die == %dms\n", arguments[1]);
	data->time_to_die = arguments[1];
	printf("\ntime_to_eat == %dms\n", arguments[2]);
	data->time_to_eat = arguments[2];
	printf("\ntime_to_sleep == %dms\n", arguments[3]);
	data->time_to_sleep = arguments[3];
	if (argc == 6)
	{
		printf("\nnumber_of_times_each_philosopher_must_eat == %d times\n",
			arguments[4]);
		data->nb_must_eat = arguments[4];
	}
	free(arguments);
}
