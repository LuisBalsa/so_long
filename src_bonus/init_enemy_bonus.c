/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:01:55 by luide-so          #+#    #+#             */
/*   Updated: 2023/07/19 14:18:50 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	create_path_grid(t_game *game)
{
	int	i;

	game->path_grid = ft_calloc(game->map.rows, sizeof(int *));
	if (!game->path_grid)
		exit_error(game, "Couldn't allocate memory.");
	i = -1;
	while (++i < game->map.rows)
	{
		game->path_grid[i] = ft_calloc(game->map.cols, sizeof(int));
		if (!game->path_grid[i])
			exit_error(game, "Couldn't allocate memory.");
	}
}

static int	near_space_not_player(t_game *game, t_point pos)
{
	game->y = pos.y - 3;
	game->y *= !(game->y < 0);
	while (game->y < pos.y + 6 && game->y < game->map.rows)
	{
		game->x = pos.x - 3;
		game->x *= !(game->x < 0);
		while (game->x < pos.x + 6 && game->x < game->map.cols)
		{
			if (game->map.grid[game->y][game->x] == PLAYER)
				return (0);
			game->x++;
		}
		game->y++;
	}
	game->x = 0;
	if (game->map.grid[pos.y][pos.x + 1] == SPACE)
		game->x++;
	if (game->map.grid[pos.y][pos.x - 1] == SPACE)
		game->x++;
	if (game->map.grid[pos.y + 1][pos.x] == SPACE)
		game->x++;
	if (game->map.grid[pos.y - 1][pos.x] == SPACE)
		game->x++;
	return (game->x > 2);
}

static void	place_enemies(t_game *game)
{
	int	i;
	int	j;
	int	k;
	int	time_out;

	time_out = 1000;
	k = 0;
	while (k < game->enemy_count && time_out)
	{
		i = (rand() % (game->map.rows - 1) + 1);
		j = (rand() % (game->map.cols - 1) + 1);
		if (game->map.grid[i][j] == SPACE)
		{
			if (near_space_not_player(game, (t_point){j, i}))
			{
				game->enemy[k].current = (t_point){j, i};
				game->enemy[k].next = (t_point){j, i};
				game->map.grid[i][j] = ENEMY;
				k++;
			}
		time_out--;
		}
	}
}

static void	count_spaces(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
		{
			if (game->map.grid[i][j] == SPACE)
				game->spaces++;
		}
	}
}

void	init_enemy(t_game *game)
{
	count_spaces(game);
	game->enemy_count = game->spaces / SPACES_PER_ENEMY;
	game->enemy = ft_calloc(game->enemy_count + 1, sizeof(t_dummies));
	if (!game->enemy)
		exit_error(game, "Couldn't allocate memory.");
	place_enemies(game);
	create_path_grid(game);
}
