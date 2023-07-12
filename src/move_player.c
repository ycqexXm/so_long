/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 02:43:00 by yorlians          #+#    #+#             */
/*   Updated: 2023/04/29 18:35:17 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//updates player pos, cheks if player is on floor or col. if on col,
//decrease the total num of col. if standing on exit, is col == 0,
//the game is won. function redraws the map after updating the num
//of steps
void	upd_player_pos(t_game *game, int new_x, int new_y, int player_sprite)
{
	int	prev_x;
	int	prev_y;
	int	place_on_map;
	int	col;

	col = game -> map.collectible;
	place_on_map = game -> map.complete_map[new_y][new_x];
	if (place_on_map == EXIT && col == 0)
		you_won(game);
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
