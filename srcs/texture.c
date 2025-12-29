#include "../includes/cub3d.h"
#include <stdio.h>

void	load_texture(t_game *game, t_image *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->mlx, path, &tex->size.x, &tex->size.y);
	if (!tex->img)
	{
		printf("mlx_xpm_file_to_image error: %s\n", path);
		return ;
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel, &tex->line_len, &tex->endian);
}

void	load_textures(t_game *game)
{
	load_texture(game, &game->map->textures.west, "textures/christmas_W.xpm");
	load_texture(game, &game->map->textures.east, "textures/christmas_E.xpm");
	load_texture(game, &game->map->textures.south, "textures/christmas_S.xpm");
	load_texture(game, &game->map->textures.north, "textures/christmas_N.xpm");
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

// Determine the horizontal position on the texture
// based on where it hit the wall (fractional part of x/y coordinates)
int	calculate_tex_x(t_image *tex, t_ray *ray, t_player *p)
{
	int		tex_x;
	double	hit_offset;

	hit_offset = calculate_wall_hit_offset(ray, p);
	// flip left to right depending on which side of the wall player is viewing from (the direction of the ray)
	if ((ray->hit_side == WALL_VERTICAL && ray->dir.x < 0) || (ray->hit_side == WALL_HORIZONTAL && ray->dir.y >= 0))
		tex_x = (1 - hit_offset) * tex->size.x;
	else
		tex_x = hit_offset * tex->size.x;
	if (tex_x >= tex->size.x)
		tex_x = tex->size.x - 1;
	return (tex_x);
}
