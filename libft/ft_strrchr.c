/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:59:45 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/05/29 12:01:30 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	chr;

	i = ft_strlen(s);
	chr = (unsigned char)c;
	while (i >= 0 && s[i] != chr)
		i--;
	if (s[i] == chr)
		return ((char *)(s + i));
	else
		return (NULL);
}
