
#include "pushswap.h"

static void	rer(t_stack **Root)
{
	t_stack	*temp;
	t_stack	*curr;

	if (*Root == NULL || (*Root)->next == NULL)
		return ;
	curr = *Root;
	while (curr->next->next != NULL)
	{
		curr = curr->next;
	}
	temp = curr->next;
	curr->next = NULL;
	temp->next = *Root;
	*Root = temp;
}

void	rrr(t_stack **RootA, t_stack **RootB, bool print)
{
	rer(RootA);
	rer(RootB);
	if (print)
		write(1, "rrr\n", 4);
}

void	reverserotate(t_stack **Root, char option, bool print)
{
	if (option == 'a')
	{
		rer(Root);
		if (print)
			write(1, "rra\n", 4);
	}
	else if (option == 'b')
	{
		rer(Root);
		if (print)
			write(1, "rrb\n", 4);
	}
}
// option 'a':rra The last element from A becomes the first one.
// option 'b':rrb The last element from B becomes the first one.