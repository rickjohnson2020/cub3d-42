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

#include "../include/cub3d.h"

static bool	are_textures_set(t_map *map);

bool	parse_wall_textures(t_map *map, char ***file)
{
	bool	are_all_set;

	are_all_set = false;
	skip_empty_line(file);
	if (ft_strncmp("NO ", **file, 3) == 0)
		map->file_north = ft_strndup(**file, 3, ft_strlen(**file) - 3);
	(*file)++;
	skip_empty_line(file);
	if (ft_strncmp("SO ", **file, 3) == 0)
		map->file_south = ft_strndup(**file, 3, ft_strlen(**file) - 3);
	(*file)++;
	skip_empty_line(file);
	if (ft_strncmp("WE ", **file, 3) == 0)
		map->file_west = ft_strndup(**file, 3, ft_strlen(**file) - 3);
	(*file)++;
	skip_empty_line(file);
	if (ft_strncmp("EA ", **file, 3) == 0)
		map->file_east = ft_strndup(**file, 3, ft_strlen(**file) - 3);
	(*file)++;
	are_all_set = are_textures_set(map);
	return (are_all_set);
}

static bool	are_textures_set(t_map *map)
{
	if (map->file_north == NULL || map->file_north[0] == '\0')
		return (false);
	if (map->file_south == NULL || map->file_south[0] == '\0')
		return (false);
	if (map->file_west == NULL || map->file_west[0] == '\0')
		return (false);
	if (map->file_east == NULL || map->file_east[0] == '\0')
		return (false);
	return (true);
}
