/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:01:20 by luide-so          #+#    #+#             */
/*   Updated: 2023/07/20 04:18:24 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

/* static void	put_tile(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_p[game->player.img_index].img,
		game->player.current.x * TILE_SIZE, game->player.current.y * TILE_SIZE);
} */

static void	print_moves(t_game *game)
{
	char	*moves;

	mlx_put_image_to_window(game->mlx, game->win,
		game->img_walls.img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_walls.img, TILE_SIZE, 0);
	mlx_string_put(game->mlx, game->win, 10, 15, 0xFFFFFF, "Moves:  ");
	mlx_string_put(game->mlx, game->win, 50, 15, 0xFFFFFF,
		moves = ft_itoa(++game->moves));
	free(moves);
}

static void	check_move(t_game *game, int x, int y)
{
	game->player.i_anim = 1;
	if (game->map.grid[y][x] == WALL)
		return ;
	print_moves(game);
	if (game->map.grid[y][x] == COLLECT)
	{
		game->map.grid[y][x] = SPACE;
		game->collect--;
	}
	if (game->map.grid[y][x] == EXIT && !game->collect)
		exit_game(game, "Congratulations! You managed to drive drunk! 🍺");
	if (game->map.grid[y][x] == EXIT)
		ft_printf("You are not drunk enough! 🍺\n");
	if (game->map.grid[y][x] == ENEMY)
		exit_game(game, "You lost the chicken fight! 🐔");
	game->player.next = (t_point){x, y};
	render_move(game, game->player.current_tile, PLAYER, &game->player);
	game->map.grid[game->player.current.y][game->player.current.x]
		= game->player.current_tile;
	game->player.current = game->player.next;
	game->player.current_tile = game->map.grid[y][x];
	game->map.grid[y][x] = PLAYER;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == W || keycode == UP)
		check_move(game, game->player.current.x, game->player.current.y - 1);
	else if (keycode == A || keycode == LEFT)
	{
		game->player.img_index = FACE_LEFT;
		check_move(game, game->player.current.x - 1, game->player.current.y);
	}
	else if (keycode == S || keycode == DOWN)
		check_move(game, game->player.current.x, game->player.current.y + 1);
	else if (keycode == D || keycode == RIGHT)
	{
		game->player.img_index = FACE_RIGHT;
		check_move(game, game->player.current.x + 1, game->player.current.y);
	}
	else if (keycode == ESC)
		exit_game(game, "You gave up! 🐔");
	return (0);
}
