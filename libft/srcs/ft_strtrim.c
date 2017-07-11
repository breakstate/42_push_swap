/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 17:07:07 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/06/10 07:47:12 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*new_s;
	size_t	count;
	size_t	start;
	size_t	end;
	size_t	len;

	start = 0;
	end = 0;
	count = -1;
	while (ft_iswhitespace(s[start]))
		start++;
	len = ft_strlen(s);
	count = len;
	while (ft_iswhitespace(s[--count]))
		end++;
	if ((long)(len - start - end) < 0)
		return (ft_strnew(0));
	new_s = ft_strnew(len - start - end);
	if (!new_s)
		return (new_s);
	ft_strncpy(new_s, s + start, len - start - end);
	return (new_s);
}
