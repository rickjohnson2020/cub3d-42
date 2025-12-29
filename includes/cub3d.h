#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-opengl/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>
# include <stdio.h>

# define WIN_WIDTH 1024
# define WIN_HEIGHT 768

# define MOVE_SPEED 0.05
# define ROT_SPEED 0.01

# define RED 0x00FF0000
# define DARK_RED 0x00800000

// for linux
//# define MOUSE_DOWN 4
//# define MOUSE_UP 5
//# define WINDOW_CLOSE 17
//# define KEY_ESC 65307
//# define KEY_LEFT 65361
//# define KEY_UP 65362
//# define KEY_RIGHT 65363
//# define KEY_DOWN 65364
//# define KEY_A 97
//# define KEY_D 100
//# define KEY_W 119
//# define KEY_S 115

// for mac
# define MOUSE_DOWN 4
# define MOUSE_UP 5
# define WINDOW_CLOSE 17
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_UP 126
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_A 0
# define KEY_D 2
# define KEY_W 13
# define KEY_S 1
# define KEY_PRESS 02
# define KEY_RELEASE 03

typedef struct	s_vec2d
{
	double	x;
	double	y;
}	t_vec2d;

typedef struct	s_vec2i
{
	int	x;
	int	y;
}	t_vec2i;

typedef struct	s_colour
{
	int	r;
	int	g;
	int	b;
}	t_colour;

typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		height;
	int		width;
}	t_image;

typedef struct	s_player
{
	t_vec2d	pos;
	t_vec2d	dir;
	t_vec2d	plane;
	double	move_speed;
	double	rot_speed;
}	t_player;

typedef struct	s_textures
{
	t_image	north;
	t_image	south;
	t_image	west;
	t_image	east;
}	t_textures;

typedef struct	s_map
{
	char		*file_north;
	char		*file_south;
	char		*file_west;
	char		*file_east;
	char		**map;
	t_colour	ceiling_colour;
	t_colour	floor_colour;
	t_textures	textures;
	int		width;
	int		height;
}	t_map;


typedef enum	e_wall_side
{
	WALL_VERTICAL,
	WALL_HORIZONTAL
}	t_wall_side;

typedef struct	s_ray
{
	double		camera_x; // for normalisation (-1 ~ 1)
	t_vec2d		dir; // direction of ray
	t_vec2i		current_cell; // (map.x, map.y)
	t_vec2d		next_boundary_dist; // distance to first grid boundary
	t_vec2d		step_cost; // distance for the ray to move one grid cell
	double		distance_to_wall;
	t_vec2i		step; // direction for the next step (-1 or 1)
	int			hit; // whether it hits the wall or not
	t_wall_side	hit_side;
}	t_ray;

typedef struct	s_input
{
	int	w;
	int	s;
	int	d;
	int	a;
	int	right;
	int	left;
	int	esc;
}	t_input;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_image		frame;
	t_player	player;
	t_input		input;
}	t_game;

typedef struct	s_wall_line
{
	int		height;
	int		draw_start;
	int		draw_end;
	double	tex_x;
	double	tex_step;
	double	tex_pos;
}	t_wall_line;

void	render_frame(t_game *game);
void	init_game(t_game *game);
int		handle_key_press(int keycode, t_game *game);
int		handle_key_release(int keycode, t_game *game);
int		game_loop(t_game *game);
void	load_textures(t_game *game);
t_image	*select_wall_texture(t_game *game, t_ray *ray);
int		calculate_tex_x(t_image *tex, t_ray *ray, t_player *p);

#endif
