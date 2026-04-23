/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmemory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 05:12:32 by mtaleb            #+#    #+#             */
/*   Updated: 2025/02/17 10:41:33 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*memoryhexa(unsigned long n, char *base)
{
	char	*result;

	result = 0;
	while (1)
	{
		result = ft_append(result, base[n % 16], 0);
		n /= 16;
		if (!n)
			break ;
	}
	return (result);
}

char	*printmemory(void *addr)
{
	char	*ptr;

	if (!addr)
		return (NULL);
	ptr = memoryhexa((unsigned long)addr, "0123456789abcdef");
	ptr = ft_append(ptr, 'x', 0);
	ptr = ft_append(ptr, '0', 0);
	return (ptr);
}
