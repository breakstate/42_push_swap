/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 16:09:33 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/06/09 15:31:36 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lists	*ft_lstmap(t_lists *lst, t_lists *(*f)(t_lists *elem))
{
	t_lists	*lst_head;
	t_lists	*crawler;
	t_lists	*tmp;

	tmp = NULL;
	if (lst != NULL && f != NULL)
	{
		if ((lst_head = (*f)(lst)) == NULL)
			return (NULL);
		crawler = lst_head;
		lst = lst->next;
		while (lst != NULL)
		{
			tmp = crawler;
			if ((crawler = (*f)(lst)) == NULL)
				return (NULL);
			lst = lst->next;
			tmp->next = crawler;
		}
		crawler->next = NULL;
		return (lst_head);
	}
	return (NULL);
}
