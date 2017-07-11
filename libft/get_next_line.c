/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 16:40:59 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/06/19 16:58:42 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	buff_refill(char *buff, const int fd)
{
	ft_bzero(buff, BUFF_SIZE + 1);
	return (read(fd, buff, BUFF_SIZE));
}

static size_t	line_len(char *buff, size_t b_indx)
{
	size_t len;

	len = 0;
	while (buff[b_indx] != '\n' && buff[b_indx] != '\0')
	{
		b_indx++;
		len++;
	}
	return (len);
}

static int		prep(char *buff, const int fd, size_t *b_indx, int *prev_fd)
{
	if (*prev_fd != fd)
	{
		*prev_fd = fd;
		*b_indx = 0;
		return (buff_refill(buff, fd));
	}
	else
	{
		if (buff[*b_indx] == '\n')
			(*b_indx)++;
		return (BUFF_SIZE);
	}
}

static int		line_fill(char **line, char *buff, size_t *b_i, size_t *lin_i)
{
	while (buff[*b_i] != '\n' && buff[*b_i] != '\0')
		(*line)[(*lin_i)++] = buff[(*b_i)++];
	(*line)[*lin_i] = '\0';
	if (buff[*b_i] == '\n')
		return (1);
	else
		return (0);
}

int				get_next_line(const int fd, char **line)
{
	size_t				lin_indx;
	ssize_t				count;
	static t_buff_info	in = {.fd = -10};
	size_t				prev_len;
	size_t				len;

	lin_indx = 0;
	count = prep(in.buff, fd, &(in.b_indx), &(in.fd));
	prev_len = line_len(in.buff, in.b_indx) + 1;
	len = prev_len;
	if (line == NULL || !(*line = ft_strnew(len)) || count < 0)
		return (-1);
	while (line_fill(line, in.buff, &(in.b_indx), &lin_indx) == 0)
	{
		count = buff_refill(in.buff, fd);
		if ((in.b_indx = (count == 0 && *line[0] == '\0')))
			return (0);
		else if (count == 0)
			return (1);
		len += line_len(in.buff, in.b_indx);
		if (ft_realloc((void **)line, prev_len, len) == -1)
			return (-1);
		prev_len = len;
	}
	return (1);
}
