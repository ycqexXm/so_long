/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:00:26 by yorlians          #+#    #+#             */
/*   Updated: 2023/04/29 20:54:07 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <memory.h>
# include <fcntl.h>
# include <unistd.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"

# define NOT_RECT		"Invalid map! Map is not rectangular :("	
# define NO_WALL_1_C	"Invalid map! The wall is missing (first column) :("
# define NO_WALL_L_C	"Invalid map! The wall is missing (last column) :("
# define NO_WALL_1_L	"Invalid map! The wall is missing (first line) :("
# define NO_WALL_L_L	"Invalid map! The wall is missing (last line) :("
# define NO_COL			"Invalid map! No collectible found :("
# define NO_EXIT		"Invalid map! No exit found :("
# define MANY_EXITS		"Invalid map! Too many exits found :("
# define NOT_1_PL		"Invalid map! Only one player is allowed :("
# define UNEX_PARAM		"Unexpected parameter :("
# define COL_N_REACH	"Collectible not reachable :("
# define EX_N_REACH		"Exit not reachable :("
# define ERR_L_XPM		"Unable to load xpm42 :("
# define ERR_CONV		"Error while converting texture to image :("
# define ERR_OP_MAP		"Can't open the map :("
# define NO_2_ARGC		"Wrong number of arguments :("
# define FAIL_ALLOC		"Allocation failed :("
# define EXT_ERROR		"Extension is not ber :("

//left and right of player
# define PL_L						1
# define PL_R						2

//elements of the map
//with assigned characters 
# define WALL						'1'
# define COLLECTIBLE				'C'
# define PLAYER						'P'
# define EXIT						'E'
# define FLOOR						'0'

//images
# define COLLECTIBLE_XPM			"images/fly.xpm42"
# define WALL_XPM					"images/wall.xpm42"
# define FLOOR_XPM					"images/grass.xpm42"
# define PLAYER_LEFT_XPM			"images/frog_left.xpm42"
# define PLAYER_RIGHT_XPM			"images/frog_right.xpm42"
# define EXIT_XPM					"images/exit.xpm42"
# define WINNER_XPM					"images/you_won.xpm42"

typedef struct s_image
{
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*player_left;
	mlx_image_t		*player_right;
	mlx_image_t		*exit;
	mlx_image_t		*collectible;
	mlx_image_t		*steps;
	int				width;
	int				height;
	int				pl_dir;
}	t_image;

typedef struct s_position
{
	int				x;
	int				y;
}	t_position;

typedef struct s_map
{
	char			**complete_map;
	int				width;
	int				height;
	int				collectible;
	int				exit;
	int				players;
	t_position		pl_pos;
}	t_map;

typedef struct s_game
{
	mlx_t			*mlx;
	char			*mapname;
	int				steps;
	int				player_sprite;
	t_map			map;
	t_image			image;
	int				won;
}	t_game;

//check_map_utils
void			check_rows(t_game *game);
void			check_columns(t_game *game);
void			check_assets_number(t_game *game);
void			count_assets(t_game *game, int x, int y, char c);
void			check_assets_validity(t_game *game);

//check_map
void			check_map(t_game *game);

//dfs
int				dfs(t_game *game, int x, int y, int **visit);
void			free_visited(int **visited, int height);
int				is_reachable(t_game *game, int x, int y);
void			check_reach(t_game *game);

//draw_map_utils
void			render_player(t_game *game, int x, int y);
void			render_sprite(t_game *game, mlx_image_t *sprite, \
				int line, int column);
void			print_steps(t_game *game);
void			render_exit(t_game *game, int x, int y);

//draw_map
void			render_map(t_game *game);
void			render_map2(t_game *game, int x, int y, char c);

//free_all
void			free_all(t_game *game);
void			free_map(t_game *game);
void			delete_images(mlx_t *mlx, t_image *image);
void			close_game(t_game *game);

//hooks
int				event_handler(int pressed_key, t_game *game);
void			key_hook(mlx_key_data_t keydata, void *param);

//init_game
mlx_image_t		*put_image(char *path, t_game *game);
void			initialise_all(t_game *game);
void			create_images(t_game *game);

//init_map
void			count_map_lines(t_game *game, char *path);
void			init_map(t_game *game, char *path);

//move_player
void			upd_player_pos(t_game *game, int new_x, int new_y, \
				int player_sprite);

//utils
void			ends_with_ber(t_game *game, char *path);
void			error_message(char *message, t_game *game);
void			you_won(t_game *game);
void			*sl_calloc(t_game *game, size_t size, size_t count);

#endif