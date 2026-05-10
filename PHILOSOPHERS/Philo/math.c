/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:35:58 by mtaleb            #+#    #+#             */
/*   Updated: 2025/07/26 10:52:08 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initurn(int tid, int numofphilos)
{
	if ((tid % 2) != 0 && tid < numofphilos)
		return (0);
	else if (tid % 2 == 0)
		return (1);
	else if ((tid % 2) != 0 && tid == numofphilos)
		return (2);
	return (99);
}

void	predict_simulation(t_data *data)
{
	int	tid;
	int	i;

	i = 0;
	while (i < data->numofphilos)
	{
		tid = data->philos[i]->tid;
		data->philos[i]->order = initurn(tid, data->numofphilos);
		data->philos[i]->access = !(tid % 2 && tid != data->numofphilos);
		data->philos[i]->start = data->teat * data->philos[i]->order;
		if (data->tsleep > data->teat * (data->turns_nb - 1))
			data->philos[i]->duration = data->teat + data->tsleep;
		else
			data->philos[i]->duration = data->turns_nb * data->teat;
		i++;
	}
}
