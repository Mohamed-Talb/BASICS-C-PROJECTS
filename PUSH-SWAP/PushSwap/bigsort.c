
#include "pushswap.h"

static void	lastmove(t_stack **RootA)
{
	t_stack	*mina;
	t_stack	*maxa;

	mina = findmin(RootA);
	markabovemedian(RootA);
	while (mina->pos != 0)
	{
		reverserotate(RootA, 'a', true);
		markabovemedian(RootA);
	}
}

static void	getcurrrank(t_stack **RootA, t_stack **RootB)
{
	int	med;

	rank(RootA);
	med = lstsize(RootA) / 3;
	while ((*RootA)->rank > med)
		rotate(RootA, 'a', true);
}

void	bigsort(t_stack **RootA, t_stack **RootB)
{
	int		size;
	t_stack	*node;

	size = lstsize(RootA);
	while (size > 3)
	{
		getcurrrank(RootA, RootB);
		push(RootA, RootB, 'b', true);
		size--;
	}
	sortthree(RootA);
	size = lstsize(RootB);
	while (size > 0)
	{
		markabovemedian(RootB);
		closestbigger(RootA, RootB);
		cost(RootB, RootA);
		node = cheapest(RootB);
		setintop(node, RootA, RootB);
		push(RootA, RootB, 'a', true);
		size--;
	}
	lastmove(RootA);
}
