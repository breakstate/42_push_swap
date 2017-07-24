/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 10:41:28 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/06/02 11:48:40 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_str_cnt(const char *s, char c)
{
	int		i;
	int		str_cnt;
	char	in_str;

	str_cnt = 0;
	in_str = FALSE;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && in_str != TRUE)
		{
			str_cnt++;
			in_str = TRUE;
		}
		else if (s[i] == c)
			in_str = FALSE;
		i++;
	}
	return (str_cnt);
}

static size_t	*ft_str_lens(const char *s, char c, int str_cnt)
{
	size_t	*lens;
	int		i;
	char	is_str;
	int		b;

	i = -1;
	b = 0;
	is_str = FALSE;
	if ((lens = (size_t *)ft_memalloc(sizeof(size_t) * str_cnt + 1)) == NULL)
		return (NULL);
	while (s[++i] != '\0')
	{
		if (s[i] != c)
		{
			lens[b]++;
			is_str = TRUE;
		}
		else if (s[i] == c && is_str == TRUE)
		{
			b++;
			is_str = FALSE;
		}
	}
	return (lens);
}

static char		**ft_aloc_str_list(int str_cnt, size_t *len, const char *s,
									char c)
{
	char	**arr;
	int		i;
	char	in_str;
	int		b;

	i = -1;
	b = -1;
	in_str = FALSE;
	if ((arr = (char **)ft_memalloc(sizeof(char *) * (str_cnt + 1))) == NULL)
		return (NULL);
	while (s[++i] != '\0')
	{
		if (s[i] != c && in_str == FALSE)
		{
			++b;
			if ((arr[b] = ft_strnew(len[b])) != NULL)
				ft_memcpy(arr[b], s + i, len[b]);
			in_str = TRUE;
		}
		else if (s[i] == c && in_str == TRUE)
			in_str = FALSE;
	}
	return (arr);
}

char			**ft_strsplit(const char *s, char c)
{
	int		str_cnt;
	size_t	*len;
	char	**words;

	if (s == NULL)
		return (0);
	str_cnt = ft_str_cnt(s, c);
	len = ft_str_lens(s, c, str_cnt);
	words = ft_aloc_str_list(str_cnt, len, s, c);
	free(len);
	return (words);
}
