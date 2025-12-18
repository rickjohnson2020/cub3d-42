/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   cub3d.h                                             :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*   By: takaito <takaito@student.42london.com>       +#+  +:+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2025/11/26 21:20:14 by takaito             #+#    #+#           */
/*   Updated: 2025/11/26 21:22:20 by takaito           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>
# include "../lib/libft/libft.h"

typedef struct s_image	t_image;
struct s_image
{
	void	*north;
	void	*south;
	void	*west;
	void	*east;
	void	*floor;
	void	*ceiling;
	void	*space;
};

typedef struct s_map	t_map;
struct s_map
{
	char	*file_north;
	char	*file_south;
	char	*file_west;
	char	*file_east;
	char	**map;
	char	*floor; // taking RGB as xxx.xxx.xxx
	char	*ceiling; // taking RGB as xxx.xxx.xxx
	char	*floor_hex; //"#373737" taking RGB as hex
	char	*ceiling_hex; //"#373737" taking RGB as hex
	t_image	*img;
};

typedef struct s_game	t_game;
struct s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
//	t_player	player;
};

// validate argument
bool	is_valid_filename(char *filename);
bool	is_valid_argv(int argc, char **argv);

// validate files
int		validate_file(char *filename);

// initialize
t_game	*init_game(t_game *game, char *filename);
bool	init_map(t_game *game, char *filename);
char	**read_config(char *filename);
bool	is_space(char c);
void	skip_empty_line(char ***file);
t_map	*parse(char **file);
bool	parse_colour(t_map *map, char ***file);
bool	parse_wall_textures(t_map *map, char ***file);
bool	parse_map(t_map *map, char ***file);
char	**store_file(char **file, char *new);
bool	check_store_file(char **file, char *new);
char	*ft_strndup(char *str, int start, int size);

// error
void	put_error(char *msg);
void	put_file_error(char *msg, char *filename);

// clean up resources
void	free_map(t_map **map);
void	free_image(t_image *img);
void	free_game(t_game *game);
void	free_dstr(char **str);
