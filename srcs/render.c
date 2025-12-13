#include "../includes/cub3d.h"

void	init_ray(t_ray *ray, t_game *game, int x);
int		colour_to_int(t_colour c);
void	set_pixel(t_image *img, int x, int y, int colour);
void	draw_background(t_game *game);
void	render_walls(t_game *game);
void	init_ray(t_ray *ray, t_game *game, int x);
void	perform_dda(t_ray *ray, t_map *map);
void	draw_wall_column(t_game *game, int x, t_ray *ray);

void	render_frame(t_game *game)
{
	// TODO: initialise buffer
	//clear_frame(&game->frame);

	// TODO: draw ceiling and floor
	draw_background(game);

	// TODO: draw wall(raycasting)
	render_walls(game);
}

int	colour_to_int(t_colour c)
{
	return ((c.r << 16) | (c.g << 8) | c.b);
}

void	set_pixel(t_image *img, int x, int y, int colour)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= img->size.x || y >= img->size.y)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

void	draw_background(t_game *game)
{
	int	x;
	int	y;
	int	colour;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		if (y < WIN_HEIGHT / 2)
			//colour = colour_to_int(game->map->ceiling_colour);
			colour = 0x87CEEB;
		else
			//colour = colour_to_int(game->map->floor_colour);
			colour = 0x444444;
		x = 0;
		while (x < WIN_WIDTH)
		{
			set_pixel(&game->frame, x, y, colour);
			x++;
		}
		y++;
	}
}

void	render_walls(t_game *game)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray(&ray, game, x);
		perform_dda(&ray, game->map);
		draw_wall_column(game, x, &ray);
		x++;
	}
}

void	init_ray(t_ray *ray, t_game *game, int x)
{
	ray->camera_x = (2 * x / (double)WIN_WIDTH) - 1.0;
	ray->dir.x = game->player.dir.x + game->player.plane.x * ray->camera_x;
	ray->dir.y = game->player.dir.y + game->player.plane.y * ray->camera_x;
	ray->current_cell.x = (int)game->player.pos.x;
	ray->current_cell.y = (int)game->player.pos.y;

	if (ray->dir.x == 0)
		ray->step_cost.x = 1e30;
	else
		ray->step_cost.x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->step_cost.y = 1e30;
	else
		ray->step_cost.y = fabs(1 / ray->dir.y);

	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->next_boundary_dist.x = (game->player.pos.x - ray->current_cell.x) * ray->step_cost.x;
	}
	else
	{
		ray->step.x = 1;
		ray->next_boundary_dist.x = (ray->current_cell.x + 1.0 - game->player.pos.x) * ray->step_cost.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->next_boundary_dist.y = (game->player.pos.y - ray->current_cell.y) * ray->step_cost.y;
	}
	else
	{
		ray->step.y = 1;
		ray->next_boundary_dist.y = (ray->current_cell.y + 1.0 - game->player.pos.y) * ray->step_cost.y;
	}
	ray->hit = 0;
}

void	perform_dda(t_ray *ray, t_map *map)
{
	while (!ray->hit)
	{
		if (ray->next_boundary_dist.x < ray->next_boundary_dist.y)
		{
			ray->next_boundary_dist.x += ray->step_cost.x;
			ray->current_cell.x += ray->step.x;
			ray->hit_side = WALL_VERTICAL;
		}
		else
		{
			ray->next_boundary_dist.y += ray->step_cost.y;
			ray->current_cell.y += ray->step.y;
			ray->hit_side = WALL_HORIZONTAL;
		}
		if (map->map[ray->current_cell.y][ray->current_cell.x] == '1')
			ray->hit = 1;
	}
	// calculate accurate distance to the wall
	// substract the step_cost that went beyond the required steps
	if (ray->hit_side == WALL_VERTICAL)
	{
		ray->distance_to_wall = ray->next_boundary_dist.x - ray->step_cost.x;
	}
	else if (ray->hit_side == WALL_HORIZONTAL)
	{
		ray->distance_to_wall = ray->next_boundary_dist.y - ray->step_cost.y;
	}
}

// calculate the wall height based on the distance to the wall, keeping it within the range of WIN_HEIGHT
// when the distance to the wall is short, the wall should appears taller; when the distance is longer, it should appears shorter.
void	draw_wall_column(t_game *game, int x, t_ray *ray)
{
	int	colour;
	int	y;
	int	line_height;
	int	start;
	int	end;

	line_height = (int)(WIN_HEIGHT / ray->distance_to_wall);
	start = (WIN_HEIGHT / 2) - (line_height / 2);
	if (start < 0)
		start = 0;
	end = (WIN_HEIGHT / 2) + (line_height / 2);
	if (end >= WIN_HEIGHT)
		end = WIN_HEIGHT - 1;
	// put colour
	if (ray->hit_side == WALL_VERTICAL)
		colour = RED;
	else
		colour = DARK_RED;
	y = start;
	while (y <= end)
	{
		set_pixel(&game->frame, x, y, colour);
		y++;
	}
}
