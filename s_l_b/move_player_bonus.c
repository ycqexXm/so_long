/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 05:10:51 by yorlians          #+#    #+#             */
/*   Updated: 2023/04/29 19:28:11 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	upd_player_pos(t_game *game, int new_x, int new_y, int player_sprite)
{
	int	prev_x;
	int	prev_y;
	int	place_on_map;

	place_on_map = game -> map.complete_map[new_y][new_x];
	prev_x = game -> map.pl_pos.x;
	prev_y = game -> map.pl_pos.y;
	if (place_on_map == EXIT && game -> map.collectible == 0)
		you_won(game);
	else if (place_on_map == DEMON_SPAWN)
		you_lost(game);
	else if (place_on_map == FLOOR || place_on_map == COLLECTIBLE)
	{
		game -> player_sprite = player_sprite;
		prev_x = game -> map.pl_pos.x;
		prev_y = game -> map.pl_pos.y;
		if (place_on_map == COLLECTIBLE)
			game -> map.collectible--;
		game -> map.complete_map[prev_y][prev_x] = FLOOR;
		game -> map.complete_map[new_y][new_x] = PLAYER;
		game -> map.pl_pos.x = new_x;
		game -> map.pl_pos.y = new_y;
		game -> steps++;
		render_map(game);
	}
}

void	upd_enemy_pos(t_game *game, int new_x, int new_y, int enemy_sprite)
{
	int	prev_x;
	int	prev_y;

	prev_x = game -> map.en_pos.x;
	prev_y = game -> map.en_pos.y;
	if (game -> map.complete_map[new_y][new_x] == PLAYER)
		you_lost(game);
	else if (game -> map.complete_map[new_y][new_x] == FLOOR)
	{
		game -> enemy_sprite = !enemy_sprite;
		prev_x = game -> map.en_pos.x;
		prev_y = game -> map.en_pos.y;
		game -> map.complete_map[prev_y][prev_x] = FLOOR;
		game -> map.complete_map[new_y][new_x] = DEMON_SPAWN;
		game -> map.en_pos.x = new_x;
		game -> map.en_pos.y = new_y;
		render_map(game);
	}
	else
	{
		game -> enemy_sprite = !enemy_sprite;
		game -> en_dir *= -1;
		render_map(game);
	}
}
