/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:30:50 by riyano            #+#    #+#             */
/*   Updated: 2026/01/11 18:32:10 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_player_dir(t_player *p, char dir);
static void	set_player_plane(t_player *p, char dir);

void	init_player(t_game *game)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (!game->map->map[y][x])
				break ;
			c = game->map->map[y][x];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				game->player.pos.x = x + 0.5;
				game->player.pos.y = y + 0.5;
				set_player_dir(&game->player, c);
				set_player_plane(&game->player, c);
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	set_player_dir(t_player *p, char dir)
{
	if (dir == 'N')
	{
		p->dir.x = 0;
		p->dir.y = -1;
	}
	else if (dir == 'S')
	{
		p->dir.x = 0;
		p->dir.y = 1;
	}
	else if (dir == 'E')
	{
		p->dir.x = 1;
		p->dir.y = 0;
	}
	else if (dir == 'W')
	{
		p->dir.x = -1;
		p->dir.y = 0;
	}
}

static void	set_player_plane(t_player *p, char dir)
{
	if (dir == 'N')
	{
		p->plane.x = 0.66;
		p->plane.y = 0;
	}
	else if (dir == 'S')
	{
		p->plane.x = -0.66;
		p->plane.y = 0;
	}
	else if (dir == 'E')
	{
		p->plane.x = 0;
		p->plane.y = 0.66;
	}
	else if (dir == 'W')
	{
		p->plane.x = 0;
		p->plane.y = -0.66;
	}
}
