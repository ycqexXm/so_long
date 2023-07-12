/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:32:06 by yorlians          #+#    #+#             */
/*   Updated: 2023/04/29 20:54:17 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//checks if the given path ends with the ext .ber
void	ends_with_ber(t_game *game, char *path)
{
	char	*extension;

	extension = ft_strrchr(path, '.');
	if (!(extension != 0 && ft_strncmp(extension, ".ber", 5) == 0))
		error_message(EXT_ERROR, game);
}

//prints out error message and exit program with 
//failure status
void	error_message(char *message, t_game *game)
{
	ft_putstr_fd("Error\n", STDOUT_FILENO);
	ft_putstr_fd(message, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	free_all(game);
	exit(EXIT_FAILURE);
}

void	you_won(t_game *game)
{
	int			x;
	int			y;
	mlx_image_t	*image;

	game -> won = 1;
	image = put_image(WINNER_XPM, game);
	x = (game -> mlx -> width - 600) / 2;
	y = (game -> mlx -> height - 300) / 2;
	mlx_image_to_window(game -> mlx, image, x, y);
	delete_images(game -> mlx, &game -> image);
}

void	*sl_calloc(t_game *game, size_t size, size_t count)
{
	void	*ptr;

	ptr = NULL;
	ptr = ft_calloc(count, size);
	if (!ptr)
		error_message(FAIL_ALLOC, game);
	return (ptr);
}
