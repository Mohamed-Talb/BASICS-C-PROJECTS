/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:48:57 by mtaleb            #+#    #+#             */
/*   Updated: 2025/07/26 11:09:01 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

void	safeprint(char *str, t_philo *philo)
{
	size_t	now;

	now = get_time_in_ms() - philo->data->starttime;
	pthread_mutex_lock(&philo->data->printlock);
	pthread_mutex_lock(&philo->data->death_mutex);
	if (!philo->data->dead)
	{
		printf("%ld %d %s\n", now, philo->tid, str);
	}
	pthread_mutex_unlock(&philo->data->death_mutex);
	pthread_mutex_unlock(&philo->data->printlock);
}

size_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	errors(t_data *data, char *error)
{
	ft_putstr_fd(error, 1);
	free_data(data);
}

void	manageexit(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->numofphilos)
		pthread_join(data->philos[i]->thread, NULL);
	free_data(data);
}
