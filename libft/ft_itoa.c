/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 11:35:47 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/06/02 11:01:44 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(int num)
{
	int	len;

	len = 0;
	if (num == 0)
		len = 1;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static char	*ft_ptr_prep(int *len, int i)
{
	char	*ptr;

	ptr = NULL;
	if (i < 0)
	{
		if ((ptr = ft_strnew(++(*len))) != NULL)
			ptr[0] = '-';
	}
	else
		ptr = ft_strnew(*len);
	return (ptr);
}

char		*ft_itoa(int i)
{
	int		len;
	char	*ptr;

	len = ft_num_len(i);
	ptr = ft_ptr_prep(&len, i);
	if (ptr != NULL)
	{
		len--;
		while (ptr[len] != '-' && len >= 0)
		{
			ptr[len] = '0' + ft_abs(i % 10);
			i /= 10;
			len--;
		}
	}
	return (ptr);
}
