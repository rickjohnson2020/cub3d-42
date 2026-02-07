/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   parse_colour.c                                      :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*   By: takaito <takaito@student.42london.com>       +#+  +:+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2025/11/26 21:20:14 by takaito             #+#    #+#           */
/*   Updated: 2025/11/26 21:21:26 by takaito           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_colour	extract_colour(char *str);
static bool		parse_ceiling(t_map *map, char ***file);
static bool		parse_floor(t_map *map, char ***file);

bool	parse_colour(t_map *map, char ***file)
{
	bool	res;

	res = true;
	if (ft_strncmp("F ", **file, 2) == 0)
		res = parse_floor(map, file);
	else if (ft_strncmp("C ", **file, 2) == 0)
		res = parse_ceiling(map, file);
	return (res);
}

static bool	parse_floor(t_map *map, char ***file)
{
	char	*floor;

	floor = NULL;
	if (ft_strncmp("F ", **file, 2) == 0)
	{
		if (map->is_floor_set)
		{
			put_error("Floor colour is set twice\n");
			return (false);
		}
		floor = ft_strndup(**file, 2, ft_strlen(**file) - 2);
	}
	(*file)++;
	if (floor != NULL && floor[0] != '\0')
	{
		map->floor_colour = extract_colour(floor);
		map->is_floor_set = true;
		free (floor);
	}
	return (map->is_floor_set);
}

static bool	parse_ceiling(t_map *map, char ***file)
{
	char	*ceiling;

	ceiling = NULL;
	if (ft_strncmp("C ", **file, 2) == 0)
	{
		if (map->is_ceiling_set)
		{
			put_error("ceiling colour is set twice\n");
			return (false);
		}
		ceiling = ft_strndup(**file, 2, ft_strlen(**file) - 2);
	}
	(*file)++;
	if (ceiling != NULL && ceiling[0] != '\0')
	{
		map->ceiling_colour = extract_colour(ceiling);
		map->is_ceiling_set = true;
		free (ceiling);
	}
	return (map->is_ceiling_set);
}

static t_colour	extract_colour(char *str)
{
	int			i;
	t_colour	colour;

	colour.r = 0;
	colour.g = 0;
	colour.b = 0;
	i = 0;
	if (!str)
		return (colour);
	i = count_spaces(str);
	while (str[i] != '\0')
	{
		while (ft_isalnum(str[i]))
			colour.r = colour.r * 10 + (str[i++] - '0');
		i++;
		while (ft_isalnum(str[i]))
			colour.g = colour.g * 10 + (str[i++] - '0');
		i++;
		while (ft_isalnum(str[i]))
			colour.b = colour.b * 10 + (str[i++] - '0');
	}
	return (colour);
}

bool	is_valid_colour(t_map *map)
{
	if (!map)
		return (false);
	if (map->floor_colour.r > 255 || map->floor_colour.g > 255
		|| map->floor_colour.b > 255 || map->floor_colour.r < 0
		|| map->floor_colour.g < 0 || map->floor_colour.b < 0)
		return (false);
	if (map->ceiling_colour.r > 255 || map->ceiling_colour.g > 255
		|| map->ceiling_colour.b > 255 || map->ceiling_colour.r < 0
		|| map->ceiling_colour.g < 0 || map->ceiling_colour.b < 0)
		return (false);
	return (true);
}
