/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:01:55 by luide-so          #+#    #+#             */
/*   Updated: 2023/07/17 11:34:11 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static int	next_to_player(t_game *game, t_point pos)
{
	if (game->map.grid[pos.y][pos.x + 1] == PLAYER)
		return (1);
	if (game->map.grid[pos.y][pos.x - 1] == PLAYER)
		return (1);
	if (game->map.grid[pos.y + 1][pos.x] == PLAYER)
		return (1);
	if (game->map.grid[pos.y - 1][pos.x] == PLAYER)
		return (1);
	return (0);
}

static int	next_to_space(t_game *game, t_point pos)
{
	int	spaces;

	spaces = 0;
	if (game->map.grid[pos.y][pos.x + 1] == SPACE)
		spaces++;
	if (game->map.grid[pos.y][pos.x - 1] == SPACE)
		spaces++;
	if (game->map.grid[pos.y + 1][pos.x] == SPACE)
		spaces++;
	if (game->map.grid[pos.y - 1][pos.x] == SPACE)
		spaces++;
	return (spaces > 2);
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
			if (!next_to_player(game, (t_point){j, i}) &&
				next_to_space(game, (t_point){j, i}))
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
}
