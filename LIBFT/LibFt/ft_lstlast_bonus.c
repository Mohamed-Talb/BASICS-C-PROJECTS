/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:52:34 by mtaleb            #+#    #+#             */
/*   Updated: 2024/11/07 18:10:45 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list		*curr;

	if (!lst)
		return (NULL);
	curr = lst;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	return (curr);
}

// int main()
// {
//     t_list *head = NULL;

//     int *value1 = malloc(sizeof(int));
//     *value1 = 10;
//     ft_lstadd_back_bonus(&head, ft_lstnew(value1));

//     int *value2 = malloc(sizeof(int));
//     *value2 = 20;
//     ft_lstadd_back_bonus(&head, ft_lstnew(value2));

//     int *value3 = malloc(sizeof(int));
//     *value3 = 30;
//     ft_lstadd_back_bonus(&head, ft_lstnew(value3));

//     printf("%d\n: ",*(int *)ft_lstlast_bonus(head)->content);  
// }