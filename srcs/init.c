#include "../includes/cub3d.h"

void	init_player(t_player *p)
{
	p->pos.x = 3.5;
	p->pos.y = 5.5;
	p->dir.x = -0.7;
	p->dir.y = -0.7;
	p->plane.x = 0.46;
	p->plane.y = -0.46;
}

void	init_input(t_input *i)
{
	i->w = 0;
	i->s = 0;
	i->d = 0;
	i->a = 0;
	i->right = 0;
	i->left = 0;
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return ;
}

static char	**dup_map(void)
{
	int	i;

	static char *src[] =
	{
		"1111111111",
		"1000000001",
		"1000000001",
		"1000000001",
		"1000010001",
		"1000000001",
		"1000000001",
		"1000000001",
		"1000000001",
		"1111111111",
		NULL
	};

	char **map = malloc(sizeof(char *) * 11);
    if (!map)
		return (NULL);

	i = 0;
	while (src[i])
	{
		map[i] = strdup(src[i]);
		if (!map[i])
			return (NULL);
		i++;
	}
	map[10] = NULL;
	return (map);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	game->frame.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->frame.addr = mlx_get_data_addr(game->frame.img, &game->frame.bits_per_pixel, &game->frame.line_len, &game->frame.endian);

	game->map = malloc(sizeof(*game->map));
	game->map->map = dup_map();

	game->frame.size.x = WIN_WIDTH;
	game->frame.size.y = WIN_HEIGHT;

	init_player(&game->player);
	init_input(&game->input);
}
