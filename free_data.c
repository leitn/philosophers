/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:18:01 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/04 16:00:12 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// WIP (obviously)
void	ft_free_data(t_data *data)
{
	free(data->forks);
	free(data->philos);
	free(data->philo_threads);
	free(data);
}
