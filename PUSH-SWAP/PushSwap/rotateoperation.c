
#include "pushswap.h"

static void	r(t_stack **Root)
{
	t_stack	*temp;
	t_stack	*curr;

	if (*Root == NULL || (*Root)->next == NULL)
		return ;
	temp = (*Root)->next;
	curr = *Root;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = *Root;
	(*Root)->next = NULL;
	*Root = temp;
}

void	rr(t_stack **RootA, t_stack **RootB, bool print)
{
	r(RootA);
	r(RootB);
	if (print)
		write(1, "rr\n", 3);
}

void	rotate(t_stack **Root, char option, bool print)
{
	if (option == 'a')
	{
		r(Root);
		if (print)
			write(1, "ra\n", 3);
	}
	else if (option == 'b')
	{
		r(Root);
		if (print)
			write(1, "rb\n", 3);
	}
}
// option 'a': ra The first in A element becomes the last one.
// option 'b': rb The first in B element becomes the last one