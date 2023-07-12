/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 05:14:30 by yorlians          #+#    #+#             */
/*   Updated: 2023/04/29 20:29:36 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_map_lines(t_game *game, char *path)
{
	int		map_fd;
	char	*line;

	map_fd = open(path, O_RDONLY);
	if (map_fd < 0)
		error_message(ERR_OP_MAP, game);
	while (1)
	{
		line = get_next_line(map_fd);
		if (!line)
			break ;
		game -> map.height++;
		free(line);
	}
	close(map_fd);
}

void	init_map(t_game *game, char *path)
{
	int		map_fd;
	int		y;

	count_map_lines(game, path);
	game -> map.complete_map = sl_calloc(game, game -> map.height + 1,
			sizeof(char *));
	map_fd = open(path, O_RDONLY);
	if (map_fd < 0)
		error_message(ERR_OP_MAP, game);
	y = 0;
	while (1)
	{
		game -> map.complete_map[y] = get_next_line(map_fd);
		if (game -> map.complete_map[y] == NULL)
			break ;
		if (ft_strchr(game -> map.complete_map[y], '\n'))
			*ft_strchr(game -> map.complete_map[y], '\n') = '\0';
		y++;
	}
	game -> map.complete_map[y] = NULL;
	close(map_fd);
}
