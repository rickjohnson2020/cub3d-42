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
	bool	are_all_set;
	char	*floor;
	char	*ceiling;

	are_all_set = false;
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
	are_all_set = are_colours_set(map, floor, ceiling);
	free (floor);
	free (ceiling);
	return (are_all_set);
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
	if (!map || !floor || !ceiling)
		return (false);
	if ((map->floor_colour.r == 0 && map->floor_colour.g
			&& map->floor_colour.b == 0)
		&& (ft_strncmp(floor, "0,0,0", ft_strlen(floor)) != 0))
		return (false);
	if (map->floor_colour.r > 255 || map->floor_colour.g > 255
		|| map->floor_colour.b > 255 || map->floor_colour.r < 0
		|| map->floor_colour.g < 0 || map->floor_colour.b < 0)
		return (false);
	if ((map->ceiling_colour.r == 0 && map->ceiling_colour.g
			&& map->ceiling_colour.b == 0)
		&& (ft_strncmp(ceiling, "0,0,0", ft_strlen(ceiling)) != 0))
		return (false);
	if (map->ceiling_colour.r > 255 || map->ceiling_colour.g > 255
		|| map->ceiling_colour.b > 255 || map->ceiling_colour.r < 0
		|| map->ceiling_colour.g < 0 || map->ceiling_colour.b < 0)
		return (false);
	return (true);
}
