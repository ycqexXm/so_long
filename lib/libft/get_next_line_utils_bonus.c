/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:23:05 by yorlians          #+#    #+#             */
/*   Updated: 2023/03/16 15:55:55 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	copy_string(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (length_of_string(src));
	i = 0;
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (length_of_string(src));
}

void	*gnl_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (ptr);
	while (i < count * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

int	length_of_string(const char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*search_for_nl(char *line)
{
	if (!line)
		return (line);
	while (*line && *line != '\n')
		line++;
	if (*line == '\n')
		return (line + 1);
	else
		return (NULL);
}

char	*join_string(char *line, char *buffer)
{
	char	*new_line;
	int		total;
	int		i;
	int		length;

	i = 0;
	length = 0;
	total = length_of_string(buffer) + 1;
	if (line)
		total += length_of_string(line);
	new_line = gnl_calloc(total, sizeof(char));
	while (line && line[i])
		new_line[length++] = line[i++];
	i = 0;
	while (buffer && buffer[i])
	{
		new_line[length++] = buffer[i++];
		buffer[i - 1] = '\0';
	}
	new_line[length] = '\0';
	free(line);
	return (new_line);
}
