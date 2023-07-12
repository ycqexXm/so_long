/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:22:45 by yorlians          #+#    #+#             */
/*   Updated: 2023/03/16 15:58:22 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

size_t	copy_string(char *dst, const char *src, size_t dstsize);
void	*gnl_calloc(size_t count, size_t size);
int		length_of_string(const char *string);
char	*search_for_nl(char *line);
char	*join_string(char *line, char *buffer);

void	free_and_null(char **ptr);
char	*get_left(char *line);
char	*get_right(char *line);
char	*read_line(int fd, char *line, char **buffer);
char	*get_next_line(int fd);

#endif
