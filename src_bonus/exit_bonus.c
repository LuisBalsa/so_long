/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:06:37 by luide-so          #+#    #+#             */
/*   Updated: 2023/07/18 03:22:54 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	free_textures(t_game *game)
{
	game->exit = -1;
	if (game->img_walls.img)
		mlx_destroy_image(game->mlx, game->img_walls.img);
	if (game->img_space.img)
		mlx_destroy_image(game->mlx, game->img_space.img);
	if (game->img_exit.img)
		mlx_destroy_image(game->mlx, game->img_exit.img);
	while (++game->exit < SP_ANIM)
		if (game->img_collect[game->exit].img)
			mlx_destroy_image(game->mlx, game->img_collect[game->exit].img);
	game->exit = -1;
	while (++game->exit < SP_LEN)
		if (game->img_p[game->exit].img)
			mlx_destroy_image(game->mlx, game->img_p[game->exit].img);
	game->exit = -1;
	while (++game->exit < SP_LEN)
		if (game->img_e[game->exit].img)
			mlx_destroy_image(game->mlx, game->img_e[game->exit].img);
}

static void	free_game(t_game *game)
{
	if (game)
	{
		if (game->map.grid)
			ft_free_array(game->map.grid);
		free_textures(game);
		if (game->mlx && game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		if (game->enemy)
			free(game->enemy);
	}
}

int	exit_error(t_game *game, char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	free_game(game);
	exit(EXIT_FAILURE);
}

int	exit_game(t_game *game, char *msg)
{
	ft_putendl_fd(msg, 1);
	free_game(game);
	exit(EXIT_SUCCESS);
}

int	exit_esc(t_game *game)
{
	ft_putendl_fd("You gave up! 🐔", 1);
	free_game(game);
	exit(EXIT_SUCCESS);
}
