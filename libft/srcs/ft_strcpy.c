/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 08:45:03 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/06/21 11:48:06 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	count;

	if (src == NULL)
	{
		dest[0] = '\0';
		return (dest);
	}
	count = -1;
	while (src[++count] != '\0')
		dest[count] = src[count];
	dest[count] = '\0';
	return (dest);
}
