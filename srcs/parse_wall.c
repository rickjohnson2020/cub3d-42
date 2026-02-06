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

static bool	are_textures_set(t_map *map);
static int	set_texture_filename(char **filename);

bool	parse_wall_textures(t_map *map, char ***file)
{
	bool	are_all_textures_set;

	are_all_textures_set = are_textures_set(map);
	if (are_all_textures_set)
		return (are_all_textures_set);
	skip_empty_line(file);
	if (!map->is_north_set && ft_strncmp("NO ", **file, 3) == 0)
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
	are_all_textures_set = are_textures_set(map);
	return (are_all_textures_set);
}

bool	validate_texture_path(t_map *map)
{
	int	fd;

	fd = -1;
	if (!map || !map->file_north || !map->file_south
		|| !map->file_east || !map->file_west)
		return (false);
	fd = set_texture_filename(&map->file_north);
	if (fd < 0)
		return (false);
	close (fd);
	fd = set_texture_filename(&map->file_east);
	if (fd < 0)
		return (false);
	close (fd);
	fd = set_texture_filename(&map->file_west);
	if (fd < 0)
		return (false);
	close (fd);
	fd = set_texture_filename(&map->file_south);
	if (fd < 0)
		return (false);
	close (fd);
	return (true);
}

static int	set_texture_filename(char **filename)
{
	int		fd;
	int		i;
	char	*tmp;
	char	*new;

	i = 0;
	while ((*filename)[i])
	{
		tmp = *filename + i++;
		fd = open(tmp, O_RDONLY);
		if (fd >= 0)
		{
			new = ft_strdup(tmp);
			if (!new)
			{
				close (fd);
				return (-1);
			}
			free(*filename);
			*filename = new;
			return (fd);
		}
	}
	return (-1);
}

static bool	are_textures_set(t_map *map)
{
	if (map->file_north != NULL && map->file_north[0] != '\0')
		map->is_north_set = true;
	if (map->file_south != NULL && map->file_south[0] != '\0')
		map->is_south_set = true;
	if (map->file_west != NULL && map->file_west[0] != '\0')
		map->is_west_set = true;
	if (map->file_east != NULL && map->file_east[0] != '\0')
		map->is_east_set = true;
	if (map->is_north_set && map->is_south_set
		&& map->is_east_set && map->is_west_set)
		return (true);
	return (false);
}
