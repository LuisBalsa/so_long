/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:56:34 by luide-so          #+#    #+#             */
/*   Updated: 2023/07/17 16:05:21 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	put_tile(t_game *game, t_dummies *enemy)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_e[enemy->img_index].img,
		enemy->current.x * TILE_SIZE, enemy->current.y * TILE_SIZE);
}

static void	check_move(t_game *game, t_dummies *enemy, int x, int y)
{
	if (game->map.grid[y][x] == WALL || game->map.grid[y][x] == ENEMY)
	{
		enemy->direction += rand() % 2 + 1;
		enemy->direction = enemy->direction % 4;
		return ;
	}
	if (game->map.grid[y][x] == PLAYER)
		exit_game(game, "The chicken gotcha and whooped ya! 🐔");
	enemy->next = (t_point){x, y};
	render_move(game, enemy->current_tile, ENEMY, enemy);
	game->map.grid[enemy->current.y][enemy->current.x] = enemy->current_tile;
	enemy->current = enemy->next;
	enemy->current_tile = game->map.grid[y][x];
	game->map.grid[y][x] = ENEMY;
}

static void	move_enemy(t_game *game, t_dummies *enemy)
{
	if (enemy->direction == 0)
		check_move(game, enemy, enemy->current.x, enemy->current.y - 1);
	else if (enemy->direction == 1)
	{
		enemy->img_index = 1;
		put_tile(game, enemy);
		check_move(game, enemy, enemy->current.x - 1, enemy->current.y);
	}
	else if (enemy->direction == 2)
		check_move(game, enemy, enemy->current.x, enemy->current.y + 1);
	else if (enemy->direction == 3)
	{
		enemy->img_index = 0;
		put_tile(game, enemy);
		check_move(game, enemy, enemy->current.x + 1, enemy->current.y);
	}
}

static void	render_animation(t_game *game)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
		{
			if (game->map.grid[i][j] == COLLECT)
			{
				x = j * TILE_SIZE;
				y = i * TILE_SIZE;
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_collect[game->anim_index].img, x, y);
			}
		}
	}
}

int	game_loop(t_game *game)
{
	int	enemy;

	if (clock() - game->clock_anim >= SP_ANIM_SPEED)
	{
		game->clock_anim = clock();
		render_animation(game);
		game->anim_index++;
		game->anim_index = game->anim_index % SP_ANIM;
	}
	if (clock() - game->clock_enemy >= ENEMY_SPEED)
	{
		enemy = -1;
		game->clock_enemy = clock();
		while (game->enemy[++enemy].current.x && (enemy < game->enemy_count))
		{
			if (rand() % 32 == 0)
				game->enemy[enemy].direction = rand() % 4;
			if (rand() % 3 - (rand() % 3))
				move_enemy(game, &game->enemy[enemy]);
		}
	}
	return (0);
}
