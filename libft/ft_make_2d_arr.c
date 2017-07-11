/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_2d_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 08:43:58 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/07/03 08:50:43 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_make_2d_arr(int r_num, int r_len, size_t r_sz, size_t l_sz)
{
	int		i;
	void	**ret;

	i = 0;
	if ((ret = (void **)ft_memalloc(r_num * r_sz)) != NULL)
	{
		while (i < r_num)
		{
			if ((ret[i] = ft_memalloc(r_len * l_sz)) == NULL)
				return (NULL);
			i++;
		}
	}
	return (ret);
}
