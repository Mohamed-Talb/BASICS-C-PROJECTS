/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:38:52 by mtaleb            #+#    #+#             */
/*   Updated: 2025/07/10 17:14:18 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data)
{
	if (!data)
	{
		errors(data, MALLOC_ERROR);
		return (1);
	}
	data->tdie = -1;
	data->teat = -1;
	data->tsleep = -1;
	data->dead = false;
	data->forks = NULL;
	data->philos = NULL;
	data->starttime = -1;
	data->numofphilos = -1;
	data->all = 0;
	if (pthread_mutex_init(&data->xeat_mutex, NULL) != 0)
		return (errors(data, MUTEX_ERROR), 1);
	if (pthread_mutex_init(&data->death_mutex, NULL) != 0)
		return (errors(data, MUTEX_ERROR), 1);
	if (pthread_mutex_init(&data->printlock, NULL) != 0)
		return (errors(data, MUTEX_ERROR), 1);
	if (pthread_mutex_init(&data->all_mutex, NULL) != 0)
		return (errors(data, MUTEX_ERROR), 1);
	return (0);
}
