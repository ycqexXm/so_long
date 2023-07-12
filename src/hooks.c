/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 06:35:08 by yorlians          #+#    #+#             */
/*   Updated: 2023/04/29 18:34:33 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//event handler triggered when a key is pressed.
//checks which key was pressed and updates the players
//pos accordingly. if ESC = close game. returns 0
//to indicate that event was handled
int	event_handler(int pressed_key, t_game *game)
{
	int	pos_y;
	int	pos_x;

	if (!game -> won)
	{
		pos_y = game -> map.pl_pos.y;
		pos_x = game -> map.pl_pos.x;
		if (pressed_key == MLX_KEY_UP || pressed_key == MLX_KEY_W)
			upd_player_pos(game, pos_x, pos_y - 1, PL_R);
		if (pressed_key == MLX_KEY_DOWN || pressed_key == MLX_KEY_S)
			upd_player_pos(game, pos_x, pos_y + 1, PL_L);
		if (pressed_key == MLX_KEY_LEFT || pressed_key == MLX_KEY_A)
			upd_player_pos(game, pos_x - 1, pos_y, PL_L);
		if (pressed_key == MLX_KEY_RIGHT || pressed_key == MLX_KEY_D)
			upd_player_pos(game, pos_x + 1, pos_y, PL_R);
	}
	if (pressed_key == MLX_KEY_ESCAPE)
		close_game(game);
	return (0);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		event_handler(keydata.key, game);
}
