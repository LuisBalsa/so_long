/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:24:21 by luide-so          #+#    #+#             */
/*   Updated: 2023/07/15 16:48:18 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error(game, "Couldn't initialize mlx.");
	game->win = mlx_new_window(game->mlx, game->map.cols * TILE_SIZE,
			game->map.rows * TILE_SIZE, "so_long");
	if (!game->win)
		exit_error(game, "Couldn't create window.");
}

void	init_game(t_game *game)
{
	init_enemy(game);
	init_mlx(game);
}
