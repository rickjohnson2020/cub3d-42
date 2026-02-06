/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:36:03 by riyano            #+#    #+#             */
/*   Updated: 2026/02/02 18:39:22 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Calculate wall drawing parameters: height, screen position, texture scaling
// Determines where the wall appears on screen and
// how texture pixels map to screen pixels
// If wall extends beyond screen bounds, it is clipped and
// texture position is adjusted
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
