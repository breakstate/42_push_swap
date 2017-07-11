/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdamhuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:05:01 by jdamhuis          #+#    #+#             */
/*   Updated: 2017/06/19 14:51:39 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isoutint(char *nbr, int sign)
{
	int		size;

	size = 0;
	while (ft_isdigit(nbr[size]))
		size++;
	if (size > 10)
	{
		if (sign == -1)
			return (0);
		if (sign == 1)
			return (-1);
	}
	return (1);
}

int			ft_atoi(const char *nbr)
{
	int		count;
	int		number;
	int		sign;
	int		check;

	count = 0;
	sign = 1;
	number = 0;
	while (ft_iswhitespace(nbr[count]))
		count++;
	if (nbr[count] == '-' || nbr[count] == '+')
	{
		if (nbr[count] == '-')
			sign = -1;
		count++;
	}
	check = ft_isoutint((char *)nbr + count, sign);
	if (check == 0 || check == -1)
		return (check);
	while (ft_isdigit(nbr[count]))
		number = (number * 10) + (nbr[count++] - '0');
	return (number * sign);
}
