/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:29:51 by riyano            #+#    #+#             */
/*   Updated: 2026/02/02 18:15:49 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	load_texture(t_game *game, t_image *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->mlx,
			path, &tex->width, &tex->height);
	if (!tex->img)
		return (put_file_error("mlx_xpm_file_to_image() error", path), false);
	tex->addr = mlx_get_data_addr(tex->img,
			&tex->bits_per_pixel, &tex->line_len, &tex->endian);
	if (!tex->addr)
		return (put_file_error("mlx_get_data_addr() error", path), false);
	return (true);
}

bool	load_textures(t_game *game)
{
	if (!load_texture(game, &game->map->textures.west, game->map->file_west))
		return (false);
	if (!load_texture(game, &game->map->textures.east, game->map->file_east))
		return (false);
	if (!load_texture(game, &game->map->textures.south, game->map->file_south))
		return (false);
	if (!load_texture(game, &game->map->textures.north, game->map->file_north))
		return (false);
	return (true);
}

t_image	*select_wall_texture(t_game *game, t_ray *ray)
{
	if (ray->hit_side == WALL_VERTICAL)
	{
		if (ray->dir.x < 0)
			return (&game->map->textures.west);
		return (&game->map->textures.east);
	}
	else
	{
		if (ray->dir.y < 0)
			return (&game->map->textures.north);
		return (&game->map->textures.south);
	}
}

// Determine the horizontal position on the texture
// based on where it hit the wall (fractional part of x/y coordinates)
static double	calculate_wall_hit_offset(t_ray *ray, t_player *p)
{
	double	hit_x_or_y;
	double	hit_offset;

	if (ray->hit_side == WALL_VERTICAL)
		hit_x_or_y = p->pos.y + (ray->dir.y * ray->distance_to_wall);
	else
		hit_x_or_y = p->pos.x + (ray->dir.x * ray->distance_to_wall);
	hit_offset = hit_x_or_y - floor(hit_x_or_y);
	return (hit_offset);
}

// Calculate the hit offset and
// flip left to right depending on which side of the wall
// player is viewing from (the direction of the ray)
int	calculate_tex_x(t_image *tex, t_ray *ray, t_player *p)
{
	int		tex_x;
	double	hit_offset;

	hit_offset = calculate_wall_hit_offset(ray, p);
	if ((ray->hit_side == WALL_VERTICAL && ray->dir.x < 0)
		|| (ray->hit_side == WALL_HORIZONTAL && ray->dir.y >= 0))
		tex_x = (1 - hit_offset) * tex->width;
	else
		tex_x = hit_offset * tex->width;
	if (tex_x >= tex->width)
		tex_x = tex->width - 1;
	return (tex_x);
}
