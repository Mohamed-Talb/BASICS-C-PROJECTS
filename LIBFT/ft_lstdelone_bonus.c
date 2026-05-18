/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:52:22 by mtaleb            #+#    #+#             */
/*   Updated: 2024/11/07 18:19:23 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void del(void *content)
// {
//     if(content)
//         free(content);
// }

// int main()
// {
//     t_list *head = NULL;
//
//     int *value1 = malloc(sizeof(int));
//     *value1 = 10;
//     ft_lstadd_back_bonus(&head, ft_lstnew_bonus(value1));
//
//     int *value2 = malloc(sizeof(int));
//     *value2 = 20;
//     ft_lstadd_back_bonus(&head, ft_lstnew_bonus(value2));
//
//     int *value3 = malloc(sizeof(int));
//     *value3 = 30;
//     ft_lstadd_back_bonus(&head, ft_lstnew_bonus(value3));
//
//     printf("The list before clear: ");
//     ft_print_list(head);
//     ft_lstdelone_bonus(head, del);
//	 
//      int *value4 = malloc(sizeof(int));
//     *value4 = 40;
//     ft_lstadd_back_bonus(&head, ft_lstnew_bonus(value4));
//     printf("The list before clear: ");
//     ft_print_list(head);
//     return 0;
// }
