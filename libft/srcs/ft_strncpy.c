/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 10:11:19 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/06/07 15:44:00 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	count;

	count = -1;
	while (++count < n && src[count] != '\0')
		dest[count] = src[count];
	while (count < n)
		dest[count++] = '\0';
	return (dest);
}
