
#include "pushswap.h"

static void	comprotate(t_stack **Root, t_stack *cheapest, char sname)
{
	while (*Root != cheapest)
	{
		if (sname == 'a')
		{
			if (cheapest->abovemed)
				rotate(Root, 'a', true);
			else
				reverserotate(Root, 'a', true);
		}
		else if (sname == 'b')
		{
			if (cheapest->abovemed)
				rotate(Root, 'b', true);
			else
				reverserotate(Root, 'b', true);
		}
	}
}

void	setintop(t_stack *chaepest, t_stack **RootA, t_stack **RootB)
{
	markabovemedian(RootA);
	markabovemedian(RootB);
	if (chaepest->abovemed && chaepest->target->abovemed)
		while (*RootB != chaepest && *RootA != chaepest->target)
			rr(RootA, RootB, true);
	if (!chaepest->abovemed && !chaepest->target->abovemed)
		while (*RootB != chaepest && *RootA != chaepest->target)
			rrr(RootA, RootB, true);
	markabovemedian(RootA);
	markabovemedian(RootB);
	comprotate(RootB, chaepest, 'b');
	comprotate(RootA, chaepest->target, 'a');
}
