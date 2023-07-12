/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 02:11:10 by yorlians          #+#    #+#             */
/*   Updated: 2023/04/29 19:22:38 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//frees all memory allocated for the game data
void	free_all(t_game *game)
{
	if (game)
	{
		if (game -> map.complete_map)
			free_map(game);
		delete_images(game -> mlx, &(game -> image));
		free(game);
	}
}

//frees memory allocated for all images
void	delete_images(mlx_t *mlx, t_image *image)
{
	if (image -> floor)
		mlx_delete_image(mlx, image -> floor);
	if (image -> exit)
		mlx_delete_image(mlx, image -> wall);
	if (image -> player_left)
		mlx_delete_image(mlx, image -> player_left);
	if (image -> player_right)
		mlx_delete_image(mlx, image -> player_right);
	if (image -> exit)
		mlx_delete_image(mlx, image -> exit);
	if (image -> collectible)
		mlx_delete_image(mlx, image -> collectible);
	if (image -> steps)
		mlx_delete_image(mlx, image -> steps);
	if (image -> enemy_child)
		mlx_delete_image(mlx, image -> enemy_child);
	if (image -> enemy_d_child)
		mlx_delete_image(mlx, image -> enemy_d_child);
}

//frees memory allocated for game map
void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game -> map.complete_map[i])
	{
		free(game -> map.complete_map[i]);
		i++;
	}
	free(game -> map.complete_map);
}

//close game and free all allocated things by the game
void	close_game(t_game *game)
{
	if (game)
	{
		mlx_close_window(game -> mlx);
		free_all(game);
		exit(EXIT_SUCCESS);
	}
}
