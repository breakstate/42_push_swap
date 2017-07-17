/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 15:42:16 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/17 17:11:44 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/includes/libft.h"

/*
**	verify_digits()
**	returns 1 if verified only digits
**	returns 0 if non-digits detected
*/

int			verify_digits(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (!(ft_isdigit(arg[i]) || ft_isspace(arg[i])))
		{
			return (0);
		}
		i++;
	}
	return (verify_dup(arg));
}

/*
**	verify_dup()
**	returns 1 if verfied no duplicates
**	returns 0 if duplicates detected
*/

int			verify_dup(char *arg)
{
	int		i;
	int		j;
	int		pos;
	char	**arr;

	arr = ft_strsplit(arg, ' ');
	i = 0;
	j = 1;
	while (arr[i])
	{
		pos = i;
		while (arr[i + j])
		{
			if (ft_strcmp(arr[i], arr[i + j]) != 0)
				j++;
			else
				return (0);
		}
		free(arr[i]);
		j = 1;
		i = pos + 1;
	}
	return (1);
}

/*
**	verify_int()
**	returns 1 if verified all elements fit into int
**	returns 0 if element > int detected
*/

int			verify_min_max(long num)
{
	int		int_high;
	int		int_low;

	int_high = 2147483647;
	int_low = -2147483648;
	if (num < int_low || num > int_high)
		return (0);
	return (1);
}

int			verify_int(char **arg)
{
	int		sign;
	int		i;
	int		j;
	long	result;

	sign = 1;
	i = 0;
	while (arg[i])
	{
		j = 0;
		result = 0;
		if (arg[i][j] == '-')
			sign = -1;
		if (arg[i][j] == '-' || arg[i][j] == '+')
			j++;
		while (arg[i][j] != '\0')
			result = ((result * 10) + (arg[i][j++] - 48));
		result = result * sign;
		if (!(verify_min_max(result)))
			return (0);
		i++;
	}
	return (1);
}

/*
**	arr_atoi() [I don't like the name, open for suggestions]
**	takes in a 2d char array and converts to int array
**	assumes checks have been done prior
**	arg_len can be determined in another function or within arr_stoi()
*/

int			arr_stoi(char **arg, t_pack *pack)
{
	int		i;

	i = 0;
	pack->elements = 0;
	while (arg[pack->elements])
		pack->elements++;
	pack->int_arr = (int *)ft_memalloc(sizeof(int) * pack->elements);
	if (pack->int_arr == NULL)
	{
		return (0);
	}
	while (arg[i])
	{
		pack->int_arr[i] = ft_atoi(arg[i]);
		i++;
	}
	return (1);
}

/*
**	notes
** 	0 is bad, 1 is good, can be reversed if preferred
**	push_swap.h modified to compile, changes not pushed
*/
