/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:53:52 by mtaleb            #+#    #+#             */
/*   Updated: 2025/02/17 10:30:53 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*printhexa(unsigned int n, char *base, t_flag *params)
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
	if (result[0] == '0')
		params->hashtag = false;
	return (result);
}
