/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:38:35 by mtaleb            #+#    #+#             */
/*   Updated: 2025/07/24 18:41:05 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philos(t_data *data)
{
	int	i;

	if (!data || !data->philos)
		return ;
	i = 0;
	while (i < data->numofphilos)
	{
		if (data->philos[i])
		{
			free(data->philos[i]);
			data->philos[i] = NULL;
		}
		i++;
	}
	free(data->philos);
	data->philos = NULL;
}

void	free_forks(t_data *data)
{
	int	i;

	if (!data || !data->forks)
		return ;
	i = 0;
	while (i < data->numofphilos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
	data->forks = NULL;
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	free_philos(data);
	free_forks(data);
	pthread_mutex_destroy(&data->xeat_mutex);
	pthread_mutex_destroy(&data->death_mutex);
	pthread_mutex_destroy(&data->printlock);
	pthread_mutex_destroy(&data->all_mutex);
	free(data);
}
