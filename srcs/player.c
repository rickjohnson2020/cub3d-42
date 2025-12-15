#include "../includes/cub3d.h"

void	update_player_pos(t_game *game, t_player *player, int keycode);
void	update_player_rot(t_player *p, int keycode);
// pass this function to mlx_loop_hook
//int		game_loop(t_game *game);
int		handle_key_press(int keycode, t_game *game);
int		handle_key_release(int keycode, t_game *game);
void	check_wall_and_update(t_game *game, double x, double y);

int	handle_key_press(int keycode, t_game *game)
{
	update_player_pos(game, &game->player, keycode);
	update_player_rot(&game->player, keycode);
	render_frame(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
	return (0);
}

void	update_player_pos(t_game *game, t_player *p, int key)
{
	t_vec2d	next_pos;

	if (key == KEY_W)
	{
		next_pos.x = p->pos.x + p->dir.x * p->move_speed;
		next_pos.y = p->pos.y + p->dir.y * p->move_speed;
	}
	else if (key == KEY_S)
	{
		next_pos.x = p->pos.x + p->dir.x * -(p->move_speed);
		next_pos.y = p->pos.y + p->dir.y * -(p->move_speed);
	}
	else if (key == KEY_D)
	{
		next_pos.x = p->pos.x + p->plane.x * p->move_speed;
		next_pos.y = p->pos.y + p->plane.y * p->move_speed;
	}
	else if (key == KEY_A)
	{
		next_pos.x = p->pos.x + p->plane.x * -(p->move_speed);
		next_pos.y = p->pos.y + p->plane.y * -(p->move_speed);
	}
	if (key == KEY_W || key == KEY_S || key == KEY_D || key == KEY_A)
		check_wall_and_update(game, next_pos.x, next_pos.y);
}

void	check_wall_and_update(t_game *game, double x, double y)
{
	if (game->map->map[(int)y][(int)x] == '0')
	{
		game->player.pos.x = x;
		game->player.pos.y = y;
	}
}

void	update_player_rot(t_player *p, int keycode)
{
	if (keycode == KEY_RIGHT)
	{
		p->dir.x = p->dir.x * cos(p->rot_speed) - p->dir.y * sin(p->rot_speed);
		p->dir.y = p->dir.x * sin(p->rot_speed) + p->dir.y * cos(p->rot_speed);
		p->plane.x = p->plane.x * cos(p->rot_speed) - p->plane.y * sin(p->rot_speed);
		p->plane.y = p->plane.x * sin(p->rot_speed) + p->plane.y * cos(p->rot_speed);
	}
	else if (keycode == KEY_LEFT)
	{
		p->dir.x = p->dir.x * cos(-(p->rot_speed)) - p->dir.y * sin(-(p->rot_speed));
		p->dir.y = p->dir.x * sin(-(p->rot_speed)) + p->dir.y * cos(-(p->rot_speed));
		p->plane.x = p->plane.x * cos(-(p->rot_speed)) - p->plane.y * sin(-(p->rot_speed));
		p->plane.y = p->plane.x * sin(-(p->rot_speed)) + p->plane.y * cos(-(p->rot_speed));
	}
}
