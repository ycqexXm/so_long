/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 04:53:07 by yorlians          #+#    #+#             */
/*   Updated: 2023/04/29 19:34:09 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//initialises variables to how they should be
//in the start of the game
void	initialise_all(t_game *game)
{
	game -> map.collectible = 0;
	game -> map.exit = 0;
	game -> map.players = 0;
	game -> steps = 0;
	game -> map.width = 0;
	game -> map.height = 0;
	game -> won = 0;
	game -> player_sprite = PL_R;
}

//creates images for the game
void	create_images(t_game *game)
{
	game -> image.wall = put_image(WALL_XPM, game);
	game -> image.floor = put_image(FLOOR_XPM, game);
	game -> image.player_left = put_image(PLAYER_LEFT_XPM, game);
	game -> image.player_right = put_image(PLAYER_RIGHT_XPM, game);
	game -> image.exit = put_image(EXIT_XPM, game);
	game -> image.collectible = put_image(COLLECTIBLE_XPM, game);
}

//loads image file from given path, converts it to mlx and returns it
mlx_image_t	*put_image(char *path, t_game *game)
{
	mlx_image_t	*image;
	xpm_t		*xpm;

	xpm = mlx_load_xpm42(path);
	if (!xpm)
		error_message(ERR_L_XPM, game);
	image = mlx_texture_to_image(game -> mlx, &xpm -> texture);
	if (!image)
		error_message(ERR_CONV, game);
	mlx_delete_xpm42(xpm);
	return (image);
}
