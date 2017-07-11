/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:49:40 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/05/29 11:49:43 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	chr;

	i = 0;
	chr = (unsigned char)c;
	while (s[i] != '\0' && s[i] != chr)
		i++;
	if (s[i] == chr)
		return ((char *)(s + i));
	else
		return (NULL);
}
