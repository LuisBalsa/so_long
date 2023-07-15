/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:01:55 by luide-so          #+#    #+#             */
/*   Updated: 2023/07/15 15:40:29 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	place_enemies(t_game *game)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	while (k < game->enemy_count)
	{
		i = (rand() % (game->map.rows - 1) + 1);
		j = (rand() % (game->map.cols - 1) + 1);
		if (game->map.grid[i][j] == SPACE)
		{
			game->enemy[k].current = (t_point){j, i};
			game->enemy[k].next = (t_point){j, i};
			game->map.grid[i][j] = ENEMY;
			k++;
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
