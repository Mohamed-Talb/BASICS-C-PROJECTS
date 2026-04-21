
#include "pushswap.h"

static void	p(t_stack **Src, t_stack **Dest)
{
	t_stack	*tempsrc;

	if (*Src == NULL)
		return ;
	tempsrc = *Src;
	*Src = (*Src)->next;
	tempsrc->next = *Dest;
	*Dest = tempsrc;
}

void	push(t_stack **RootA, t_stack **RootB, char option, bool print)
{
	if (option == 'a')
	{
		p(RootB, RootA);
		if (print)
			write(1, "pa\n", 3);
	}
	else if (option == 'b')
	{
		p(RootA, RootB);
		if (print)
			write(1, "pb\n", 3);
	}
}
// option 'a': pa push the first element from b to a
// option 'b': pb push the first element from a to b