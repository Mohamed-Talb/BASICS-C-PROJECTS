/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launche.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:39:37 by mtaleb            #+#    #+#             */
/*   Updated: 2025/07/12 22:55:16 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start(t_data *data)
{
	int	i;

	predict_simulation(data);
	i = 0;
	data->starttime = get_time_in_ms();
	while (i < data->numofphilos)
	{
		if (pthread_create(&data->philos[i]->thread, NULL, routine,
				data->philos[i]))
		{
			i = -1;
			while (++i < data->numofphilos)
				pthread_join(data->philos[i]->thread, NULL);
			return (errors(data, THREAD_ERROR), 1);
		}
		i++;
	}
	death_checker(data);
	return (0);
}
