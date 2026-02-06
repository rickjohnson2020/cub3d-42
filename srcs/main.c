/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   main.c                                              :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*   By: takaito <takaito@student.42london.com>       +#+  +:+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2025/11/26 21:20:14 by takaito             #+#    #+#           */
/*   Updated: 2025/11/26 21:21:26 by takaito           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	print_config(t_game *game)
{
	int	i;

	i = 0;
	printf("map north file :%s\n", game->map->file_north);
	printf("map south file :%s\n", game->map->file_south);
	printf("map west file  :%s\n", game->map->file_west);
	printf("map east file  :%s\n", game->map->file_east);
	printf("map floor      :r:%d g:%d b:%d\n",
		game->map->floor_colour.r, game->map->floor_colour.g,
		game->map->floor_colour.b);
	printf("ceiling floor  :r:%d g:%d b:%d\n",
		game->map->ceiling_colour.r, game->map->ceiling_colour.g,
		game->map->ceiling_colour.b);
	if (!game->map->map)
		return ;
	while (game->map->map[i])
	{
		printf("map[%3d]:%s\n", i, game->map->map[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (!is_valid_argv(argc, argv))
		exit(EXIT_FAILURE);
	game = init_game(game, argv[1]);
	if (!game)
	{
		exit(EXIT_FAILURE);
		free_game(game);
	}
	print_config(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
	mlx_hook(game->win, WINDOW_CLOSE, 1L << 2, close_window, game);
	mlx_hook(game->win, KEY_PRESS, 1L << 0, handle_key_press, game);
	mlx_hook(game->win, KEY_RELEASE, 1L << 1, handle_key_release, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
	destroy_game(&game);
	exit(EXIT_SUCCESS);
}
