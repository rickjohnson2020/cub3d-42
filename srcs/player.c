/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:54:48 by riyano            #+#    #+#             */
/*   Updated: 2026/01/11 19:04:42 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	update_player_pos(t_game *game, t_player *p);
static void	update_player_rot(t_game *game, t_player *p);
static void	check_wall_and_update(t_game *game, t_vec2d pos, t_vec2d dir);
static int	is_inside_map(t_map *map, int x, int y);

int	game_loop(t_game *game)
{
	if (game->input.esc)
		close_window(game);
	update_player_pos(game, &game->player);
	update_player_rot(game, &game->player);
	render_frame(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
	return (0);
}

static void	update_player_pos(t_game *game, t_player *p)
{
	t_vec2d	move_dir;
	t_vec2d	next_pos;

	move_dir.x = 0;
	move_dir.y = 0;
	if (game->input.w)
	{
		move_dir.x += p->dir.x;
		move_dir.y += p->dir.y;
	}
	if (game->input.s)
	{
		move_dir.x -= p->dir.x;
		move_dir.y -= p->dir.y;
	}
	if (game->input.d)
	{
		move_dir.x += p->plane.x;
		move_dir.y += p->plane.y;
	}
	if (game->input.a)
	{
		move_dir.x -= p->plane.x;
		move_dir.y -= p->plane.y;
	}
	if (fabs(move_dir.x) < 1e-9 && fabs(move_dir.y) < 1e-9)
		return ;
	next_pos.x = p->pos.x + move_dir.x * MOVE_SPEED;
	next_pos.y = p->pos.y + move_dir.y * MOVE_SPEED;
	check_wall_and_update(game, next_pos, move_dir);
}

static void	check_wall_and_update(t_game *game, t_vec2d pos, t_vec2d dir)
{
	int	check_x;
	int	check_y;

	check_x = (int)(pos.x + dir.x * PLAYER_RADIUS);
	check_y = (int)(pos.y + dir.y * PLAYER_RADIUS);
	if (is_inside_map(game->map, check_x, (int)game->player.pos.y)
			&& game->map->map[(int)game->player.pos.y][check_x] != '1')
		game->player.pos.x = pos.x;
	if (is_inside_map(game->map, (int)game->player.pos.x, check_y)
			&& game->map->map[check_y][(int)game->player.pos.x] != '1')
		game->player.pos.y = pos.y;
}

static int	is_inside_map(t_map *map, int x, int y)
{
	int	row_len;

	if (y < 0 || y >= map->height)
		return (0);
	if (x < 0)
		return (0);
	row_len  = ft_strlen(map->map[y]);
	if (x >= row_len)
		return (0);
	return (1);
}

static void	update_player_rot(t_game *game, t_player *p)
{
	double	tmp_dir_x;
	double	tmp_plane_x;

	if (game->input.right)
	{
		tmp_dir_x = p->dir.x * cos(ROT_SPEED) - p->dir.y * sin(ROT_SPEED);
		p->dir.y = p->dir.x * sin(ROT_SPEED) + p->dir.y * cos(ROT_SPEED);
		p->dir.x = tmp_dir_x;
		tmp_plane_x = p->plane.x * cos(ROT_SPEED) - p->plane.y * sin(ROT_SPEED);
		p->plane.y = p->plane.x * sin(ROT_SPEED) + p->plane.y * cos(ROT_SPEED);
		p->plane.x = tmp_plane_x;
	}
	else if (game->input.left)
	{
		tmp_dir_x = p->dir.x * cos(-ROT_SPEED) - p->dir.y * sin(-ROT_SPEED);
		p->dir.y = p->dir.x * sin(-ROT_SPEED) + p->dir.y * cos(-ROT_SPEED);
		p->dir.x = tmp_dir_x;
		tmp_plane_x = p->plane.x * cos(-ROT_SPEED)
			- p->plane.y * sin(-ROT_SPEED);
		p->plane.y = p->plane.x * sin(-ROT_SPEED)
			+ p->plane.y * cos(-ROT_SPEED);
		p->plane.x = tmp_plane_x;
	}
}
