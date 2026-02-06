/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:54:01 by riyano            #+#    #+#             */
/*   Updated: 2026/02/04 14:36:29 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifdef __APPLE__
#  include "../lib/minilibx-opengl/mlx.h"
#  define WINDOW_CLOSE 17
#  define KEY_ESC 53
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_PRESS 02
#  define KEY_RELEASE 03
# elif defined(__linux__)
#  include "../lib/minilibx-linux/mlx.h"
#  define WINDOW_CLOSE 17
#  define KEY_ESC 65307
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_PRESS 02
#  define KEY_RELEASE 03
# endif
# include "../lib/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <stdbool.h>
# include <fcntl.h>

# define WIN_WIDTH 1024
# define WIN_HEIGHT 768
# define MOVE_STEP 0.05
# define ROT_STEP 0.01 // radian
# define PLAYER_RADIUS 0.2
# define FOV_DEGREES 67
# define EPS 1e-9

typedef struct s_vec2d
{
	double	x;
	double	y;
}	t_vec2d;

typedef struct s_vec2i
{
	int	x;
	int	y;
}	t_vec2i;

typedef struct s_colour
{
	int	r;
	int	g;
	int	b;
}	t_colour;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		height;
	int		width;
}	t_image;

typedef struct s_player
{
	t_vec2d	pos;
	t_vec2d	dir;
	t_vec2d	plane;
}	t_player;

typedef struct s_textures
{
	t_image	north;
	t_image	south;
	t_image	west;
	t_image	east;
}	t_textures;

typedef struct s_map
{
	char		*file_north;
	char		*file_south;
	char		*file_west;
	char		*file_east;
	char		**map;
	t_colour	ceiling_colour;
	t_colour	floor_colour;
	t_textures	textures;
	int			width;
	int			height;
	bool		is_north_set;
	bool		is_south_set;
	bool		is_east_set;
	bool		is_west_set;
	bool		is_ceiling_set;
	bool		is_floor_set;
	bool		are_all_set;
}	t_map;

typedef enum e_wall_side
{
	WALL_VERTICAL,
	WALL_HORIZONTAL
}	t_wall_side;

typedef struct s_ray
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

typedef struct s_input
{
	int	w;
	int	s;
	int	d;
	int	a;
	int	right;
	int	left;
	int	esc;
}	t_input;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_image		frame;
	t_player	player;
	t_input		input;
}	t_game;

typedef struct s_wall_line
{
	int		draw_start;
	int		draw_end;
	double	tex_step;
	double	tex_pos;
}	t_wall_line;

// player movements
int				handle_key_press(int keycode, t_game *game);
int				handle_key_release(int keycode, t_game *game);
void			update_player_pos(t_game *game, t_player *p);
void			update_player_rot(t_game *game, t_player *p);

// game loop
int				game_loop(t_game *game);

// rendering
void			render_frame(t_game *game);
int				colour_to_int(t_colour c);
void			set_pixel(t_image *img, int x, int y, int colour);
unsigned int	get_pixel(t_image *img, int x, int y);
t_image			*select_wall_texture(t_game *game, t_ray *ray);
int				calculate_tex_x(t_image *tex, t_ray *ray, t_player *p);

// validate argument
bool			is_valid_filename(char *filename);
bool			is_valid_argv(int argc, char **argv);

// validate files
int				validate_file(char *filename);

// validate map
bool			validate_map(t_map *map);
char			**create_vmap(char **map, int num_lines, int max_len);
bool			validate_texture_path(t_map *map);
int				get_longest_str_len(char **dstr);
int				count_lines(char **dstr);
int				count_spaces(char *str);
bool			is_valid_colour(t_map *map);

// initialize
t_game			*init_game(t_game *game, char *filename);
bool			init_map(t_game *game, char *filename);
char			**read_config(char *filename);
bool			is_space(char c);
void			skip_empty_line(char ***file);
t_map			*parse(char **file);
bool			parse_colour(t_map *map, char ***file);
bool			parse_wall_textures(t_map *map, char ***file);
bool			parse_map(t_map *map, char ***file);
char			**store_file(char **file, char *new);
bool			check_store_file(char **file, char *new);
char			*ft_strndup(char *str, int start, int size);
bool			init_mlx(t_game *game);
void			init_input(t_input *i);
void			set_map_size(t_map *map);
void			init_player(t_game *game);
bool			load_textures(t_game *game);
void			init_ray_1(t_ray *ray, t_game *game, int x);
void			init_ray_2(t_ray *ray, t_game *game);
void			init_wall(t_image *frame, t_image *tex,
					t_wall_line *wall, t_ray *ray);

// error
void			put_error(char *msg);
void			put_file_error(char *msg, char *filename);

// clean up resources
void			free_map(t_map **map);
void			free_image(t_image *img);
void			free_game(t_game *game);
void			free_dstr(char **str);
int				close_window(t_game *game);
void			destroy_game(t_game **game_ptr);
#endif
