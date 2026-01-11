/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   init_game.c                                         :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*   By: takaito <takaito@student.42london.com>       +#+  +:+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2025/11/26 21:20:14 by takaito             #+#    #+#           */
/*   Updated: 2025/11/26 21:21:26 by takaito           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_game	*init_game(t_game *game, char *filename)
{
	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
	{
		free_game (game);
		return (NULL);
	}
	if (!init_mlx(game))
	{
		free_game(game);
		return (NULL);
	}
	if (!init_map(game, filename))
	{
		free_game (game); return (NULL);
	}
	set_map_size(game->map);
	init_input(&game->input);
	init_player(game);
	load_textures(game);
	return (game);
}

bool	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		put_error("mlx_init() error\n");
		return (false);
	}
	game->frame.width = WIN_WIDTH;
	game->frame.height = WIN_HEIGHT;
	game->win = mlx_new_window(game->mlx, game->frame.width, game->frame.height, "cub3D");
	if (!game->win)
	{
		//mlx_destroy_display(game->mlx);
		free(game->mlx);
		put_error("mlx_new_window() error\n");
		return (false);
	}
	game->frame.img = mlx_new_image(game->mlx, game->frame.width, game->frame.height);
	game->frame.addr = mlx_get_data_addr(game->frame.img, &game->frame.bits_per_pixel, &game->frame.line_len, &game->frame.endian);
	return (true);
}

void	init_input(t_input *i)
{
	i->w = 0;
	i->s = 0;
	i->d = 0;
	i->a = 0;
	i->right = 0;
	i->left = 0;
	i->esc = 0;
}

void	set_map_size(t_map *map)
{
	int	width;
	int y;
	int	len;

	width = 0;
	y = 0;
	len = 0;
	while (map->map[y])
	{
		len = ft_strlen(map->map[y]);
		if (width < len)
			width = len;
		y++;
	}
	map->height = y;
	map->width = width;
}
