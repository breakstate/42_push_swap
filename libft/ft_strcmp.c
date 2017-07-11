/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 09:20:43 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/06/02 11:59:44 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*p1;
	unsigned char	*p2;
	int				i;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while (p1[i] != '\0')
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (p1[i] - p2[i]);
}
