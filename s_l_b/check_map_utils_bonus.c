/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 00:34:18 by yorlians          #+#    #+#             */
/*   Updated: 2023/04/29 19:19:12 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//loops through every row of the map to check that their len is same,
//the first char of all lines is a WALL, the last one also a WALL
void	check_rows(t_game *game)
{
	int		i;
	char	*row;
	int		length;

	i = 0;
	while (game -> map.complete_map[i])
	{
		row = game -> map.complete_map[i];
		length = (int)ft_strlen(row);
		if (game -> map.width == 0)
			game -> map.width = length;
		if (length != game -> map.width)
			error_message(NOT_RECT, game);
		if (row[0] != WALL)
			error_message(NO_WALL_1_C, game);
		if (row[length - 1] != WALL)
			error_message(NO_WALL_L_C, game);
		i++;
	}
}

//loops trough every column of the map and checks if the first and last rows
//of each column contain a wall
void	check_columns(t_game *game)
{
	int	i;

	i = 0;
	while (i < game -> map.width)
	{
		if (game -> map.complete_map[0][i] != WALL)
			error_message(NO_WALL_1_L, game);
		else if (game -> map.complete_map[game -> map.height - 1][i] != WALL)
			error_message(NO_WALL_L_L, game);
		i++;
	}
}

//checks for col, exit and players on map
void	check_assets_number(t_game *game)
{
	if (game -> map.collectible < 1)
		error_message(NO_COL, game);
	if (game -> map.exit < 1)
		error_message(NO_EXIT, game);
	if (game -> map.exit > 1)
		error_message(MANY_EXITS, game);
	if (game -> map.players != 1)
		error_message(NOT_1_PL, game);
	if (game -> map.enemies > 1)
		error_message(NOT_1_EN, game);
}

//iterates over the entire map and counts the num of assets,
//x y used to keep track of the pos on the map, 'tile' holds
//the value of the tile being examinated. for each tile stores 
//its value in 'tile'
void	count_assets(t_game *game, int x, int y, char c)
{
	if (c == PLAYER)
	{
		game -> map.players++;
		game -> map.pl_pos.x = x;
		game -> map.pl_pos.y = y;
	}
	else if (c == DEMON_SPAWN)
	{
		game -> map.enemies++;
		game -> map.en_pos.x = x;
		game -> map.en_pos.y = y;
	}
	else if (c == COLLECTIBLE)
		game -> map.collectible++;
	else if (c == EXIT)
		game -> map.exit++;
}

//checks the validity of assets on the map. goes through each tile
//and checks if that tile is one of "01CPE". After checking all the assets calls
//count_assets to count the num of pl, col and exits
void	check_assets_validity(t_game *game)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < game -> map.height)
	{
		x = 0;
		while (x < game -> map.width)
		{
			c = game -> map.complete_map[y][x];
			if (!ft_strchr("01CPED", c))
				error_message(UNEX_PARAM, game);
			count_assets(game, x, y, c);
			x++;
		}
		y++;
	}
	check_reach(game);
}
