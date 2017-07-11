/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 09:11:31 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/06/19 11:05:32 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	count;
	char			*new_str;

	if (str != NULL && f != NULL)
	{
		new_str = ft_strnew(ft_strlen(str));
		if (!new_str)
			return (NULL);
		count = -1;
		while (str[++count] != '\0')
			new_str[count] = (*f)(count, str[count]);
		return (new_str);
	}
	return (NULL);
}
