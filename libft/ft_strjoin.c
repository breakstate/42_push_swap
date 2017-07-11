/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:59:39 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/05/30 13:59:41 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ptr;
	size_t	s1_len;
	size_t	s2_len;

	ptr = NULL;
	s1_len = 0;
	s2_len = 0;
	if (s1 != NULL && s2 != NULL)
	{
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		ptr = ft_strnew(s1_len + s2_len);
		if (ptr != NULL)
		{
			ft_strcpy(ptr, s1);
			ft_strlcat(ptr, s2, (s1_len + s2_len + 1));
			return (ptr);
		}
	}
	return (NULL);
}
