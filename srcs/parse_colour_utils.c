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
