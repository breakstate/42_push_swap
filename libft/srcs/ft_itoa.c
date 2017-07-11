/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 16:07:18 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/06/27 08:49:59 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa2(int count, char *alpha, int n, int sign)
{
	alpha = (char *)malloc(sizeof(char) * count + 1);
	if (alpha == NULL)
		return (NULL);
	if (sign == -1)
		alpha[0] = '-';
	alpha[count--] = '\0';
	while (n != 0)
	{
		alpha[count--] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
	}
	return (alpha);
}

char		*ft_itoa(int n)
{
	int		org_n;
	int		count;
	char	*alpha;
	int		sign;

	alpha = NULL;
	if (ft_isintmin(n))
		return (ft_strcpy(ft_strnew(11), "-2147483647"));
	else if (n == 0)
		return (ft_strcpy(ft_strnew(1), "0"));
	org_n = n;
	count = 0;
	sign = 1;
	if (org_n < 0)
	{
		sign = -1;
		count++;
	}
	while (org_n != 0)
	{
		org_n = ft_abs(org_n / 10);
		count++;
	}
	alpha = ft_itoa2(count, alpha, n, sign);
	return (alpha);
}
