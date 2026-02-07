/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   parse_wall.c                                        :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*   By: takaito <takaito@student.42london.com>       +#+  +:+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2025/11/26 21:20:14 by takaito             #+#    #+#           */
/*   Updated: 2025/11/26 21:21:26 by takaito           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	parse_north(t_map *map, char ***file);
static bool	parse_south(t_map *map, char ***file);
static bool	parse_east(t_map *map, char ***file);
static bool	parse_west(t_map *map, char ***file);

bool	parse_wall_textures(t_map *map, char ***file)
{
	bool	res;

	res = true;
	if (ft_strncmp("NO ", **file, 3) == 0)
		res = parse_north(map, file);
	else if (ft_strncmp("SO ", **file, 3) == 0)
		res = parse_south(map, file);
	else if (ft_strncmp("WE ", **file, 3) == 0)
		res = parse_west(map, file);
	else if (ft_strncmp("EA ", **file, 3) == 0)
		res = parse_east(map, file);
	return (res);
}

static bool	parse_north(t_map *map, char ***file)
{
	if (map->is_north_set)
	{
		put_error("NO is set twice\n");
		return (false);
	}
	map->file_north = ft_strndup(**file, 3, ft_strlen(**file) - 3);
	map->is_north_set = true;
	return (true);
}

static bool	parse_south(t_map *map, char ***file)
{
	if (map->is_south_set)
	{
		put_error("SO is set twice\n");
		return (false);
	}
	map->file_south = ft_strndup(**file, 3, ft_strlen(**file) - 3);
	map->is_south_set = true;
	return (true);
}

static bool	parse_east(t_map *map, char ***file)
{
	if (map->is_east_set)
	{
		put_error("EA is set twice\n");
		return (false);
	}
	map->file_east = ft_strndup(**file, 3, ft_strlen(**file) - 3);
	map->is_east_set = true;
	return (true);
}

static bool	parse_west(t_map *map, char ***file)
{
	if (map->is_west_set)
	{
		put_error("WE is set twice\n");
		return (false);
	}
	map->file_west = ft_strndup(**file, 3, ft_strlen(**file) - 3);
	map->is_west_set = true;
	return (true);
}
