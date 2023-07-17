/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:06:37 by luide-so          #+#    #+#             */
/*   Updated: 2023/07/16 12:57:44 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	free_textures(t_game *game)
{
	if (game->img_walls.img)
		mlx_destroy_image(game->mlx, game->img_walls.img);
	if (game->img_space.img)
		mlx_destroy_image(game->mlx, game->img_space.img);
	if (game->img_exit.img)
		mlx_destroy_image(game->mlx, game->img_exit.img);
	if (game->img_collect[0].img)
		mlx_destroy_image(game->mlx, game->img_collect[0].img);
	if (game->img_collect[1].img)
		mlx_destroy_image(game->mlx, game->img_collect[1].img);
	if (game->img_collect[2].img)
		mlx_destroy_image(game->mlx, game->img_collect[2].img);
	if (game->img_collect[3].img)
		mlx_destroy_image(game->mlx, game->img_collect[3].img);
	if (game->img_p[0].img)
		mlx_destroy_image(game->mlx, game->img_p[0].img);
	if (game->img_p[1].img)
		mlx_destroy_image(game->mlx, game->img_p[1].img);
	if (game->img_e[0].img)
		mlx_destroy_image(game->mlx, game->img_e[0].img);
	if (game->img_e[1].img)
		mlx_destroy_image(game->mlx, game->img_e[1].img);
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
