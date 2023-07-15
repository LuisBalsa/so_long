/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:03:17 by luide-so          #+#    #+#             */
/*   Updated: 2023/07/15 16:34:26 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include "../Libft/libft.h"
# include <fcntl.h>
# include <time.h>

# define TILE_SIZE 32
# define SP_LEN 8
# define TILLES "01CEP"
# define SPACES_PER_ENEMY 10

typedef enum e_key
{
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	ESC = 65307,
	UP = 65362,
	LEFT = 65361,
	DOWN = 65364,
	RIGHT = 65363,
}				t_key;

typedef enum e_tile
{
	WALL = '1',
	SPACE = '0',
	EXIT = 'E',
	COLLECT = 'C',
	PLAYER = 'P',
	ENEMY = 'X',
}				t_tile;

// falta ver como fazer com os inimigos, talvez pelo index destes enums (0 a 3) se é que é possivel
typedef enum e_img_index
{
	FACE_LEFT = 0,
	FACE_RIGHT = 4,
}				t_img_index;

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_map
{
	char	**grid;
	int		rows;
	int		cols;
}				t_map;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}				t_img;

typedef struct s_dummies
{
	t_point	current;
	char	current_tile;
	t_point	next;
	int		img_index;
	int		collect;
	int		move;
}				t_dummies;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_dummies	player;
	t_img		img_p[SP_LEN];
	t_dummies	*enemy;
	t_img		img_e[SP_LEN];
	int			player_count;
	int			enemy_count;
	int			exit;
	int			collect;
	int			spaces;
	t_img		img_walls;
	t_img		img_space;
	t_img		img_exit;
	t_img		img_collect;
}				t_game;

int		exit_error(t_game *game, char *msg);
int		exit_game(t_game *game, char *msg);
void	check_map(t_game *game);
void	init_game(t_game *game);
void	init_enemy(t_game *game);

#endif
