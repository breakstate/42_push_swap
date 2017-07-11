/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:35:34 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/05/31 17:44:01 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *src, int c, size_t n)
{
	size_t		count;
	char		*s;

	s = (char *)src;
	count = -1;
	while (++count < n)
		if (s[count] == c)
			return (s + count);
	return (NULL);
}
