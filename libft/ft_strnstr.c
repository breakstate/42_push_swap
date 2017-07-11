/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 12:01:41 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/05/29 12:01:43 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int b;
	unsigned int s;

	b = 0;
	s = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[b] != '\0' && b + s < len)
	{
		if (haystack[b + s] == needle[s])
			s++;
		else
		{
			s = 0;
			b++;
		}
		if (needle[s] == '\0')
			return ((char *)(haystack + b));
	}
	return (NULL);
}
