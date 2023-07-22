/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:02:18 by luide-so          #+#    #+#             */
/*   Updated: 2023/07/22 15:39:44 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_get_grid(t_game *game, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error(NULL, "Couldn't open requested file.");
	line = get_next_line(fd);
	game->map.cols = ft_strclen(line, '\n');
	game->map.rows = 0;
	while (line && ++game->map.rows)
	{
		if ((ft_strclen(line, '\n') != (size_t)game->map.cols))
		{
			free(line);
			exit_error(NULL, "Map is not a rectangle.");
		}
		free(line);
		line = get_next_line(fd);
	}
	if (!game->map.cols)
		exit_error(NULL, "Map is empty.");
	close(fd);
}

static void	create_map(t_game *game, char *file)
{
	int		fd;
	char	*line;
	int		i;

	check_get_grid(game, file);
	game->map.grid = ft_calloc(game->map.rows + 1, sizeof(char *));
	if (!game->map.grid)
		exit_error(NULL, "Couldn't allocate memory.");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error(game, "Couldn't open requested file.");
	line = get_next_line(fd);
	i = -1;
	while (line)
	{
		game->map.grid[++i] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	check_map(game);
}

static void	so_long(char *file)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	create_map(&game, file);
	init_game(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 17, 1L << 17, exit_esc, &game);
	mlx_loop(game.mlx);
}

static void	check_filename(char *file)
{
	size_t	i;

	i = ft_strlen(file);
	if (i <= 4)
		exit_error(NULL, "Invalid file name.");
	else if (!ft_strnstr((file + i - 4), ".ber", 4))
		exit_error(NULL, "Invalid file extension.");
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_error(NULL, "Usage: ./so_long <map_name>.ber");
	check_filename(av[1]);
	so_long(av[1]);
}
