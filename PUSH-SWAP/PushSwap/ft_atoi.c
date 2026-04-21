
#include "pushswap.h"

int	ft_atoi(const char *nptr, t_flags *params)
{
	int			sign;
	long int	r;
	int			i;

	(1) && (i = 0, r = 0, sign = 1);
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	if ((nptr[i] < '0' || nptr[i] > '9'))
		return (params->charflag = true, 0);
	while (nptr[i])
	{
		if ((nptr[i] < '0' || nptr[i] > '9'))
			return (params->charflag = true, 0);
		r = r * 10 + nptr[i] - '0';
		i++;
	}
	if ((r * sign) > INT_MAX || (r * sign) < INT_MIN)
		return (params->charflag = true, 0);
	return (r * sign);
}
