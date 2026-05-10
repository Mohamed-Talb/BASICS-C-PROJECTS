/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:34:21 by mtaleb            #+#    #+#             */
/*   Updated: 2025/07/26 10:11:23 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	r_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->forks[philo->lfork]);
	pthread_mutex_unlock(&philo->data->forks[philo->rfork]);
}

void	take_forks(t_philo *philo)
{
	int	first;
	int	second;

	first = philo->lfork;
	second = philo->rfork;
	if (first > second)
	{
		first = philo->rfork;
		second = philo->lfork;
	}
	pthread_mutex_lock(&philo->data->forks[first]);
	safeprint(TAKE_LFORK, philo);
	pthread_mutex_lock(&philo->data->forks[second]);
	safeprint(TAKE_RFORK, philo);
}

void	thinking(t_philo *philo, int ch)
{
	int	stime;

	if (ch == 1)
	{
		safeprint("is thinking", philo);
		ft_usleep(philo, philo->start, get_time_in_ms());
		philo->start = 0;
		philo->access = 0;
	}
	if (ch == 2)
	{
		stime = (philo->duration - (get_time_in_ms() - philo->lastmeal));
		safeprint("is thinking", philo);
		ft_usleep(philo, stime, get_time_in_ms());
	}
}

void	sleeping(t_philo *philo)
{
	safeprint("is sleeping", philo);
	ft_usleep(philo, philo->data->tsleep, get_time_in_ms());
}

int	eating(t_philo *philo)
{
	take_forks(philo);
	safeprint("is eating", philo);
	philo->lastmeal = get_time_in_ms();
	if (ft_usleep(philo, philo->data->teat, get_time_in_ms()))
	{
		r_forks(philo);
		return (1);
	}
	r_forks(philo);
	pthread_mutex_lock(&(philo->data->xeat_mutex));
	philo->xeat++;
	pthread_mutex_unlock(&(philo->data->xeat_mutex));
	philo->access = 1;
	return (0);
}
