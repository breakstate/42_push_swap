/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:57:22 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/05/29 14:46:45 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t dlen;
	size_t slen;
	size_t i;

	i = 0;
	while (dest[i] != '\0' && i != size)
		i++;
	dlen = i;
	i = 0;
	slen = ft_strlen(src);
	while (i + dlen + 1 < size)
	{
		if (src[i] == '\0')
			break ;
		dest[dlen + i] = src[i];
		i++;
	}
	if (dlen != size)
		dest[dlen + i] = '\0';
	return (dlen + slen);
}
