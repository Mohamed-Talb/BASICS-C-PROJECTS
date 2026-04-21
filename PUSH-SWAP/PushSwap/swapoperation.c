
#include "pushswap.h"

static void	s(t_stack **Root)
{
	t_stack	*temp;

	if (*Root == NULL || (*Root)->next == NULL)
		return ;
	temp = (*Root)->next;
	(*Root)->next = temp->next;
	temp->next = *Root;
	*Root = temp;
}

void	ss(t_stack **RootA, t_stack **RootB, bool print)
{
	s(RootA);
	s(RootB);
	if (print)
		write(1, "ss\n", 3);
}

void	swap(t_stack **Root, char option, bool print)
{
	if (option == 'a')
	{
		s(Root);
		if (print)
			write(1, "sa\n", 3);
	}
	else if (option == 'b')
	{
		s(Root);
		if (print)
			write(1, "sb\n", 3);
	}
}
