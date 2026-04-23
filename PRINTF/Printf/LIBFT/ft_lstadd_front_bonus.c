/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:52:12 by mtaleb            #+#    #+#             */
/*   Updated: 2024/11/07 18:24:46 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

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

//     int *value1 = malloc(sizeof(int));
//     *value1 = 10;
//     ft_lstadd_front_bonus(&head, ft_lstnew(value1));

//     int *value2 = malloc(sizeof(int));
//     *value2 = 20;
//     ft_lstadd_front_bonus(&head, ft_lstnew(value2));

//     int *value3 = malloc(sizeof(int));
//     *value3 = 30;
//     ft_lstadd_front_bonus(&head, ft_lstnew(value3));
//     ft_print_list(head);
// }
