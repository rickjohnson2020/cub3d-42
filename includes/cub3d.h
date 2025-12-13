#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-opengl/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>

# define WIN_WIDTH 1024
# define WIN_HEIGHT 768

# define RED 0x00FF0000
# define DARK_RED 0x00800000


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
	t_vec2i	size;
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

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_image		frame;
	t_player	player;
}	t_game;

//typedef struct	s_wall_line
//{
//	int	height;
//	int	draw_start;
//	int	draw_end;
//}	t_wall_line;

void	render_frame(t_game *game);
void	init_game(t_game *game);

#endif
