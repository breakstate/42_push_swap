/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:47:15 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/05/29 11:47:29 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	chr;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		ptr[i] = chr;
		i++;
	}
	return (s);
}
