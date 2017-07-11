/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 12:02:16 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/06/09 12:25:50 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			len;

	len = ft_strnlen(s1, n);
	if (len + 1 > n || n == 0)
		return (ft_memcmp(s1, s2, n));
	else
		return (ft_memcmp(s1, s2, len + 1));
}
