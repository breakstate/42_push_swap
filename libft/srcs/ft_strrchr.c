/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 12:44:20 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/06/10 03:23:39 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	count_end;

	count_end = ft_strlen(s) + 1;
	while (count_end--)
		if (s[count_end] == c)
			return ((char *)(s + count_end));
	return (NULL);
}
