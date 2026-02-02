/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 20:48:29 by riyano            #+#    #+#             */
/*   Updated: 2026/02/02 18:12:17 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw_background(t_game *game);
static void	render_walls(t_game *game);
static void	perform_dda(t_ray *ray, t_map *map);

void	render_frame(t_game *game)
{
	draw_background(game);
	render_walls(game);
}

static void	draw_background(t_game *game)
{
	int	x;
	int	y;
	int	colour;

	y = 0;
	while (y < game->frame.height)
	{
		if (y < game->frame.height / 2)
			colour = colour_to_int(game->map->ceiling_colour);
		else
			colour = colour_to_int(game->map->floor_colour);
		x = 0;
		while (x < game->frame.width)
		{
			set_pixel(&game->frame, x, y, colour);
			x++;
		}
		y++;
	}
}

// Trace the ray through the grid using DDA algorithm until a wall is hit
// Compares distances to next vertical/horizontal boundaries to step efficiently
// Calculates accurate distance to wall by subtracting
// the step cost that exceeded it
static void	perform_dda(t_ray *ray, t_map *map)
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
	if (ray->hit_side == WALL_VERTICAL)
	{
		ray->distance_to_wall = ray->next_boundary_dist.x - ray->step_cost.x;
	}
	else if (ray->hit_side == WALL_HORIZONTAL)
	{
		ray->distance_to_wall = ray->next_boundary_dist.y - ray->step_cost.y;
	}
}

// Calculate the wall height based on the distance to the wall,
// keeping it within the range of WIN_HEIGHT
// When the distance to the wall is short, the wall should appears taller;
// when the distance is longer, it should appears shorter
static void	draw_wall_column(t_game *game, int x, t_ray *ray, t_wall_line *line)
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

static void	render_walls(t_game *game)
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
