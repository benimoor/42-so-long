/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 18:58:42 by hohayrap          #+#    #+#             */
/*   Updated: 2022/06/18 19:58:20 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_get_line(char *buffer)
{
	char	*line;
	int		index;

	index = 0;
	while (buffer && buffer[index] && buffer[index] != '\n')
		++index;
	line = malloc(index + 2);
	if (!buffer || !line)
		return (NULL);
	index = 0;
	while (buffer && buffer[index] && buffer[index] != '\n')
	{
		line[index] = buffer[index];
		++index;
	}
	line[index++] = '\n';
	line[index] = '\0';
	return (line);
}

char	*gnl_get_buffer(char *buffer)
{
	char	*change;
	size_t	size;
	int		index;
	int		c_index;

	index = 0;
	if (!buffer)
		return (NULL);
	while (buffer[index] && buffer[index] != '\n')
		++index;
	if (!buffer[index])
		free(buffer);
	if (!buffer[index])
		return (NULL);
	size = ft_gnl_strlen(buffer) - index;
	change = malloc(sizeof(char) * (size + 1));
	if (!change)
		return (NULL);
	++index;
	c_index = 0;
	while (buffer[index])
		change[c_index++] = buffer[index++];
	change[c_index] = '\0';
	free(buffer);
	return (change);
}

void	norm_fx(int fd, int *read_return, t_get_gnl_line	*gnl)
{
	while (1)
	{
		*read_return = read(fd, gnl->buffer, BUFFER_SIZE);
		if (*read_return <= 0)
			return ;
		gnl->buffer[*read_return] = '\0';
		gnl->fd_buffer[fd] = ft_gnl_strjoin(gnl->fd_buffer[fd], gnl->buffer);
		if (ft_gnl_strchr(gnl->fd_buffer[fd], '\n')
			|| ft_gnl_strchr(gnl->fd_buffer[fd], '\0'))
			return ;
	}
}

int	get_next_line(int fd, char **line)
{
	int						read_return;
	static t_get_gnl_line	gnl;

	gnl.buffer = 0;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	gnl.buffer = malloc(BUFFER_SIZE + 1);
	if (!gnl.buffer)
		return (-1);
	norm_fx(fd, &read_return, &gnl);
	free(gnl.buffer);
	gnl.buffer = 0;
	if (read_return < 0)
		return (-1);
	*line = gnl_get_line(gnl.fd_buffer[fd]);
	gnl.fd_buffer[fd] = gnl_get_buffer(gnl.fd_buffer[fd]);
	if (!read_return && !*line)
	{
		free(gnl.fd_buffer[fd]);
		return (0);
	}
	return (1);
}
