/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:58:11 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/05/29 13:57:11 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
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
				str[i] = (*f)(s[i]);
				i++;
			}
		}
	}
	return (str);
}
