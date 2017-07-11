/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:17:47 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/06/21 13:05:53 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		new_len;
	char		*new;

	new_len = ft_strlen(s1) + ft_strlen(s2);
	new = ft_strnew(new_len);
	if (new != NULL)
	{
		new = ft_strcpy(new, s1);
		new = ft_strcat(new, s2);
	}
	return (new);
}
