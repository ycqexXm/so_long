/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:23:02 by yorlians          #+#    #+#             */
/*   Updated: 2023/03/16 15:55:37 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	free_and_null(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*get_left(char *line)
{
	char	*left;
	int		i;

	i = 0;
	if (!line[0])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	left = gnl_calloc(i + 2, sizeof(char));
	copy_string(left, line, i + 1);
	free(line);
	return (left);
}

char	*get_right(char *line)
{
	char	*right;

	if (!line || !(*line))
		return (NULL);
	right = gnl_calloc(length_of_string(line) + 1, sizeof(char));
	copy_string(right, line, length_of_string(line) + 1);
	return (right);
}

char	*read_line(int fd, char *line, char **buffer)
{
	int		read_bytes;

	read_bytes = 1;
	while (read_bytes)
	{
		read_bytes = read(fd, *buffer, BUFFER_SIZE);
		if (read_bytes < 1)
		{
			free_and_null(buffer);
			if (read_bytes == -1)
				free_and_null(&line);
			return (line);
		}
		line = join_string(line, *buffer);
		if (search_for_nl(line))
		{
			free_and_null(buffer);
			return (line);
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*buffer[1024];
	char			*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (0);
	line = NULL;
	if (buffer[fd])
	{
		line = buffer[fd];
		buffer[fd] = NULL;
	}
	buffer[fd] = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer[fd])
		free_and_null(&buffer[fd]);
	line = read_line(fd, line, &buffer[fd]);
	if (!line)
		return (line);
	buffer[fd] = get_right(search_for_nl(line));
	return (get_left(line));
}
