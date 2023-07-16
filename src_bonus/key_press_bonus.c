/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:01:20 by luide-so          #+#    #+#             */
/*   Updated: 2023/07/16 01:43:17 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	print_moves(t_game *game)
{
	ft_printf("Player moves: %d\n", ++game->moves);
}

static void	check_move(t_game *game, int x, int y)
{
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
//	render_move(game, x, y);
	game->player.current = game->player.next;
	ft_printf("Player position after: %d, %d\n", game->player.current.x,
		game->player.current.y);
}

int	key_press(int keycode, t_game *game)
{
	ft_printf("Keycode: %d\n", keycode);
	if (keycode == W || keycode == UP)
		check_move(game, game->player.current.x, game->player.current.y - 1);
	else if (keycode == A || keycode == LEFT)
		check_move(game, game->player.current.x - 1, game->player.current.y);
	else if (keycode == S || keycode == DOWN)
		check_move(game, game->player.current.x, game->player.current.y + 1);
	else if (keycode == D || keycode == RIGHT)
		check_move(game, game->player.current.x + 1, game->player.current.y);
	else if (keycode == ESC)
		exit_game(game, "You gave up! 🐔");
	return (0);
}
