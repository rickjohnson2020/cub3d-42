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

static bool		are_colours_set(t_map *map, char *floor, char *ceiling);
static t_colour	extract_colour(char *str);

bool	parse_colour(t_map *map, char ***file)
{
	bool	are_all_colours_set;
	char	*floor;
	char	*ceiling;

	floor = NULL;
	ceiling = NULL;
	are_all_colours_set = are_colours_set(map, floor, ceiling);
	skip_empty_line(file);
	if (ft_strncmp("F ", **file, 2) == 0)
		floor = ft_strndup(**file, 2, ft_strlen(**file) - 2);
	(*file)++;
	skip_empty_line(file);
	if (ft_strncmp("C ", **file, 2) == 0)
		ceiling = ft_strndup(**file, 2, ft_strlen(**file) - 2);
	(*file)++;
	if (floor != NULL && floor[0] != '\0')
		map->floor_colour = extract_colour(floor);
	if (ceiling != NULL && ceiling[0] != '\0')
		map->ceiling_colour = extract_colour(ceiling);
	are_all_colours_set = are_colours_set(map, floor, ceiling);
	free (floor);
	free (ceiling);
	return (are_all_colours_set);
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

static bool	are_colours_set(t_map *map, char *floor, char *ceiling)
{
	if (!map)
		return (false);
	if (map->is_floor_set && map->is_ceiling_set)
		return (true);
	if (!floor || !ceiling)
		return (false);
	if ((map->floor_colour.r != 0 || map->floor_colour.g != 0
			|| map->floor_colour.b != 0)
		|| (ft_strncmp(floor + count_spaces(floor), "0,0,0",
				ft_strlen(floor + count_spaces(floor))) != 0))
		map->is_floor_set = true;
	if ((map->ceiling_colour.r != 0 || map->ceiling_colour.g != 0
			|| map->ceiling_colour.b != 0)
		&& (ft_strncmp(ceiling + (count_spaces(ceiling)), "0,0,0",
				ft_strlen(ceiling + count_spaces(ceiling))) != 0))
		map->is_ceiling_set = true;
	if (map->is_floor_set && map->is_ceiling_set)
		return (true);
	return (false);
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

int	count_spaces(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] == ' ')
		i++;
	return (i);
}
