/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eric_trump_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:21:07 by luide-so          #+#    #+#             */
/*   Updated: 2023/07/24 10:07:00 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	best_direction(int **path, int *direction, t_point current)
{
	int	less_steps;
	int	x;
	int	y;
	int	dir;
	int	i;

	less_steps = INT_MAX;
	i = 0;
	dir = rand() % 4;
	while (i < 4)
	{
		x = current.x + (dir == 3) - (dir == 1);
		y = current.y + (dir == 2) - (dir == 0);
		if (path[y][x] < less_steps)
		{
			less_steps = path[y][x];
			*direction = dir;
		}
		dir = (dir + 1) % 4;
		i++;
	}
}

static void	best_path_grid(t_game *g, t_point c, int **path, int steps)
{
	if (g->map.grid[c.y][c.x] == WALL)
		return ;
	if (steps < path[c.y][c.x])
	{
		path[c.y][c.x] = steps;
		best_path_grid(g, (t_point){c.x, c.y - 1}, path, steps + 1);
		best_path_grid(g, (t_point){c.x - 1, c.y}, path, steps + 1);
		best_path_grid(g, (t_point){c.x, c.y + 1}, path, steps + 1);
		best_path_grid(g, (t_point){c.x + 1, c.y}, path, steps + 1);
	}
}

static void	init_path_grid(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
			game->path_grid[i][j] = INT_MAX;
	}
}

static void	joe_biden(t_game *game)
{
	int	enemy;

	enemy = -1;
	while (++enemy < game->enemy_count)
	{
		if (game->enemy[enemy].trump)
		{
			game->enemy[enemy].trump = 0;
			game->enemy[enemy].img_index -= 4;
		}
	}
	game->trump_steps = 0;
}

void	eric_trump(t_game *game)
{
	int	enemy;

	if (!TRUMP_MODE)
		return ;
	init_path_grid(game);
	best_path_grid(game, game->player.current, game->path_grid, 0);
	if (rand() % 6 == 0)
	{
		enemy = rand() % game->enemy_count;
		if (game->enemy[enemy].trump == 0)
			game->enemy[enemy].img_index += 4;
		game->enemy[enemy].trump = 1;
	}
	enemy = -1;
	while (++enemy < game->enemy_count)
	{
		if (game->enemy[enemy].trump == 1)
		{
			best_direction(game->path_grid, &game->enemy[enemy].direction,
				game->enemy[enemy].current);
		}
	}
	game->trump_steps++;
	if (game->trump_steps == TRUMP_STEPS)
		joe_biden(game);
}
