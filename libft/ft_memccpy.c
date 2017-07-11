/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:36:45 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/05/29 11:36:48 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	chr;
	size_t			i;

	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dest;
	i = 0;
	chr = (unsigned char)c;
	while (i < n)
	{
		s2[i] = s1[i];
		if (s2[i] == chr)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
