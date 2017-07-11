/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 15:52:17 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/06/09 14:51:49 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*crawler;

	if (lst != NULL && f != NULL)
	{
		crawler = lst;
		while (crawler != NULL)
		{
			(*f)(crawler);
			crawler = crawler->next;
		}
	}
}
