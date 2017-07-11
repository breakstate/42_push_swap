/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 12:43:48 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/06/10 07:45:07 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_s;

	new_s = ft_strnew(len);
	if (new_s == NULL)
		return (NULL);
	ft_strncpy(new_s, s + start, len);
	return (new_s);
}
