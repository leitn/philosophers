/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:57:09 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/06 16:05:37 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
			while (argv[i][j] == '\r' || argv[i][j] == '\t' || argv[i][j] == ' '
			|| argv[i][j] == '\f' || argv[i][j] == '\v' || argv[i][j] == '\n')
				return (1);
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (1);
			while (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
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
		return (NULL);
	}
	i = 0;
	while (i < 4)
	{
		intarg[i] = ft_atoi(argv[i + 1]);
		if (intarg[i] == 0)
			return (NULL);
		i++;
	}
	if (argc == 6)
		intarg[4] = ft_atoi(argv[5]);
	return (intarg);
}


int	ft_init_args(int argc, char *argv[], t_data *data)
{
	int		*arguments;

	arguments = ft_parsing_arguments(argv, argc);
	if (arguments == NULL)
		return (1);
	data->nb_philo = arguments[0];
	data->time_to_die = arguments[1];
	data->time_to_eat = arguments[2];
	data->time_to_sleep = arguments[3];
	if (argc == 6)
		data->nb_must_eat = arguments[4];
	free(arguments);
	return (0);
}