/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   free_all.c                                           :+:      :+:    :+: */
/*                                                     +:+ +:+         +:+    */
/*   By: takaito <takaito@student.42london.com>       +#+  +:+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2025/11/26 21:20:14 by takaito             #+#    #+#           */
/*   Updated: 2025/11/26 21:20:20 by takaito            ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
	{
		free_map(&game->map);
		game->map = NULL;
	}
	if (game->mlx)
	{
		(void)game->mlx;
	}
	if (game->win)
	{
		(void)game->win;
	}
	free (game);
}

int	close_window(t_game *game)
{
	mlx_destroy_image(game->mlx, game->frame.img);
	mlx_destroy_image(game->mlx, game->map->textures.east.img);
	mlx_destroy_image(game->mlx, game->map->textures.west.img);
	mlx_destroy_image(game->mlx, game->map->textures.south.img);
	mlx_destroy_image(game->mlx, game->map->textures.north.img);
	mlx_destroy_window(game->mlx, game->win);
	//mlx_loop_end(game->mlx);
	//mlx_destroy_display(game->mlx);
	free_game(game);
	exit(EXIT_SUCCESS);
}
