/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:24:21 by luide-so          #+#    #+#             */
/*   Updated: 2023/07/16 12:52:23 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	init_map(t_game *game, int i, int j)
{
	t_img	*tile;

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
				tile = &game->img_collect[0];
			else if (game->map.grid[i][j] == PLAYER)
				tile = &game->img_p[0];
			else if (game->map.grid[i][j] == ENEMY)
				tile = &game->img_e[0];
			mlx_put_image_to_window(game->mlx, game->win, tile->img,
				j * TILE_SIZE, i * TILE_SIZE);
		}
	}
}

static void	check_textures(t_game *game)
{
	if (!game->img_walls.img || !game->img_space.img || !game->img_exit.img
		|| !game->img_collect[0].img || !game->img_collect[1].img
		|| !game->img_collect[2].img || !game->img_collect[3].img
		|| !game->img_p[0].img || !game->img_p[1].img
		|| !game->img_e[0].img || !game->img_e[1].img)
		exit_error(game, "Couldn't load textures.");
}

static void	init_textures(t_game *game)
{
	game->img_walls.img = mlx_xpm_file_to_image(game->mlx, WALL_XPM,
			&game->img_walls.width, &game->img_walls.height);
	game->img_space.img = mlx_xpm_file_to_image(game->mlx, SPACE_XPM,
			&game->img_space.width, &game->img_space.height);
	game->img_exit.img = mlx_xpm_file_to_image(game->mlx, EXIT_XPM,
			&game->img_exit.width, &game->img_exit.height);
	game->img_collect[0].img = mlx_xpm_file_to_image(game->mlx, COLLECT1_XPM,
			&game->img_collect[0].width, &game->img_collect[0].height);
	game->img_collect[1].img = mlx_xpm_file_to_image(game->mlx, COLLECT2_XPM,
			&game->img_collect[1].width, &game->img_collect[1].height);
	game->img_collect[2].img = mlx_xpm_file_to_image(game->mlx, COLLECT3_XPM,
			&game->img_collect[2].width, &game->img_collect[2].height);
	game->img_collect[3].img = mlx_xpm_file_to_image(game->mlx, COLLECT4_XPM,
			&game->img_collect[3].width, &game->img_collect[3].height);
	game->img_p[0].img = mlx_xpm_file_to_image(game->mlx, PLAYER1_XPM,
			&game->img_p[0].width, &game->img_p[0].height);
	game->img_p[1].img = mlx_xpm_file_to_image(game->mlx, PLAYER2_XPM,
			&game->img_p[1].width, &game->img_p[1].height);
	game->img_e[0].img = mlx_xpm_file_to_image(game->mlx, ENEMY1_XPM,
			&game->img_e[0].width, &game->img_e[0].height);
	game->img_e[1].img = mlx_xpm_file_to_image(game->mlx, ENEMY2_XPM,
			&game->img_e[1].width, &game->img_e[1].height);
	check_textures(game);
}


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
	init_textures(game);
	init_map(game, -1, -1);
}
