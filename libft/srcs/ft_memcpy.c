/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:56:08 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/05/31 17:00:54 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t		index;
	char		*d;
	char const	*s;

	s = src;
	d = dest;
	index = -1;
	while (++index < count)
		(d++)[0] = (s++)[0];
	return (dest);
}
