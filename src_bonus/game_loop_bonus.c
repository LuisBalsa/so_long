/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:56:34 by luide-so          #+#    #+#             */
/*   Updated: 2023/07/20 18:09:06 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	put_tile(t_game *game, t_img *img, int i, t_point p)
{
	mlx_put_image_to_window(game->mlx, game->win, img[i].img,
		p.x * TILE_SIZE, p.y * TILE_SIZE);
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
	enemy->i_anim = 1;
	if (enemy->direction == 0)
		check_move(game, enemy, enemy->current.x, enemy->current.y - 1);
	else if (enemy->direction == 1)
	{
		enemy->img_index = FACE_LEFT + 4 * enemy->trump;
		put_tile(game, game->img_e, enemy->img_index, enemy->current);
		check_move(game, enemy, enemy->current.x - 1, enemy->current.y);
	}
	else if (enemy->direction == 2)
		check_move(game, enemy, enemy->current.x, enemy->current.y + 1);
	else if (enemy->direction == 3)
	{
		enemy->img_index = FACE_RIGHT + 4 * enemy->trump;
		put_tile(game, game->img_e, enemy->img_index, enemy->current);
		check_move(game, enemy, enemy->current.x + 1, enemy->current.y);
	}
}

static void	render_animation(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
			if (game->map.grid[i][j] == COLLECT)
				put_tile(game, game->img_collect, game->anim_index,
					(t_point){j, i});
	}
	i = -1;
	while (game->enemy[0].current.x && ++i < game->enemy_count)
	{
		if (game->enemy[i].i_anim)
		{
			put_tile(game, game->img_e, game->enemy[i].img_index
				+ (game->enemy[i].i_anim % 2), game->enemy[i].current);
			game->enemy[i].i_anim = (game->enemy[i].i_anim + 1) % 3;
		}
	}
	if (game->player.i_anim)
		put_tile(game, game->img_p, game->player.img_index
			+ (game->player.i_anim % 2), game->player.current);
}

int	game_loop(t_game *game)
{
	int	enemy;

	if (clock() - game->clock_anim >= SP_ANIM_DELAY)
	{
		game->clock_anim = clock();
		render_animation(game);
		game->anim_index++;
		game->anim_index = game->anim_index % SP_ANIM;
		if (game->player.i_anim)
			game->player.i_anim = (game->player.i_anim + 1) % 3;
	}
	if (game->enemy[0].current.x && clock() - game->clock_enemy >= ENEMY_DELAY)
	{
		enemy = -1;
		game->clock_enemy = clock() + game->collect * SPEED_PER_COLLET;
		eric_trump(game);
		while (game->enemy[++enemy].current.x && (enemy < game->enemy_count))
		{
			if (rand() % (16 - 5 * game->enemy[enemy].trump) == 0)
				game->enemy[enemy].direction = rand() % 4;
			if (rand() % 3)
				move_enemy(game, &game->enemy[enemy]);
		}
	}
	return (0);
}
