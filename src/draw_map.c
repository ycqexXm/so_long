/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:56:55 by yorlians          #+#    #+#             */
/*   Updated: 2023/04/29 17:53:49 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//renders the map onto the screen. goes through each cell of map
//checks its contents. after rendering the map
//calls print_steps to display num of steps
void	render_map(t_game *game)
{
	int		x;
	int		y;
	char	c;

	print_steps(game);
	y = 0;
	while (y < game -> map.height)
	{
		x = 0;
		while (x < game -> map.width)
		{
			c = game -> map.complete_map[y][x];
			render_map2(game, x, y, c);
			x++;
		}
		y++;
	}
}

void	render_map2(t_game *game, int x, int y, char c)
{
	if (c == WALL)
		render_sprite(game, game -> image.wall, x, y);
	if (c != WALL)
		render_sprite(game, game -> image.floor, x, y);
	if (c == COLLECTIBLE)
		render_sprite(game, game -> image.collectible, x, y);
	if (c == PLAYER)
		render_player(game, x, y);
	if (c == EXIT)
		render_exit(game, x, y);
}
