/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:03:17 by luide-so          #+#    #+#             */
/*   Updated: 2023/07/19 17:52:22 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../minilibx-linux/mlx.h"
# include "../Libft/libft.h"
# include <fcntl.h>
# include <time.h>

# define TILE_SIZE 32
# define SP_LEN 4
# define SP_E_LEN 8
# define SP_ANIM 4
# define SP_ANIM_SPEED 100000
# define ENEMY_SPEED 250000
# define SPACES_PER_ENEMY 50
# define TRUMP_MODE 1
# define TRUMP_STEPS 50
# define TILLES "01CEP"
# define W_XPM "textures/1.xpm"
# define S_XPM "textures/0.xpm"
# define E_XPM "textures/E.xpm"
# define C1_XPM "textures/C1.xpm"
# define C2_XPM "textures/C2.xpm"
# define C3_XPM "textures/C3.xpm"
# define C4_XPM "textures/C4.xpm"
# define P1_XPM "textures/P1.xpm"
# define P2_XPM "textures/P2.xpm"
# define P3_XPM "textures/P3.xpm"
# define P4_XPM "textures/P4.xpm"
# define E1_XPM "textures/X1.xpm"
# define E2_XPM "textures/X2.xpm"
# define E3_XPM "textures/X3.xpm"
# define E4_XPM "textures/X4.xpm"
# define E5_XPM "textures/X5.xpm"
# define E6_XPM "textures/X6.xpm"
# define E7_XPM "textures/X7.xpm"
# define E8_XPM "textures/X8.xpm"

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
	FACE_LEFT = 2,
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
	int		i_anim;
	int		collect;
	int		direction;
	int		trump;
}				t_dummies;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	int			moves;
	t_dummies	player;
	t_img		img_p[SP_LEN];
	t_dummies	*enemy;
	t_img		img_e[SP_E_LEN];
	int			trump_steps;
	int			**path_grid;
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
	int			x;
	int			y;
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
void	eric_trump(t_game *game);

#endif
