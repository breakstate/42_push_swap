/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 09:51:02 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/05/30 12:36:38 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*ptr;

	ptr = NULL;
	if (s != NULL)
	{
		ptr = ft_strnew(len);
		if (ptr != NULL)
		{
			ft_memcpy((void *)ptr, (void *)(s + start), len);
			return (ptr);
		}
	}
	return (NULL);
}
