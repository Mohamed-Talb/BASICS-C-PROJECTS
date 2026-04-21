
#include "pushswap.h"

int	main(int ac, char **av)
{
	t_stack	*roota;
	t_stack	*rootb;
	int		re;
	int		size;

	roota = NULL;
	rootb = NULL;
	re = parsing(ac, av, &roota);
	if (re == 1)
		return (write(2, "Error\n", 6), 0);
	if (!roota || issorted(&roota) || lstsize(&roota) == 1)
		return (0);
	size = lstsize(&roota);
	if (size == 2)
		sorttwo(&roota);
	else if (size == 3)
		sortthree(&roota);
	else if (size > 3)
		bigsort(&roota, &rootb);
	lstclear(&roota);
	lstclear(&rootb);
	return (0);
}
