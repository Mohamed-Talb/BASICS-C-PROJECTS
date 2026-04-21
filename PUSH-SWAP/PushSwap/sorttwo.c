
#include "pushswap.h"

void	sorttwo(t_stack **RootA)
{
	t_stack	*curr;

	curr = *RootA;
	if (curr->data > curr->next->data)
	{
		swap(RootA, 'a', true);
	}
	else
		return ;
}
