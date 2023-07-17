/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:03:17 by luide-so          #+#    #+#             */
/*   Updated: 2023/07/17 17:18:32 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include "../Libft/libft.h"
# include <fcntl.h>
# include <time.h>

# define TILE_SIZE 32
# define SP_LEN 2
# define SP_ANIM 4
# define SP_ANIM_SPEED 100000
# define ENEMY_SPEED 250000
# define TILLES "01CEP"
# define SPACES_PER_ENEMY 60
# define WALL_XPM "textures/1.xpm"
# define SPACE_XPM "textures/0.xpm"
# define EXIT_XPM "textures/E.xpm"
# define COLLECT1_XPM "textures/C1.xpm"
# define COLLECT2_XPM "textures/C2.xpm"
# define COLLECT3_XPM "textures/C3.xpm"
# define COLLECT4_XPM "textures/C4.xpm"
# define PLAYER1_XPM "textures/P1.xpm"
# define PLAYER2_XPM "textures/P2.xpm"
# define ENEMY1_XPM "textures/X1.xpm"
# define ENEMY2_XPM "textures/X2.xpm"

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
	int		direction;
}				t_dummies;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_dummies	player;
	int			moves;
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
	t_img		img_collect[SP_ANIM];
	int			anim_index;
	long		clock_anim;
	long		clock_enemy;
}				t_game;

int		exit_error(t_game *game, char *msg);
int		exit_game(t_game *game, char *msg);
int		exit_esc(t_game *game);
void	check_map(t_game *game);
void	init_game(t_game *game);
void	init_enemy(t_game *game);
int		key_press(int keycode, t_game *game);
void	render_move(t_game *game, char current, char next, t_dummies *dummy);
int		game_loop(t_game *game);

#endif
