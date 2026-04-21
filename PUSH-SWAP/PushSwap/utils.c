
#include "pushswap.h"

t_stack	*findmin(t_stack **Root)
{
	t_stack	*min;
	t_stack	*curr;

	if (Root == NULL)
		return (NULL);
	min = *Root;
	curr = (*Root)->next;
	while (curr != NULL)
	{
		if (curr->data < min->data)
			min = curr;
		curr = curr->next;
	}
	return (min);
}

bool	issorted(t_stack **RootA)
{
	t_stack	*curr;

	curr = *RootA;
	while (curr && curr->next)
	{
		if (curr->data > curr->next->data)
			return (false);
		curr = curr->next;
	}
	return (true);
}

void	settozero(t_stack **tstack)
{
	t_stack	*curr;

	curr = *tstack;
	while (curr)
	{
		curr->cost = 0;
		curr = curr->next;
	}
}

void	markabovemedian(t_stack **Root)
{
	int		i;
	int		median;
	t_stack	*curr;

	if (!Root)
		return ;
	median = lstsize(Root) / 2;
	curr = *Root;
	i = 0;
	while (curr)
	{
		curr->pos = i;
		if (i <= median)
			curr->abovemed = 1;
		else
			curr->abovemed = 0;
		curr = curr->next;
		i++;
	}
}

void	rank(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*comp;
	int		rank;

	if (!*stack)
		return ;
	curr = *stack;
	while (curr)
	{
		rank = 0;
		comp = *stack;
		while (comp)
		{
			if (curr->data > comp->data)
				rank++;
			comp = comp->next;
		}
		curr->rank = rank;
		curr = curr->next;
	}
}
