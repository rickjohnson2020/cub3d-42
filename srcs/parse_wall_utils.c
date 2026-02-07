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

static int	set_texture_filename(char **filename);

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
