/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:47:45 by takaito           #+#    #+#             */
/*   Updated: 2024/12/19 15:47:47 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

/*
void ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*target;
	t_list	*next_p;

	if (lst == NULL || del == NULL)
		return ;
	target = (t_list *)del;
	while (lst != NULL)
	{
		if (lst == target)
		{
			if (target->next == NULL)
				next_p = NULL;
			else
				next_p = target->next;
			lst->next = next_p;
			free(target);
		}
		lst = lst->next;
	}
}
*/