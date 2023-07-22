/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:03:17 by luide-so          #+#    #+#             */
/*   Updated: 2023/07/22 15:41:01 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../Libft/libft.h"
# include <fcntl.h>

# define TILE_SIZE 32
# define SP_LEN 2
# define TILLES "01CEP"
# define W_XPM "textures/1.xpm"
# define S_XPM "textures/0.xpm"
# define E_XPM "textures/E.xpm"
# define C1_XPM "textures/C1.xpm"
# define P1_XPM "textures/P1.xpm"
# define P2_XPM "textures/P4.xpm"

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
}				t_tile;

typedef enum e_img_index
{
	FACE_LEFT = 1,
	FACE_RIGHT = 0,
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
}				t_dummies;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	int			moves;
	t_dummies	player;
	t_img		img_p[SP_LEN];
	int			player_count;
	int			exit;
	int			collect;
	int			spaces;
	t_img		img_walls;
	t_img		img_space;
	t_img		img_exit;
	t_img		img_collect;
	int			x;
	int			y;
}				t_game;

int		exit_error(t_game *game, char *msg);
int		exit_game(t_game *game, char *msg);
int		exit_esc(t_game *game);
void	check_map(t_game *game);
void	init_game(t_game *game);
int		key_press(int keycode, t_game *game);
void	render_move(t_game *game, char current, char next, t_dummies *dummy);

#endif
