
#include "pushswap.h"

t_stack	*cheapest(t_stack **Root)
{
	t_stack	*curr;
	t_stack	*cheapest;
	int		smallercost;

	curr = *Root;
	cheapest = curr;
	smallercost = curr->cost;
	while (curr != NULL)
	{
		if (smallercost > curr->cost)
		{
			smallercost = curr->cost;
			cheapest = curr;
		}
		curr = curr->next;
	}
	return (cheapest);
}

static void	exactcost(t_stack **SrcStack, t_stack **DestStack)
{
	int		size;
	int		ncost;
	int		tcost;
	t_stack	*curr;

	markabovemedian(SrcStack);
	markabovemedian(DestStack);
	curr = *SrcStack;
	while (curr != NULL)
	{
		(1) && (ncost = curr->cost);
		(1) && (tcost = curr->target->cost);
		curr->cost = ncost + tcost;
		if ((curr->abovemed && curr->target->abovemed) || (!curr->abovemed
				&& !curr->target->abovemed))
		{
			curr->cost = (ncost * (ncost > tcost) + tcost * (ncost <= tcost));
		}
		curr = curr->next;
	}
	settozero(DestStack);
}

void	cost(t_stack **SrcStack, t_stack **DestStack)
{
	t_stack	*curr;
	int		size;

	markabovemedian(SrcStack);
	markabovemedian(DestStack);
	(1) && (size = lstsize(SrcStack), curr = *SrcStack);
	while (curr != NULL && curr->pos <= size)
	{
		if (curr->abovemed)
			curr->cost = curr->pos;
		else
			curr->cost = size - curr->pos;
		curr = curr->next;
	}
	(1) && (size = lstsize(DestStack), curr = *DestStack);
	while (curr != NULL && curr->pos <= size)
	{
		if (curr->abovemed)
			curr->cost = curr->pos;
		else
			curr->cost = size - curr->pos;
		curr = curr->next;
	}
	exactcost(SrcStack, DestStack);
}
