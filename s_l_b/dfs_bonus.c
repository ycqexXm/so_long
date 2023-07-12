/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:02:33 by yorlians          #+#    #+#             */
/*   Updated: 2023/04/29 20:36:02 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	dfs(t_game *game, int x, int y, int **visit)
{
	if (visit[y][x] || game -> map.complete_map[y][x] == WALL)
		return (0);
	if (x == game -> map.pl_pos.x && y == game -> map.pl_pos.y)
		return (1);
	visit[y][x] = 1;
	if (dfs(game, x - 1, y, visit))
		return (1);
	if (dfs(game, x + 1, y, visit))
		return (1);
	if (dfs(game, x, y - 1, visit))
		return (1);
	if (dfs(game, x, y + 1, visit))
		return (1);
	return (0);
}

void	free_visited(int **visited, int height)
{
	while (--height >= 0)
		free(visited[height]);
	free(visited);
}

int	is_reachable(t_game *game, int x, int y)
{	
	int	**visited;
	int	i;
	int	j;

	j = 0;
	visited = sl_calloc(game, game -> map.height, sizeof(int *));
	while (j < game -> map.height)
	{
		i = 0;
		visited[j] = sl_calloc(game, game -> map.width, sizeof(int));
		while (i < game -> map.width)
			visited[j][i++] = 0;
		j++;
	}
	if (dfs(game, x, y, visited))
		return (free_visited(visited, game -> map.height), 1);
	else
		return (free_visited(visited, game -> map.height), 0);
}

void	check_reach(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game -> map.complete_map[y])
	{
		x = 0;
		while (game -> map.complete_map[y][x])
		{
			if (game -> map.complete_map[y][x] == COLLECTIBLE)
			{
				if (!is_reachable(game, x, y))
					error_message(COL_N_REACH, game);
			}
			if (game -> map.complete_map[y][x] == EXIT)
			{
				if (!is_reachable(game, x, y))
					error_message(EX_N_REACH, game);
			}
			x++;
		}
		y++;
	}
}
