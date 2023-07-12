/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:11:25 by yorlians          #+#    #+#             */
/*   Updated: 2023/04/29 20:52:08 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//takes current game state and players coordinates
//renders players sprite on the window based on the current
//player direction
void	render_player(t_game *game, int x, int y)
{
	if (game -> player_sprite == PL_R)
		render_sprite(game, game -> image.player_right, x, y);
	if (game -> player_sprite == PL_L)
		render_sprite(game, game -> image.player_left, x, y);
}

void	render_enemy(t_game *game, int x, int y)
{
	if (game -> enemy_sprite == EN_C)
		render_sprite(game, game -> image.enemy_child, x, y);
	if (game -> enemy_sprite == EN_D)
		render_sprite(game, game -> image.enemy_d_child, x, y);
}

//renders sprite to the game window at needed location
void	render_sprite(t_game *game, mlx_image_t *sprite, int x, int y)
{
	x *= 80;
	y *= 80;
	mlx_image_to_window(game -> mlx, sprite, x, y);
}

//prints the number of steps made.
//converts nb to str, + message
void	print_steps(t_game *game)
{
	mlx_image_t	*old_image;
	char		*steps;
	char		*message;

	steps = ft_itoa(game -> steps);
	message = ft_strjoin("Steps: ", steps);
	old_image = game -> image.steps;
	game -> image.steps = mlx_put_string(game -> mlx, message, 50,
			game -> map.height * 80 + 30);
	if (old_image)
		mlx_delete_image(game -> mlx, old_image);
	free(steps);
	free(message);
}

// renders the exit sprite
void	render_exit(t_game *game, int x, int y)
{
	if (game -> map.collectible == 0)
		render_sprite(game, game -> image.exit, x, y);
	else
		render_sprite(game, game -> image.exit, x, y);
}
