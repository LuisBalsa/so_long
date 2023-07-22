/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:24:53 by luide-so          #+#    #+#             */
/*   Updated: 2023/07/22 15:24:13 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_tile(t_game *game, char tile, t_point point, int img_index)
{
	if (tile == SPACE || tile == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_space.img, point.x * TILE_SIZE, point.y * TILE_SIZE);
	else if (tile == EXIT)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_exit.img, point.x * TILE_SIZE, point.y * TILE_SIZE);
	else if (tile == COLLECT)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_collect.img, point.x * TILE_SIZE, point.y * TILE_SIZE);
	else if (tile == PLAYER)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_p[img_index].img,
			point.x * TILE_SIZE, point.y * TILE_SIZE);
}

void	render_move(t_game *game, char current, char next, t_dummies *dummy)
{
	put_tile(game, current, dummy->current, dummy->img_index);
	put_tile(game, next, dummy->next, dummy->img_index);
}
