/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:00:56 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/06/19 11:16:43 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	char	*check;
	char	*buffer;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (!haystack || !needle || !needle_len)
		return ((char *)haystack);
	buffer = (char *)(haystack + n);
	check = (char *)haystack;
	while ((check = ft_strchr(check, *needle)) && check <= buffer)
	{
		if ((check + needle_len <= buffer)
				&& !ft_strncmp(check, needle, needle_len))
			return (check);
		check++;
	}
	return (NULL);
}
