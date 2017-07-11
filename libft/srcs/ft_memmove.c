/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 09:43:53 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/06/10 02:46:09 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dest == src)
		return (dest);
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	while ((long)--n >= 0)
	{
		if (s < d)
			*(d + n) = *(s + n);
		else
			*(d++) = *(s++);
	}
	return (d);
}
