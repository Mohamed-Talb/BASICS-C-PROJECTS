/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:37:25 by mtaleb            #+#    #+#             */
/*   Updated: 2025/07/26 10:15:06 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	onephilo(t_philo *philo)
{
	int	first;

	first = philo->lfork;
	pthread_mutex_lock(&philo->data->forks[first]);
	safeprint(TAKE_LFORK, philo);
	pthread_mutex_unlock(&philo->data->forks[first]);
	usleep(philo->data->tdie * 1000);
	safeprint("died", philo);
	pthread_mutex_lock(&philo->data->death_mutex);
	philo->data->dead = 1;
	pthread_mutex_unlock(&philo->data->death_mutex);
}

static void	get_dead_and_all(t_data *data, int *dead, int *all)
{
	pthread_mutex_lock(&(data->death_mutex));
	*dead = data->dead;
	pthread_mutex_unlock(&(data->death_mutex));
	pthread_mutex_lock(&(data->all_mutex));
	*all = data->all;
	pthread_mutex_unlock(&(data->all_mutex));
}

void	simulation(t_philo *philo)
{
	int	is_dead;
	int	all_done;

	while (1)
	{
		get_dead_and_all(philo->data, &is_dead, &all_done);
		if (is_dead || all_done)
			break ;
		if (philo->access == 0)
		{
			if (eating(philo))
				break ;
		}
		if (philo->access == 1 && philo->start == 0)
			sleeping(philo);
		if (philo->start)
		{
			thinking(philo, 1);
			continue ;
		}
		if (philo->duration > get_time_in_ms() - philo->lastmeal)
			thinking(philo, 2);
		philo->access = 0;
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->lastmeal = get_time_in_ms();
	if (philo->data->numofphilos == 1)
	{
		onephilo(philo);
		return (NULL);
	}
	simulation(philo);
	return (NULL);
}
