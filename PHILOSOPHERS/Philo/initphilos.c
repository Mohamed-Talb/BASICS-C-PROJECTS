/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initphilos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:39:04 by mtaleb            #+#    #+#             */
/*   Updated: 2025/07/26 09:58:37 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	helper(t_philo *philo, int i)
{
	philo->tid = i + 1;
	philo->lastmeal = -1;
	philo->rfork = -1;
	philo->lfork = -1;
	philo->xeat = 0;
	philo->order = 0;
	philo->access = 0;
	philo->duration = 0;
	philo->start = 0;
	return (0);
}

int	initphilo(t_data *data)
{
	int	i;

	i = 0;
	data->turns_nb = data->numofphilos % 2 + 2;
	data->philos = malloc(sizeof(t_philo *) * (data->numofphilos + 1));
	if (!data->philos)
		return (errors(data, MALLOC_ERROR), 1);
	while (i < data->numofphilos)
	{
		data->philos[i] = malloc(sizeof(t_philo));
		if (!data->philos[i])
			return (errors(data, MALLOC_ERROR), 1);
		if (helper(data->philos[i], i))
			return (1);
		data->philos[i]->data = data;
		i++;
	}
	data->philos[i] = NULL;
	return (0);
}
