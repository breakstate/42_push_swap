/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 12:04:30 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/06/09 14:47:25 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skip_wsp_set_sign(const char *nptr, int *sign, int *i)
{
	int leading_chars;

	leading_chars = 0;
	while (ft_isspace(nptr[*i]))
	{
		(*i)++;
		leading_chars++;
	}
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			*sign = -1;
		leading_chars++;
		(*i)++;
	}
	while (nptr[*i] == '0')
	{
		(*i)++;
		leading_chars++;
	}
	return (leading_chars);
}

int			ft_atoi(const char *nptr)
{
	int	i;
	int	num;
	int	sign;
	int	leading_chars;

	sign = 1;
	i = 0;
	leading_chars = ft_skip_wsp_set_sign(nptr, &sign, &i);
	num = 0;
	while (nptr[i] != '\0' && ft_isdigit(nptr[i]))
	{
		num *= 10;
		num += (int)(nptr[i] - 48);
		i++;
	}
	if (sign == 1 && (i - leading_chars) > 19)
		return (-1);
	if (sign == -1 && (i - leading_chars) > 19)
		return (0);
	return (num * sign);
}
