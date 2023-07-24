/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:24:21 by luide-so          #+#    #+#             */
/*   Updated: 2023/07/24 10:07:14 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	render_map(t_game *game, int i, int j)
{
	t_img	*tile;

	tile = &game->img_walls;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
		{
			if (game->map.grid[i][j] == WALL)
				tile = &game->img_walls;
			else if (game->map.grid[i][j] == SPACE)
				tile = &game->img_space;
			else if (game->map.grid[i][j] == EXIT)
				tile = &game->img_exit;
			else if (game->map.grid[i][j] == COLLECT)
				tile = &game->img_collect;
			else if (game->map.grid[i][j] == PLAYER)
				tile = &game->img_p[0];
			mlx_put_image_to_window(game->mlx, game->win, tile->img,
				j * TILE_SIZE, i * TILE_SIZE);
		}
	}
}

static void	check_textures(t_game *game)
{
	if (!game->img_walls.img || !game->img_space.img || !game->img_exit.img
		|| !game->img_collect.img
		|| !game->img_p[0].img || !game->img_p[1].img)
		exit_error(game, "Couldn't load textures.");
}

static void	load_textures(t_game *g)
{
	g->img_walls.img = mlx_xpm_file_to_image(g->mlx, W_XPM, &g->x, &g->y);
	g->img_space.img = mlx_xpm_file_to_image(g->mlx, S_XPM, &g->x, &g->y);
	g->img_exit.img = mlx_xpm_file_to_image(g->mlx, E_XPM, &g->x, &g->y);
	g->img_collect.img = mlx_xpm_file_to_image(g->mlx, C1_XPM, &g->x, &g->y);
	g->img_p[0].img = mlx_xpm_file_to_image(g->mlx, P1_XPM, &g->x, &g->y);
	g->img_p[1].img = mlx_xpm_file_to_image(g->mlx, P2_XPM, &g->x, &g->y);
	check_textures(g);
}

static void	init_mlx_and_textures(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error(game, "Couldn't initialize mlx.");
	load_textures(game);
	game->win = mlx_new_window(game->mlx, game->map.cols * TILE_SIZE,
			game->map.rows * TILE_SIZE, "so_long");
	if (!game->win)
		exit_error(game, "Couldn't create window.");
}

void	init_game(t_game *game)
{
	init_mlx_and_textures(game);
	render_map(game, -1, -1);
}
