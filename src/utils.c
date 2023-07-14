/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:06:37 by luide-so          #+#    #+#             */
/*   Updated: 2023/07/14 17:24:35 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	exit_error(t_game *game, char *msg)
{
	if (game)
	{
		if (game->map.grid)
			ft_free_array(game->map.grid);
		if (game->mlx && game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
			free(game->mlx);
	}
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit (EXIT_FAILURE);
}
