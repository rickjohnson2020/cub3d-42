/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   init_game.c                                         :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*   By: takaito <takaito@student.42london.com>       +#+  +:+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2025/11/26 21:20:14 by takaito             #+#    #+#           */
/*   Updated: 2025/11/26 21:21:26 by takaito           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	init_map(t_game *game, char *filename)
{
	char	**config;

	config = read_config(filename);
	if (!config)
		return (false);
	game->map = parse(config);
	free_dstr(config);
	if (!game->map)
		return (false);
	return (true);
}

char	**read_config(char *filename)
{
	int		fd;
	char	*line;
	char	**file;

	fd = validate_file(filename);
	if (fd < 0)
		return (false);
	line = get_next_line(fd);
	file = ft_calloc(sizeof(char *), 2);
	if (!line || !file)
		return (false);
	while (line)
	{
		if (*line == '\n')
			;
		else if (!*file)
			*file = ft_strndup(line, 0, ft_strlen(line) - 1);
		else
			file = store_file(file, line);
		free (line);
		if (!check_store_file(file, *file))
			return (NULL);
		line = get_next_line(fd);
	}
	return (file);
}

t_map	*parse(char **file)
{
	t_map	*map;

	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
	{
		put_error("malloc() failed in parse() function\n");
		return (NULL);
	}
	if (map && !parse_wall_textures(map, &file))
	{
		put_error("failed to parse wall texture file path\n");
		free_map (&map);
	}
	if (map && !parse_colour(map, &file))
	{
		put_error("failed to parse floor or ceiling colour\n");
		free_map (&map);
	}
	skip_empty_line(&file);
	if (map && !parse_map(map, &file))
	{
		put_error("failed to parse map\n");
		free_map (&map);
	}
	return (map);
}

// This function moves pointer until string contains valid values. 
void	skip_empty_line(char ***file)
{
	char	*line;

	if (!file || !*file)
		return ;
	while (**file)
	{
		line = **file;
		while (*line && is_space(*line))
			line++;
		if (*line == '\0')
			(*file)++;
		else
			break ;
	}
}

bool	is_space(char c)
{
	if (c == 9 || c == 11 || c == 32)
		return (true);
	return (false);
}
