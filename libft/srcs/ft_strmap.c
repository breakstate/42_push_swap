/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 08:51:24 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/06/10 06:38:18 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *str, char (*f)(char))
{
	size_t	count;
	char	*new_str;

	if (str != NULL && f != NULL)
	{
		count = -1;
		new_str = ft_strnew(ft_strlen(str));
		if (new_str)
			while (str[++count] != '\0')
				new_str[count] = (*f)(str[count]);
		return (new_str);
	}
	return (NULL);
}
