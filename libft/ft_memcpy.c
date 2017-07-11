/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:42:44 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/05/29 11:44:15 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	return (dest);
}
