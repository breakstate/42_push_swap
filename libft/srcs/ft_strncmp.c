/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 13:36:07 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/06/10 06:02:55 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*cmp1;
	unsigned char	*cmp2;

	cmp1 = (unsigned char *)(s1 - 1);
	cmp2 = (unsigned char *)(s2 - 1);
	while ((n) && *(++cmp1) == *(++cmp2) && *cmp1 && cmp2)
		n--;
	return (*cmp1 - *cmp2);
}
