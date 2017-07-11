/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 12:52:10 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/06/02 16:00:48 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = ft_memalloc(sizeof(t_list));
	if (new != NULL)
	{
		new->next = NULL;
		if (content == NULL)
		{
			new->content_size = 0;
			new->content = NULL;
		}
		else
		{
			if ((new->content = ft_memalloc(content_size)) != NULL)
			{
				ft_memcpy(new->content, content, content_size);
				new->content_size = content_size;
			}
			else
				ft_memdel((void **)&new);
		}
	}
	return (new);
}
