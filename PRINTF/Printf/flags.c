/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:49:57 by mtaleb            #+#    #+#             */
/*   Updated: 2025/02/17 10:35:57 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flags(char *ptr, t_flag *params)
{
	if (!ptr)
		return (NULL);
	if (params->negative == true)
		return (ft_append(ptr, '-', 0));
	else if (params->plus && !params->negative && params->specifier > 5)
	{
		return (ft_append(ptr, '+', 0));
	}
	else if (params->space && !params->negative && !params->plus
		&& params->specifier > 5 && ptr[0] != ' ')
	{
		return (ft_append(ptr, ' ', 0));
	}
	else if (params->hashtag && params->specifier == 4)
	{
		ptr = ft_append(ptr, '0', 0);
		return (ft_append(ptr, 'x', 1));
	}
	else if (params->hashtag && params->specifier == 5)
	{
		ptr = ft_append(ptr, '0', 0);
		return (ft_append(ptr, 'X', 1));
	}
	return (ptr);
}
