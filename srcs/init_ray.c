/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:27:43 by riyano            #+#    #+#             */
/*   Updated: 2026/02/02 18:34:37 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_ray_1(t_ray *ray, t_game *game, int x)
{
	ray->camera_x = (2 * x / (double)game->frame.width) - 1.0;
	ray->dir.x = game->player.dir.x + game->player.plane.x * ray->camera_x;
	ray->dir.y = game->player.dir.y + game->player.plane.y * ray->camera_x;
	ray->current_cell.x = (int)game->player.pos.x;
	ray->current_cell.y = (int)game->player.pos.y;
	if (ray->dir.x == 0)
		ray->step_cost.x = INFINITY;
	else
		ray->step_cost.x = 1 / fabs(ray->dir.x);
	if (ray->dir.y == 0)
		ray->step_cost.y = INFINITY;
	else
		ray->step_cost.y = 1 / fabs(ray->dir.y);
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
