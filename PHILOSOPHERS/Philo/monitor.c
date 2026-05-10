/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:50:15 by mtaleb            #+#    #+#             */
/*   Updated: 2025/07/10 17:48:20 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	get_dead_and_all(t_data *data, int *dead, int *all)
{
	pthread_mutex_lock(&(data->death_mutex));
	*dead = data->dead;
	pthread_mutex_unlock(&(data->death_mutex));
	pthread_mutex_lock(&(data->all_mutex));
	*all = data->all;
	pthread_mutex_unlock(&(data->all_mutex));
}

void	death_checker(t_data *data)
{
	int	i;
	int	is_dead;
	int	all_done;

	while (1)
	{
		get_dead_and_all(data, &is_dead, &all_done);
		if (all_done || is_dead)
			break ;
		i = 0;
		pthread_mutex_lock(&(data->xeat_mutex));
		while (data->mealsrequired != -1 && i < data->numofphilos
			&& data->philos[i]->xeat >= data->mealsrequired)
			i++;
		pthread_mutex_unlock(&(data->xeat_mutex));
		if (i == data->numofphilos)
		{
			pthread_mutex_lock(&(data->all_mutex));
			data->all = 1;
			pthread_mutex_unlock(&(data->all_mutex));
		}
		usleep(100);
	}
}
