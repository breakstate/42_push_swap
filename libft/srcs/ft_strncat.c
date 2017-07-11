/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 11:38:27 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/06/01 12:07:40 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (src_len >= n)
	{
		ft_strncpy(&dest[dest_len], src, n);
		dest[dest_len + n] = '\0';
	}
	else
		ft_strcpy(&dest[dest_len], src);
	return (dest);
}
