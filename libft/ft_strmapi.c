/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:58:19 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/05/29 13:55:42 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	str = NULL;
	if (s != NULL)
	{
		len = ft_strlen(s);
		str = ft_strnew(len);
		if (str != NULL)
		{
			while (i < len)
			{
				str[i] = (*f)(i, s[i]);
				i++;
			}
		}
	}
	return (str);
}
