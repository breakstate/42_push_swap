/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 13:03:37 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/06/10 05:17:21 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t	hay_len;
	size_t	need_len;
	size_t	count;

	if (!*needle)
		return ((char *)haystack);
	hay_len = ft_strlen(haystack);
	need_len = ft_strlen(needle);
	count = -1;
	while (haystack[++count] != '\0' && count <= (hay_len - need_len))
		if (haystack[count] == needle[0])
			if (ft_strncmp(&haystack[count], needle, need_len) == 0)
				return ((char *)&haystack[count]);
	return (NULL);
}
