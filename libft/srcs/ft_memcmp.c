/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:10:20 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/06/06 13:23:18 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			count;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	count = -1;
	while (++count < n)
		if (s1[count] != s2[count])
			return (s1[count] - s2[count]);
	return (0);
}
