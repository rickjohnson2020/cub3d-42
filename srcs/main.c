#include "../includes/cub3d.h"

int	main(void)
{
	t_game		game;

	init_game(&game);
	render_frame(&game);
	mlx_put_image_to_window(game.mlx, game.win, game.frame.img, 0, 0);
	mlx_key_hook(game.win, handle_key_press, &game);
	mlx_loop(game.mlx);
	return (0);
}
