/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:50:28 by mtaleb            #+#    #+#             */
/*   Updated: 2025/02/17 10:32:36 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

long	ft_pratoi(char **nptr)
{
	long	result;

	result = 0;
	while (ft_isdigit(**nptr) && result < 2147483648)
	{
		result = result * 10 + **nptr - '0';
		(*nptr)++;
	}
	return (result);
}
