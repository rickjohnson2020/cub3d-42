#include "../includes/cub3d.h"

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->input.w = 1;
	if (keycode == KEY_S)
		game->input.s = 1;
	if (keycode == KEY_D)
		game->input.d = 1;
	if (keycode == KEY_A)
		game->input.a = 1;
	if (keycode == KEY_RIGHT)
		game->input.right = 1;
	if (keycode == KEY_LEFT)
		game->input.left = 1;
	return (0);
}

int	handle_key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->input.w = 0;
	if (keycode == KEY_S)
		game->input.s = 0;
	if (keycode == KEY_D)
		game->input.d = 0;
	if (keycode == KEY_A)
		game->input.a = 0;
	if (keycode == KEY_RIGHT)
		game->input.right = 0;
	if (keycode == KEY_LEFT)
		game->input.left = 0;
	return (0);
}
