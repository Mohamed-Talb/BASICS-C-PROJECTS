/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initforks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:38:58 by mtaleb            #+#    #+#             */
/*   Updated: 2025/07/10 16:39:00 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initforks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->numofphilos);
	if (!data->forks)
		return (errors(data, MALLOC_ERROR), 1);
	while (i < data->numofphilos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (errors(data, MUTEX_ERROR), 1);
		i++;
	}
	i = 0;
	while (data->philos[i])
	{
		data->philos[i]->rfork = i;
		if (data->philos[i + 1] == NULL)
			data->philos[i]->lfork = 0;
		else
			data->philos[i]->lfork = i + 1;
		i++;
	}
	return (0);
}
