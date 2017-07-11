/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 12:36:50 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/06/17 17:30:04 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *src, int c)
{
	size_t	count;

	if (src == NULL)
		return (NULL);
	count = -1;
	while (src[++count] != '\0')
		if (src[count] == c)
			return ((char *)&src[count]);
	if (src[count] == c)
		return ((char *)&src[count]);
	return (NULL);
}
