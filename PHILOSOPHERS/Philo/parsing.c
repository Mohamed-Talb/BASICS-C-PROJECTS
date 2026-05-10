/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:32:38 by mtaleb            #+#    #+#             */
/*   Updated: 2025/07/25 15:27:28 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

size_t	sizet_atoi(const char *nptr)
{
	size_t	r;
	int		sign;
	int		i;

	i = 0;
	r = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r = r * 10 + nptr[i] - '0';
		i++;
	}
	return (r * sign);
}

static int	is_number(const char *str)
{
	if (!str || *str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static void	getvalue(int i, t_data *data, int value)
{
	if (i == 1)
		data->numofphilos = value;
	else if (i == 2)
		data->tdie = value;
	else if (i == 3)
		data->teat = value;
	else if (i == 4)
		data->tsleep = value;
	else if (i == 5)
		data->mealsrequired = value;
}

int	parse(int ac, char **av, t_data *data)
{
	size_t	value;
	int		i;

	i = 1;
	if (ac != 5 && ac != 6)
		return (errors(data, ERR_INVALID_ARG_COUNT), 1);
	while (i < ac)
	{
		if (!is_number(av[i]))
			return (errors(data, ERR_NON_NUMERIC_ARG), 1);
		value = sizet_atoi(av[i]);
		if (value == 0)
			return (errors(data, ERR_ARG_ZERO_OR_NEGATIVE), 1);
		getvalue(i, data, value);
		i++;
	}
	if (ac == 5)
		data->mealsrequired = -1;
	return (0);
}
