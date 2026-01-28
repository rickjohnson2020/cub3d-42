/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   validate_map.c                                      :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*   By: takaito <takaito@student.42london.com>       +#+  +:+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/01/19 22:10:14 by takaito             #+#    #+#           */
/*   Updated: 2026/01/19 22:10:14 by takaito           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	is_starting_position(char c);
static bool	is_surrounded(char **vmap, int y, int x);
static bool	validate_cell(char **vmap);

bool	validate_map(t_map *map)
{
	char	**vmap;
	int		num_lines;
	int		max_len;

	if (!map || !map->map)
		return (false);
	num_lines = count_lines(map->map);
	max_len = get_longest_str_len(map->map);
	vmap = create_vmap(map->map, num_lines, max_len);
	if (!validate_cell(vmap))
	{
		free_dstr(vmap);
		put_error("map is not surrounded by walls\n");
		return (false);
	}
	free_dstr(vmap);
	return (true);
}

static bool	is_starting_position(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	return (false);
}

static bool	validate_cell(char **vmap)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < count_lines(vmap))
	{
		x = 0;
		while (x < get_longest_str_len(vmap))
		{
			if (is_surrounded(vmap, y, x))
				x++;
			else
				return (false);
		}
		y++;
	}
	return (true);
}

static bool	is_surrounded(char **vmap, int y, int x)
{
	if (y == 0 || x == 0 || y == count_lines(vmap) - 1
		|| x == get_longest_str_len(vmap) - 1)
		return (true);
	if (vmap[y][x] == '0' || is_starting_position(vmap[y][x]))
	{
		if (vmap[y - 1][x - 1] == ' ')
			return (false);
		if (vmap[y - 1][x] == ' ')
			return (false);
		if (vmap[y - 1][x + 1] == ' ')
			return (false);
		if (vmap[y][x - 1] == ' ')
			return (false);
		if (vmap[y][x + 1] == ' ')
			return (false);
		if (vmap[y + 1][x - 1] == ' ')
			return (false);
		if (vmap[y + 1][x] == ' ')
			return (false);
		if (vmap[y + 1][x + 1] == ' ')
			return (false);
	}
	return (true);
}
