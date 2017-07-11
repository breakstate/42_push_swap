/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 13:28:06 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/06/10 06:14:48 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*cmp1;
	unsigned char	*cmp2;

	cmp1 = (unsigned char *)s1;
	cmp2 = (unsigned char *)s2;
	while (*cmp2 == *cmp1)
	{
		if (*cmp1 == '\0')
			return (0);
		cmp1++;
		cmp2++;
	}
	return (*cmp1 - *cmp2);
}
