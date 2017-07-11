/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:45:30 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/05/29 11:46:46 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dest;
	if (dest != src)
	{
		if (dest > src)
		{
			i = n - 1;
			while (i >= 0)
			{
				s2[i] = s1[i];
				i--;
			}
		}
		else
			ft_memcpy(dest, src, n);
	}
	return (dest);
}
