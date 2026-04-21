
#include "pushswap.h"

void	closestbigger(t_stack **RootA, t_stack **RootB)
{
	t_stack	*tar;
	t_stack	*curra;
	t_stack	*currb;
	long	diff;
	long	curdiff;

	currb = *RootB;
	while (currb != NULL)
	{
		(1) && (curra = *RootA, tar = curra);
		diff = LONG_MAX;
		while (curra != NULL)
		{
			if ((curra->data > currb->data) && curra->data < diff)
			{
				diff = curra->data;
				tar = curra;
			}
			curra = curra->next;
		}
		if (tar->data < currb->data)
			tar = findmin(RootA);
		currb->target = tar;
		currb = currb->next;
	}
}
