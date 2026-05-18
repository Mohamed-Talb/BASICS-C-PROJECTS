/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:52:39 by mtaleb            #+#    #+#             */
/*   Updated: 2024/11/07 19:50:43 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

// void *f(void *content)
// {
//     *(int *)content = *(int *)content * 2;
// }

// void del(void *content) 
// {
//     free(content);
// }

// void print_list(t_list *list)
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
//{
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

//     printf("Original list: ");
//     print_list(head);

//     t_list *new_list = ft_lstmap_bonus(head, f, del);

//     printf("Mapped list: ");
//     print_list(new_list);

//     return 0;
// }