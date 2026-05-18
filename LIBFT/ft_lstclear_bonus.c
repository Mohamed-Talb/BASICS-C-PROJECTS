/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:52:17 by mtaleb            #+#    #+#             */
/*   Updated: 2024/11/07 18:20:14 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}

// int main()
// {
//     t_list *head = NULL;
//     int *value1 = malloc(sizeof(int));
//     *value1 = 10;
//     ft_lstadd_back_bonus(&head, ft_lstnew(value1));
//
//     int *value2 = malloc(sizeof(int));
//     *value2 = 20;
//     ft_lstadd_back_bonus(&head, ft_lstnew(value2));
//
//     int *value3 = malloc(sizeof(int));
//     *value3 = 30;
//     ft_lstadd_back_bonus(&head, ft_lstnew(value3));
//
//     printf("the list befor clear: ");
//     ft_print_list(head);
//   
//     ft_lstclear_bonus(&head, del);
//	
//    	int *value = malloc(sizeof(int));
//     *value = 30;
// 	ft_lstadd_back_bonus(&head, ft_lstnew(value));
//     printf("the list after clear: ");
//     ft_print_list(head);
// }
