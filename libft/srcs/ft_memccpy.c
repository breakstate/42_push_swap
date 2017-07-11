/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 09:29:29 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/06/10 02:39:10 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			count;
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	letter;

	letter = (unsigned char)c;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	count = -1;
	while (++count < n)
	{
		d[count] = s[count];
		if (d[count] == letter)
			return (&d[++count]);
	}
	return (NULL);
}
