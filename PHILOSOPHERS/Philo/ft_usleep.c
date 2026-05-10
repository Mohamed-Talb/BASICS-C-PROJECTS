/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:38:45 by mtaleb            #+#    #+#             */
/*   Updated: 2025/07/26 10:33:42 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(t_philo *philo, size_t milli, size_t start)
{
	size_t	now;

	while (1)
	{
		now = get_time_in_ms();
		pthread_mutex_lock(&(philo->data->death_mutex));
		if (philo->data->dead)
		{
			pthread_mutex_unlock(&(philo->data->death_mutex));
			return (1);
		}
		pthread_mutex_unlock(&(philo->data->death_mutex));
		if ((now - philo->lastmeal) >= philo->data->tdie)
		{
			safeprint("died", philo);
			pthread_mutex_lock(&(philo->data->death_mutex));
			philo->data->dead = 1;
			pthread_mutex_unlock(&(philo->data->death_mutex));
			return (1);
		}
		if ((now - start) >= milli)
			break ;
		usleep(200);
	}
	return (0);
}
