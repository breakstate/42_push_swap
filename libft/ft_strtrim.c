/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 11:03:28 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/05/31 11:54:57 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_set_pos_and_len(const char *s, int *i)
{
	int j;

	j = 0;
	while ((s[*i] == '\n' || s[*i] == ' ' || s[*i] == '\t') && s[*i] != '\0')
		*i = *i + 1;
	j = ft_strlen(s);
	while (j > 0 && (s[j] == '\n' || s[j] == ' ' || s[j] == '\t'
			|| s[j] == '\0'))
		j--;
	if (j != 0)
		j++;
	if (j < *i)
	{
		*i = 0;
		j = 0;
	}
	return (j - *i);
}

char			*ft_strtrim(const char *s)
{
	size_t	len;
	char	*ptr;
	int		i;

	i = 0;
	ptr = NULL;
	if (s != NULL)
	{
		len = ft_set_pos_and_len(s, &i);
		ptr = ft_strnew(len);
		if (ptr != NULL)
		{
			ft_memcpy((void *)(ptr), (void *)(s + i), len);
			ptr[len + 1] = '\0';
		}
	}
	return (ptr);
}
