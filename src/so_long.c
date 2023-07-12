/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:10:46 by yorlians          #+#    #+#             */
/*   Updated: 2023/04/30 02:53:09 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//checks for num of args on command line
//recieves the map as argument
//creates a window and 
//works with the map
int	main(int argc, char **argv)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		error_message(FAIL_ALLOC, game);
	game -> mapname = argv[1];
	if (argc != 2)
		error_message(NO_2_ARGC, game);
	initialise_all(game);
	init_map(game, argv[1]);
	check_map(game);
	game -> mlx = mlx_init(game -> map.width * 80,
			game -> map.height * 80 + 80, "So_Long", false);
	create_images(game);
	render_map(game);
	mlx_key_hook(game -> mlx, &key_hook, game);
	mlx_loop(game -> mlx);
	mlx_terminate(game ->mlx);
	free_all(game);
	return (EXIT_SUCCESS);
}
