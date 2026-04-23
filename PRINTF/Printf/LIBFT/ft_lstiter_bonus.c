/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:52:26 by mtaleb            #+#    #+#             */
/*   Updated: 2024/11/07 18:25:07 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void f(void *content)
// {
//     content = 1337;
// }

// void ft_print_list(t_list *list)
// {
//     t_list *curr = list;
//     while(curr)
//     {
//         printf("%d->", *(int *)curr->content);
//         curr = curr->next;
//     }
//     printf("NULL\n");
// }

// int main()
// {
//     t_list *head = NULL;

//      int *value1 = malloc(sizeof(int));
//     *value1 = 10;
//     ft_lstadd_back_bonus(&head, ft_lstnew_bonus(value1));

//     int *value2 = malloc(sizeof(int));
//     *value2 = 20;
//     ft_lstadd_back_bonus(&head, ft_lstnew_bonus(value2));

//     int *value3 = malloc(sizeof(int));
//     *value3 = 30;
//     ft_lstadd_back_bonus(&head, ft_lstnew_bonus(value3));

//     ft_lstiter_bonus(head, f);
// 	ft_print_list(head);
// }