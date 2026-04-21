
#include "pushswap.h"

void	sortthree(t_stack **RootA)
{
	int	first;
	int	second;
	int	third;

	first = (*RootA)->data;
	second = (*RootA)->next->data;
	third = (*RootA)->next->next->data;
	if (first < second && second < third)
		return ;
	if (first > second && second > third)
	{
		swap(RootA, 'a', true);
		reverserotate(RootA, 'a', true);
	}
	else if (first > third && third > second)
		rotate(RootA, 'a', true);
	else if (second > first && first > third)
		reverserotate(RootA, 'a', true);
	else if (second > third && third > first)
	{
		swap(RootA, 'a', true);
		rotate(RootA, 'a', true);
	}
	else if (third > first && first > second)
		swap(RootA, 'a', true);
}
