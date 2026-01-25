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

static int	count_lines(char **dstr);
static int	get_longest_str_len(char **dstr);
//static bool validate_vertical_lines(char **map);
//static bool	validate_horizontal_lines(char **map);
char	**create_vmap(char **map, int num_lines, int max_len);
char	*pad_spaces(char *str, int max_len);
void floodfill(char **dstr, int y, int x);
bool	is_surrounded(char **vmap, int y, int x);
void	fill_rest_spaces(char **vmap);
bool	validate_cell(char **vmap);

bool	validate_map(t_map *map)
{
	char	**vmap;
	int		num_lines;
	int		max_len;

	if (!map || !map->map)
		return (false);
	int i = 0;
	printf("original map\n");
	while (map->map[i])
	{
		printf("map[%3d] :%s\n", i, map->map[i]);
		i++;
	}
	num_lines = count_lines(map->map);
	max_len = get_longest_str_len(map->map);
	vmap = create_vmap(map->map, num_lines, max_len);
	if (!validate_cell(vmap))
	{
		free_dstr(vmap);
		return (false);
	}
	free_dstr(vmap);
	floodfill(map->map, 0, 0);
	fill_rest_spaces(map->map);
	printf("edited map\n");
	i = 0;
	while (map->map[i])
	{
		printf("map[%3d] :%s\n", i, map->map[i]);
		i++;
	}
	// i = 0;
	// while (vmap[i])
	// {
	// 	printf("vmap[%3d]:%s\n", i, vmap[i]);
	// 	i++;
	// }
	// floodfill from start position
	// then check all map
	// if there is still 0, floodfill from there
	return (true);
}

void	fill_rest_spaces(char **vmap)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (vmap[y])
	{
		x = 0;
		while(vmap[y][x])
		{
			if (vmap[y][x] == ' ')
				vmap[y][x] = '1';
			x++;
		}
		y++;
	}
}

void	floodfill(char **vmap, int y, int x)
{
	int	max_len;
	int	num_lines;
	
	max_len = ft_strlen(vmap[0]);
	num_lines = count_lines(vmap);	
	if (x < 0 || x  >= max_len || y  < 0  || y >= num_lines)
		return ;
	if (vmap[y][x] != ' ')
		return ;
	vmap[y][x] = '1';
	floodfill(vmap, y - 1, x);
	floodfill(vmap, y + 1, x);
	floodfill(vmap, y, x - 1);
	floodfill(vmap, y, x + 1);
}
bool	is_starting_position(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	return (false);
}

bool	validate_cell(char **vmap)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < count_lines(vmap))
	{
		x = 0;
		while(x < get_longest_str_len(vmap))
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

bool	is_surrounded(char **vmap, int y, int x)
{
	if (y == 0 || x == 0 || y == count_lines(vmap) - 1 || x == get_longest_str_len(vmap) - 1)
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

char	**create_vmap(char **map, int num_lines, int max_len)
{
	char	**vmap;
	int		i;

	i = 0;
	vmap = ft_calloc(num_lines + 3, sizeof(char *));
	if (!vmap)
		return (NULL);
	vmap[i++] = pad_spaces(NULL, max_len);
	while (i < num_lines + 1)
	{
		vmap[i] = pad_spaces(map[i - 1], max_len);
		if (!vmap[i])
		{
			free_dstr(vmap);
			return (NULL);
		}
		i++;
	}
	vmap[i++] = pad_spaces(NULL, max_len);
	vmap[i] = NULL;
	return (vmap);
}

char	*pad_spaces(char *str, int max_len)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_calloc(max_len + 3, sizeof(char));
	if (!new)
		return (NULL);
	if (!str)
	{
		while (i < max_len + 2)
			new[i++] = ' ';
	}
	else
	{
		new[i++] = ' ';
		while (*str)
			new[i++] = *(str++);
		while (i < max_len + 2)
			new[i++] = ' ';
	}
	new[i] = '\0';
	return (new);
}

static int	count_lines(char **dstr)
{
	int	i;

	i = 0;
	if (!dstr)
		return (i);
	while (dstr[i])
		i++;
	return (i);
}

static int	get_longest_str_len(char **dstr)
{
	int	max;
	int	tmp;
	int	i;
	
	max = 0;
	i = 0;
	tmp = 0;
	if (!dstr)
		return (max);
	while (dstr[i])
	{
		tmp = ft_strlen(dstr[i]);
		if (tmp > max)
			max = tmp;
		i++;
	}
	return (max);
}
/*
static bool validate_vertical_lines(char **map)
{

}

static bool	validate_horizontal_lines(char **map)
{

}
*/