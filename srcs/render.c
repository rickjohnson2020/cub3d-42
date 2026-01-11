/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 20:48:29 by riyano            #+#    #+#             */
/*   Updated: 2026/01/11 21:40:13 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_ray_1(t_ray *ray, t_game *game, int x);
void	init_ray_2(t_ray *ray, t_game *game);
int		colour_to_int(t_colour c);
void	set_pixel(t_image *img, int x, int y, int colour);
void	draw_background(t_game *game);
void	render_walls(t_game *game);
void	init_ray(t_ray *ray, t_game *game, int x);
void	perform_dda(t_ray *ray, t_map *map);
void	draw_wall_column(t_game *game, int x, t_ray *ray, t_wall_line *line);

void	render_frame(t_game *game)
{
	draw_background(game);
	render_walls(game);
}

int	colour_to_int(t_colour c)
{
	return ((c.r << 16) | (c.g << 8) | c.b);
}

void	set_pixel(t_image *img, int x, int y, int colour)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

unsigned int	get_pixel(t_image *img, int x, int y)
{
	char	*addr;

	addr = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)addr);
}

void	draw_background(t_game *game)
{
	int	x;
	int	y;
	int	colour;

	y = 0;
	while (y < game->frame.height)
	{
		if (y < game->frame.height / 2)
			//colour = colour_to_int(game->map->ceiling_colour);
			colour = 0x87CEEB;
		else
			//colour = colour_to_int(game->map->floor_colour);
			colour = 0x444444;
		x = 0;
		while (x < game->frame.width)
		{
			set_pixel(&game->frame, x, y, colour);
			x++;
		}
		y++;
	}
}

void	render_walls(t_game *game)
{
	int			x;
	t_ray		ray;
	t_wall_line	line;

	x = 0;
	while (x < game->frame.width)
	{
		init_ray_1(&ray, game, x);
		init_ray_2(&ray, game);
		perform_dda(&ray, game->map);
		draw_wall_column(game, x, &ray, &line);
		x++;
	}
}

void	init_ray_1(t_ray *ray, t_game *game, int x)
{
	ray->camera_x = (2 * x / (double)game->frame.width) - 1.0;
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
	ray->hit = 0;
}

void	init_ray_2(t_ray *ray, t_game *game)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->next_boundary_dist.x = (game->player.pos.x
				- ray->current_cell.x) * ray->step_cost.x;
	}
	else
	{
		ray->step.x = 1;
		ray->next_boundary_dist.x = (ray->current_cell.x
				+ 1.0 - game->player.pos.x) * ray->step_cost.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->next_boundary_dist.y = (game->player.pos.y
				- ray->current_cell.y) * ray->step_cost.y;
	}
	else
	{
		ray->step.y = 1;
		ray->next_boundary_dist.y = (ray->current_cell.y
				+ 1.0 - game->player.pos.y) * ray->step_cost.y;
	}
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

void	init_wall(t_image *frame, t_image *tex, t_wall_line *wall, t_ray *ray)
{
	int	wall_height;
	int	wall_start;
	int	wall_end;

	wall_height = (int)(frame->height / ray->distance_to_wall);
	wall_start = (frame->height / 2) - (wall_height / 2);
	wall_end = (frame->height / 2) + (wall_height / 2);
	wall->draw_start = wall_start;
	wall->draw_end = wall_end;
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	if (wall->draw_end >= frame->height)
		wall->draw_end = frame->height - 1;
	wall->tex_step = (double)tex->height / wall_height;
	wall->tex_pos = (wall->draw_start - wall_start) * wall->tex_step;
}

// calculate the wall height based on the distance to the wall, keeping it within the range of WIN_HEIGHT
// when the distance to the wall is short, the wall should appears taller; when the distance is longer, it should appears shorter.
void	draw_wall_column(t_game *game, int x, t_ray *ray, t_wall_line *line)
{
	int		colour;
	int		tex_x;
	int		y;
	int		tex_y;
	t_image	*tex;

	tex = select_wall_texture(game, ray);
	tex_x = calculate_tex_x(tex, ray, &game->player);
	init_wall(&game->frame, tex, line, ray);
	y = line->draw_start;
	while (y <= line->draw_end)
	{
		tex_y = (int)line->tex_pos % tex->height;
		line->tex_pos += line->tex_step;
		colour = get_pixel(tex, tex_x, tex_y);
		set_pixel(&game->frame, x, y, colour);
		y++;
	}
}
