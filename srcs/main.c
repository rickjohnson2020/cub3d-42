/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   main.c                                              :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*   By: takaito <takaito@student.42london.com>       +#+  +:+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2025/11/26 21:20:14 by takaito             #+#    #+#           */
/*   Updated: 2025/11/26 21:21:26 by takaito           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	print_config(t_game *game)
{
	int	i;

	i = 0;
	printf("map north file :%s\n", game->map->file_north);
	printf("map south file :%s\n", game->map->file_south);
	printf("map west file  :%s\n", game->map->file_west);
	printf("map east file  :%s\n", game->map->file_east);
	printf("map floor      :%s\n", game->map->floor);
	printf("map floor hex  :%s\n", game->map->floor_hex);
	printf("map ceiling    :%s\n", game->map->ceiling);
	printf("map ceiling hex:%s\n", game->map->ceiling_hex);
	if (!game->map->map)
		return ;
	while (game->map->map[i])
	{
		printf("map[%3d]:%s\n", i, game->map->map[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (!is_valid_argv(argc, argv))
		exit(EXIT_FAILURE);
	game = init_game(game, argv[1]);
	if (!game)
	{
		exit(EXIT_FAILURE);
		free_game(game);
	}
	print_config(game);
	free_game(game);
	exit(EXIT_SUCCESS);
}

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	buf[101];

// 	if (argc < 1)
// 		return (1);
// 	fd = open(argv[1], O_RDONLY);
// 	if (errno)
// 	{
// 		printf("%s\n", strerror(errno));
// 		return (errno);
// 	}
// 	read(fd, buf, 99);
// 	if (errno)
// 	{
// 		printf("%s\n", strerror(errno));
// 		return (errno);
// 	}
// 	printf("%s\n", strerror(errno));
// 	buf[100] = '\0';
// 	printf("%s\n", buf);
// 	return (errno);
// }