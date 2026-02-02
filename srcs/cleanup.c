/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 21:12:35 by riyano            #+#    #+#             */
/*   Updated: 2026/02/02 21:36:15 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	destroy_image(void *mlx, t_image *img)
{
	if (!mlx || !img || !img->img)
		return ;
	mlx_destroy_image(mlx, img->img);
	img->img = NULL;
	img->addr = NULL;
}

static void	destroy_textures(t_game *g)
{
	if (!g || !g->map)
		return ;
	destroy_image(g->mlx, &g->map->textures.north);
	destroy_image(g->mlx, &g->map->textures.south);
	destroy_image(g->mlx, &g->map->textures.west);
	destroy_image(g->mlx, &g->map->textures.east);
}

static void	destroy_mlx(t_game *g)
{
	if (!g)
		return ;
	if (g->mlx && g->frame.img)
		destroy_image(g->mlx, &g->frame);
	if (g->mlx && g->win)
	{
		mlx_destroy_window(g->mlx, g->win);
		g->win = NULL;
	}
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
		g->mlx = NULL;
	}
}

static void	destroy_map(t_game *g)
{
	if (!g || !g->map)
		return ;
	free_map(&g->map);
}

void	destroy_game(t_game **game_ptr)
{
	t_game	*g;

	if (!game_ptr || !*game_ptr)
		return ;
	g = *game_ptr;
	destroy_textures(g);
	destroy_mlx(g);
	destroy_map(g);
	free(g);
	*game_ptr = NULL;
}

int	close_window(t_game *game)
{
	destroy_game(&game);
	exit(EXIT_SUCCESS);
	return (0);
}
