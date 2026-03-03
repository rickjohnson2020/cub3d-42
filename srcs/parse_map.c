/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   parse_map.c                                         :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*   By: takaito <takaito@student.42london.com>       +#+  +:+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2025/11/26 21:20:14 by takaito             #+#    #+#           */
/*   Updated: 2025/11/26 21:21:26 by takaito           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	is_valid_char(char c, bool *has_start_read);
static bool	is_valid_map(char **map);
static bool	is_valid_identifier_helper(char **file);

bool	parse_map(t_map *map, char ***file)
{
	int		i;
	char	**tmp;
	char	**map_head;

	i = 0;
	tmp = *file;
	while (*tmp)
	{
		i++;
		tmp++;
	}
	map->map = ft_calloc(sizeof(char *), i + 1);
	if (!map->map)
		return (false);
	map_head = map->map;
	skip_empty_line(file);
	while (**file)
	{
		*map->map = ft_strdup(**file);
		(map->map)++;
		(*file)++;
	}
	map->map = map_head;
	return (is_valid_map(map->map));
}

static bool	is_valid_map(char **map)
{
	bool	has_start_read;
	int		i;
	int		j;

	if (!map)
		return (false);
	i = 0;
	has_start_read = false;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (is_valid_char(map[i][j], &has_start_read))
				j++;
			else
				return (false);
		}
		i++;
	}
	if (has_start_read)
		return (true);
	return (false);
}

static bool	is_valid_char(char c, bool *has_start_read)
{
	if (c == '1' || c == '0' || c == ' ')
		return (true);
	if (!(*has_start_read))
	{
		if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		{
			*has_start_read = true;
			return (true);
		}
	}
	return (false);
}

bool	is_valid_identifier(char **file)
{
	if (!file || !(*file))
		return (false);
	if (ft_strncmp("NO ", *file, 3) == 0)
		return (true);
	else if (ft_strncmp("SO ", *file, 3) == 0)
		return (true);
	else if (ft_strncmp("WE ", *file, 3) == 0)
		return (true);
	else if (ft_strncmp("EA ", *file, 3) == 0)
		return (true);
	else if (ft_strncmp("F ", *file, 2) == 0)
		return (true);
	else if (ft_strncmp("C ", *file, 2) == 0)
		return (true);
	else
		return (is_valid_identifier_helper(file));
	return (true);
}

static bool	is_valid_identifier_helper(char **file)
{
	int		i;

	i = 0;
	while ((*file)[i] != '\0')
	{
		if ((*file)[i] != ' ' && (*file)[i] != '\n')
		{
			put_error("The map file contains an invalid identifier.\n");
			return (false);
		}
		i++;
	}
	return (true);
}
