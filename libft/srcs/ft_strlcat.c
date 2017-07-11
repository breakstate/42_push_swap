/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 03:35:12 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/06/10 03:50:35 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	dest_len;

	count = 0;
	while (dest[count] && count < size)
		count++;
	dest_len = count;
	if (count == size)
		return (dest_len + ft_strlen(src));
	while (src[count - dest_len] && count < (size - 1))
	{
		dest[count] = src[count - dest_len];
		count++;
	}
	if (dest_len < size)
		dest[count] = '\0';
	return (dest_len + ft_strlen(src));
}
