/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 06:25:26 by yorlians          #+#    #+#             */
/*   Updated: 2023/04/29 17:55:09 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//verifies if the loaded map is valid
//1 - ends with ber
//2 - surrounded by walls
//3 - each tile = valid char
//4 - at least 1 col, 1 player, 1 exit
void	check_map(t_game *game)
{
	ends_with_ber(game, game -> mapname);
	check_rows(game);
	check_columns(game);
	check_assets_validity(game);
	check_assets_number(game);
}
