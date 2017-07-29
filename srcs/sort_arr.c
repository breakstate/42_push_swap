/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 11:06:11 by bmoodley          #+#    #+#             */
/*   Updated: 2017/07/23 11:18:58 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

/*
**	NOTE:
**	modified the original array, does not make a copy,
**	therefore best used after list is made from array values.
*/

void	sort_arr(int *arr, int size)
{
	int		temp;
	int		flag;
	int		i;

	i = 0;
	temp = 0;
	flag = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			flag = 1;
		}
		i++;
		if (i == size - 1 && flag == 1)
		{
			i = 0;
			flag = 0;
		}
	}
}

int main()
{
	int	*arr;
	arr = (int*)malloc(sizeof(int) * 4);
	arr[0] = 3;
	arr[1] = 4;
	arr[2] = 1;
	arr[3] = 2;
	int i = 0;
	while (i < 4)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	i = 0;
	sort_arr(arr, 4);
	printf("\n");
	while (i < 4)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	return (0);
}

