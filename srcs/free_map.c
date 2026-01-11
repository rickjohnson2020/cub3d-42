/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   free_all.c                                           :+:      :+:    :+: */
/*                                                     +:+ +:+         +:+    */
/*   By: takaito <takaito@student.42london.com>       +#+  +:+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2025/11/26 21:20:14 by takaito             #+#    #+#           */
/*   Updated: 2025/11/26 21:20:20 by takaito            ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//static void	free_colour(t_map *map);
static void	free_filepath(t_map *map);

// mlx_destroy and free
void	free_image(t_image *img)
{
	(void)img;
}

void	free_dstr(char **str)
{
	char	**tmp;

	tmp = str;
	if (!tmp)
		return ;
	while (*tmp)
	{
		free (*tmp);
		tmp++;
	}
	free (str);
}

void	free_map(t_map **map)
{
	if (!(*map))
		return ;
	free_filepath(*map);
	//free_colour(*map);
	if ((*map)->map)
		free_dstr((*map)->map);
	//if ((*map)->img)
	//	free_image((*map)->img);
	if ((*map))
		free ((*map));
	*map = NULL;
}

//static void	free_colour(t_map *map)
//{
//	if (map->floor)
//	{
//		free(map->floor);
//		map->floor = NULL;
//	}
//	if (map->floor_hex)
//	{
//		free(map->floor_hex);
//		map->floor_hex = NULL;
//	}
//	if (map->ceiling)
//	{
//		free(map->ceiling);
//		map->ceiling = NULL;
//	}
//	if (map->ceiling_hex)
//	{
//		free(map->ceiling_hex);
//		map->ceiling_hex = NULL;
//	}
//}

static void	free_filepath(t_map *map)
{
	if (map->file_north)
	{
		free(map->file_north);
		map->file_north = NULL;
	}
	if (map->file_south)
	{
		free(map->file_south);
		map->file_south = NULL;
	}
	if (map->file_west)
	{
		free(map->file_west);
		map->file_west = NULL;
	}
	if (map->file_east)
	{
		free(map->file_east);
		map->file_east = NULL;
	}
}
