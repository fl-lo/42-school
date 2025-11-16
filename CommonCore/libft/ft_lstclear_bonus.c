/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahhhhh <nahhhhh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:44:27 by nahhhhh           #+#    #+#             */
/*   Updated: 2025/11/16 17:54:33 by nahhhhh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*org_lst;
	t_list	*temp_lst;

	if (!lst || !del)
		return ;
	org_lst = *lst;
	while (org_lst)
	{
		temp_lst = org_lst;
		org_lst = org_lst->next;
		del(temp_lst->content);
		free(temp_lst);
	}
	*lst = NULL;
}
