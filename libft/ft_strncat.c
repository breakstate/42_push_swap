/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:58:33 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/05/29 13:56:50 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t len;
	size_t i;

	i = 0;
	len = ft_strlen(dest);
	while (i < n)
	{
		if (src[i] == '\0')
			break ;
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}
