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
static void		init_extract_colour(int *i, t_colour *colour,
					t_colour *err_colour);
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
			return (put_error("Floor colour is set twice\n"), false);
		floor = ft_strndup(**file, 2, ft_strlen(**file) - 2);
	}
	(*file)++;
	if (floor != NULL && floor[0] != '\0')
	{
		if (!is_valid_colour_str(floor))
		{
			free (floor);
			return (put_error("Invalid colour format\n"), false);
		}
		map->floor_colour = extract_colour(floor);
		map->is_floor_set = true;
	}
	if (floor)
		free (floor);
	return (map->is_floor_set);
}

static bool	parse_ceiling(t_map *map, char ***file)
{
	char	*ceiling;

	ceiling = NULL;
	if (ft_strncmp("C ", **file, 2) == 0)
	{
		if (map->is_ceiling_set)
			return (put_error("ceiling colour is set twice\n"), false);
		ceiling = ft_strndup(**file, 2, ft_strlen(**file) - 2);
	}
	(*file)++;
	if (ceiling != NULL && ceiling[0] != '\0')
	{
		if (!is_valid_colour_str(ceiling))
		{
			free (ceiling);
			return (put_error("Invalid colour format\n"), false);
		}
		map->ceiling_colour = extract_colour(ceiling);
		map->is_ceiling_set = true;
	}
	if (ceiling)
		free (ceiling);
	return (map->is_ceiling_set);
}

static t_colour	extract_colour(char *str)
{
	int			i;
	t_colour	colour;
	t_colour	err_colour;

	init_extract_colour(&i, &colour, &err_colour);
	if (!str)
		return (err_colour);
	i = count_spaces(str);
	while (ft_isdigit(str[i]))
		colour.r = colour.r * 10 + (str[i++] - '0');
	if (str[i++] != ',')
		return (err_colour);
	while (ft_isdigit(str[i]))
		colour.g = colour.g * 10 + (str[i++] - '0');
	if (str[i++] != ',')
		return (err_colour);
	while (ft_isdigit(str[i]))
		colour.b = colour.b * 10 + (str[i++] - '0');
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\n')
			return (err_colour);
		i++;
	}
	return (colour);
}

static void	init_extract_colour(int *i, t_colour *colour, t_colour *err_colour)
{
	*i = 0;
	ft_memset(colour, 0, sizeof(t_colour));
	ft_memset(err_colour, -1, sizeof(t_colour));
}
