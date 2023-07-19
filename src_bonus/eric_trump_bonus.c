/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eric_trump_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:21:07 by luide-so          #+#    #+#             */
/*   Updated: 2023/07/19 17:53:21 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	best_direction(int **path, int *direction, t_point current)
{
	int	less_steps;

	less_steps = INT_MAX;
	if (path[current.y - 1][current.x] < less_steps)
	{
		less_steps = path[current.y - 1][current.x];
		*direction = 0;
	}
	if (path[current.y][current.x - 1] < less_steps)
	{
		less_steps = path[current.y][current.x - 1];
		*direction = 1;
	}
	if (path[current.y + 1][current.x] < less_steps)
	{
		less_steps = path[current.y + 1][current.x];
		*direction = 2;
	}
	if (path[current.y][current.x + 1] < less_steps)
		*direction = 3;
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

