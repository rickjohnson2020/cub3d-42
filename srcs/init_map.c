/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   init_game.c                                         :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*   By: takaito <takaito@student.42london.com>       +#+  +:+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2025/11/26 21:20:14 by takaito             #+#    #+#           */
/*   Updated: 2025/11/26 21:21:26 by takaito           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool		parse_helper(t_map *map, char **file);
static void		are_all_elements_set(t_map *map);

bool	init_map(t_game *game, char *filename)
{
	char	**config;

	config = read_config(filename);
	if (!config)
	{
		if (errno == 0)
			put_error("Map is empty or an error occured while reading file.\n");
		return (false);
	}
	game->map = parse(config);
	free_dstr(config);
	if (!game->map)
		return (false);
	if (!validate_map(game->map))
		return (false);
	if (!validate_texture_path(game->map))
		return (put_error("Failed to open texture file\n"), false);
	if (!is_valid_colour(game->map))
		return (put_error("Invalid colour format\n"), false);
	return (true);
}

t_map	*parse(char **file)
{
	t_map	*map;

	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
	{
		put_error("malloc() failed in parse() function\n");
		return (NULL);
	}
	while (!map->are_all_set && *file != NULL)
	{
		if (!parse_helper(map, file))
			return (NULL);
		file++;
	}
	if (!map || !map->are_all_set)
	{
		put_error("Failed to parse wall or colour\n");
		return (free_map (&map), NULL);
	}
	if (map && !parse_map(map, &file))
	{
		put_error("failed to parse map\n");
		free_map (&map);
	}
	return (map);
}

static bool	parse_helper(t_map *map, char **file)
{
	if (!is_valid_identifier(file))
	{
		free_map(&map);
		return (false);
	}
	if (!parse_wall_textures(map, &file))
	{
		free_map(&map);
		return (false);
	}
	else if (!parse_colour(map, &file))
	{
		free_map(&map);
		return (false);
	}
	are_all_elements_set(map);
	return (true);
}

static void	are_all_elements_set(t_map *map)
{
	if (map->is_north_set && map->is_south_set && map->is_east_set
		&& map->is_west_set && map->is_ceiling_set && map->is_floor_set)
		map->are_all_set = true;
}
