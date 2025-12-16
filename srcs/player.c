#include "../includes/cub3d.h"

void	update_player_pos(t_game *game, t_player *p, int key);
void	update_player_rot(t_player *p, int key);
// pass this function to mlx_loop_hook
//int		game_loop(t_game *game);
int		handle_key_press(int keycode, t_game *game);
int		handle_key_release(int keycode, t_game *game);
void	check_wall_and_update(t_game *game, t_player *p, double x, double y);

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
		check_wall_and_update(game, p, next_pos.x, next_pos.y);
}

void	check_wall_and_update(t_game *game, t_player *p, double x, double y)
{
	if (game->map->map[(int)p->pos.y][(int)x] != '1')
		game->player.pos.x = x;
	if (game->map->map[(int)y][(int)p->pos.x] != '1')
		game->player.pos.y = y;
}

void	update_player_rot(t_player *p, int key)
{
	t_vec2d	new_dir;
	t_vec2d	new_plane;

	if (key == KEY_RIGHT)
	{
		new_dir.x = p->dir.x * cos(ROT_SPEED) - p->dir.y * sin(ROT_SPEED);
		new_dir.y = p->dir.x * sin(ROT_SPEED) + p->dir.y * cos(ROT_SPEED);
		p->dir.x = new_dir.x;
		p->dir.y = new_dir.y;
		new_plane.x = p->plane.x * cos(ROT_SPEED) - p->plane.y * sin(ROT_SPEED);
		new_plane.y = p->plane.x * sin(ROT_SPEED) + p->plane.y * cos(ROT_SPEED);
		p->plane.x = new_plane.x;
		p->plane.y = new_plane.y;
	}
	else if (key == KEY_LEFT)
	{
		new_dir.x = p->dir.x * cos(-ROT_SPEED) - p->dir.y * sin(-ROT_SPEED);
		new_dir.y = p->dir.x * sin(-ROT_SPEED) + p->dir.y * cos(-ROT_SPEED);
		p->dir.x = new_dir.x;
		p->dir.y = new_dir.y;
		new_plane.x = p->plane.x * cos(-ROT_SPEED) - p->plane.y * sin(-ROT_SPEED);
		new_plane.y = p->plane.x * sin(-ROT_SPEED) + p->plane.y * cos(-ROT_SPEED);
		p->plane.x = new_plane.x;
		p->plane.y = new_plane.y;
	}
}
