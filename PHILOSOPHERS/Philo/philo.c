/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:57:26 by mtaleb            #+#    #+#             */
/*   Updated: 2025/07/25 15:19:07 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (init_data(data))
		return (1);
	if (parse(ac, av, data))
		return (1);
	if (initphilo(data))
		return (1);
	if (initforks(data))
		return (1);
	if (start(data))
		return (1);
	manageexit(data);
	return (0);
}
