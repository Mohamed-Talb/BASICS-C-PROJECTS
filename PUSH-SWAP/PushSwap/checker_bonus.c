
#include "pushswap.h"

static void	executecmd(char *line, t_stack **RootA, t_stack **RootB)
{
	if (!ft_strncmp(line, "sa\n", 3))
		swap(RootA, 'a', false);
	else if (!ft_strncmp(line, "sb\n", 3))
		swap(RootB, 'b', false);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(RootA, RootB, false);
	else if (!ft_strncmp(line, "pa\n", 3))
		push(RootA, RootB, 'a', false);
	else if (!ft_strncmp(line, "pb\n", 3))
		push(RootA, RootB, 'b', false);
	else if (!ft_strncmp(line, "ra\n", 3))
		rotate(RootA, 'a', false);
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate(RootB, 'b', false);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(RootA, RootB, false);
	else if (!ft_strncmp(line, "rra\n", 4))
		reverserotate(RootA, 'a', false);
	else if (!ft_strncmp(line, "rrb\n", 4))
		reverserotate(RootB, 'b', false);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(RootA, RootB, false);
	else
		exit ((free (line), write(2, "Error\n", 6),
				lstclear(RootA), lstclear(RootA), 1));
}

static void	checker(t_stack **RootA, t_stack **RootB)
{
	char	*line;

	line = getnextline(0);
	while (line)
	{
		executecmd(line, RootA, RootB);
		free(line);
		line = getnextline(0);
	}
	free(line);
	if (issorted(RootA) == true && !*RootB)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_stack	*roota;
	t_stack	*rootb;
	int		re;

	roota = NULL;
	rootb = NULL;
	re = parsing(ac, av, &roota);
	if (re == 1)
		return (write(1, "Error\n", 6), 0);
	if (!roota || lstsize(&roota) == 1)
		return (lstclear(&roota), 0);
	checker(&roota, &rootb);
	(lstclear(&roota), lstclear(&rootb));
	return (0);
}
