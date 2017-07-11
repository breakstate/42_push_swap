/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 09:13:29 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/06/20 09:14:07 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include "libft.h"

int				get_next_line(const int fd, char **line);
typedef	struct	s_buff_info
{
	int			fd;
	size_t		b_indx;
	char		buff[BUFF_SIZE + 1];
}				t_buff_info;
#endif
