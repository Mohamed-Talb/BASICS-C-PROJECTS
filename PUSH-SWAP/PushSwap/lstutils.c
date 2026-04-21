
#include "pushswap.h"

int	lstsize(t_stack **Root)
{
	t_stack	*curr;
	int		i;

	curr = *Root;
	i = 0;
	if (*Root == NULL)
		return (0);
	while (curr != NULL)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

void	lstclear(t_stack **Root)
{
	t_stack	*curr;
	t_stack	*temp;

	curr = *Root;
	if (*Root == NULL)
		return ;
	while (curr->next != NULL)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	free(curr);
	*Root = NULL;
}

void	lstaddback(t_stack **Root, int content)
{
	t_stack	*new_node;
	t_stack	*curr;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		exit (0);
	new_node->data = content;
	new_node->next = NULL;
	if (!*Root)
	{
		*Root = new_node;
		return ;
	}
	curr = *Root;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = new_node;
}
