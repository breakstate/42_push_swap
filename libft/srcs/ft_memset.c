/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:26:27 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/05/31 16:59:14 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*dest;

	dest = s;
	index = 0;
	while (index < n)
	{
		dest[index] = c;
		index++;
	}
	return (s);
}
