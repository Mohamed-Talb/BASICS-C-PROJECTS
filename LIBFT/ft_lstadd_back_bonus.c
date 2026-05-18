/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:52:06 by mtaleb            #+#    #+#             */
/*   Updated: 2024/11/07 18:13:02 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*curr;

	curr = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
}

// void print_list(t_list *lst) 
// {
//     while (lst != NULL) {
//         printf("%d -> ", *(int *)lst->content);
//         lst = lst->next;
//     }
//     printf("NULL\n");
// }

// int main()
// {
//     t_list *head = NULL;
//
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
//     print_list(head);
//     return 0;
// }
