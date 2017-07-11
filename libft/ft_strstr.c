/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:17:43 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/01/23 14:23:57 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int b;
	int s;

	b = 0;
	s = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[b] != '\0')
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
