/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 17:43:55 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/06/22 09:11:19 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_word_count(char *s, char c)
{
	int words;

	while (*s && *s == c)
		s++;
	words = (*s) ? 1 : 0;
	while (*s)
		if (*s++ == c && *s && *s != c)
			++words;
	return (words);
}

char		**ft_strsplit(const char *src, char c)
{
	int		words;
	char	*start;
	char	**ret;

	words = ft_word_count((char *)src, c);
	if (!src || !c)
		return (NULL);
	ret = (char **)malloc(sizeof(char *) * (words + 1));
	start = (char *)src;
	while (*src)
	{
		if (*src == c)
		{
			if (start != src)
				*(ret++) = ft_strsub(start, 0, src - start);
			start = (char *)src + 1;
		}
		src++;
	}
	if (start != src)
		*(ret++) = ft_strsub(start, 0, src - start);
	*ret = NULL;
	return (ret - words);
}
