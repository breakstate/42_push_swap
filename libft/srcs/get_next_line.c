/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 10:24:59 by sdube             #+#    #+#             */
/*   Updated: 2017/06/27 12:13:53 by jdamhuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		read_to_storage(int const fd, char **storage)
{
	char	*buffer;
	char	*tmp;
	int		bytes_read;

	if (!(buffer = (char *)malloc(sizeof(*buffer) * (BUFF_SIZE + 1))))
		return (-1);
	bytes_read = read(fd, buffer, BUFF_SIZE);
	if (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(*storage, buffer);
		free(*storage);
		*storage = tmp;
	}
	free(buffer);
	return (bytes_read);
}

int				get_next_line(int const fd, char **line)
{
	static char	*storage = NULL;
	char		*new_line;
	int			bytes_read;

	if ((!storage && (storage = (char *)malloc(sizeof(*storage))) == NULL)
			|| !line || fd < 0 || BUFF_SIZE < 0)
		return (-1);
	new_line = ft_strchr(storage, '\n');
	while (new_line == NULL)
	{
		bytes_read = read_to_storage(fd, &storage);
		if (bytes_read == 0)
		{
			if (ft_strlen(storage) == 0)
				return (0);
			storage = ft_strjoin(storage, "\n");
		}
		if (bytes_read < 0)
			return (-1);
		else
			new_line = ft_strchr(storage, '\n');
	}
	*line = ft_strsub(storage, 0, ft_strlen(storage) - ft_strlen(new_line));
	storage = ft_strdup(new_line + 1);
	return (1);
}
