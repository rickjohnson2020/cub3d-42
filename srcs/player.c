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

static void	update_player_pos(t_game *game, t_player *p, int key);
static void	update_player_rot(t_player *p, int key);
static void	check_wall_and_update(t_game *game, t_vec2d pos, int key);

int	game_loop(t_game *game)
{
	if (game->input.esc == 1)
		close_window(game);
	if (game->input.w == 1)
		update_player_pos(game, &game->player, KEY_W);
	if (game->input.s == 1)
		update_player_pos(game, &game->player, KEY_S);
	if (game->input.d == 1)
		update_player_pos(game, &game->player, KEY_D);
	if (game->input.a == 1)
		update_player_pos(game, &game->player, KEY_A);
	if (game->input.right == 1)
		update_player_rot(&game->player, KEY_RIGHT);
	if (game->input.left == 1)
		update_player_rot(&game->player, KEY_LEFT);
	render_frame(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
	return (0);
}

static void	update_player_pos(t_game *game, t_player *p, int key)
{
	t_vec2d	next_pos;

	if (key == KEY_W)
	{
		next_pos.x = p->pos.x + p->dir.x * MOVE_SPEED;
		next_pos.y = p->pos.y + p->dir.y * MOVE_SPEED;
	}
	else if (key == KEY_S)
	{
		next_pos.x = p->pos.x + p->dir.x * -MOVE_SPEED;
		next_pos.y = p->pos.y + p->dir.y * -MOVE_SPEED;
	}
	else if (key == KEY_D)
	{
		next_pos.x = p->pos.x + p->plane.x * MOVE_SPEED;
		next_pos.y = p->pos.y + p->plane.y * MOVE_SPEED;
	}
	else if (key == KEY_A)
	{
		next_pos.x = p->pos.x + p->plane.x * -MOVE_SPEED;
		next_pos.y = p->pos.y + p->plane.y * -MOVE_SPEED;
	}
	if (key == KEY_W || key == KEY_S || key == KEY_D || key == KEY_A)
		check_wall_and_update(game, next_pos, key);
}

static void	check_wall_and_update(t_game *game, t_vec2d pos, int key)
{
	int	check_x;
	int	check_y;

	if (key == KEY_W)
		check_x = pos.x + game->player.dir.x * PLAYER_RADIUS;
	else if (key == KEY_S)
		check_x = pos.x + game->player.dir.x * -PLAYER_RADIUS;
	else if (key == KEY_D)
		check_x = pos.x + game->player.plane.x * PLAYER_RADIUS;
	else
		check_x = pos.x + game->player.plane.x * -PLAYER_RADIUS;
	if (game->map->map[(int)game->player.pos.y][check_x] != '1')
		game->player.pos.x = pos.x;
	if (key == KEY_W)
		check_y = pos.y + game->player.dir.y * PLAYER_RADIUS;
	else if (key == KEY_S)
		check_y = pos.y + game->player.dir.y * -PLAYER_RADIUS;
	else if (key == KEY_D)
		check_y = pos.y + game->player.plane.y * PLAYER_RADIUS;
	else
		check_y = pos.y + game->player.plane.y * -PLAYER_RADIUS;
	if (game->map->map[check_y][(int)game->player.pos.x] != '1')
		game->player.pos.y = pos.y;
}

static void	update_player_rot(t_player *p, int key)
{
	double	tmp_dir_x;
	double	tmp_plane_x;

	if (key == KEY_RIGHT)
	{
		tmp_dir_x = p->dir.x * cos(ROT_SPEED) - p->dir.y * sin(ROT_SPEED);
		p->dir.y = p->dir.x * sin(ROT_SPEED) + p->dir.y * cos(ROT_SPEED);
		p->dir.x = tmp_dir_x;
		tmp_plane_x = p->plane.x * cos(ROT_SPEED) - p->plane.y * sin(ROT_SPEED);
		p->plane.y = p->plane.x * sin(ROT_SPEED) + p->plane.y * cos(ROT_SPEED);
		p->plane.x = tmp_plane_x;
	}
	else if (key == KEY_LEFT)
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
