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

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
	{
		free_map(&game->map);
		game->map = NULL;
	}
	if (game->mlx)
	{
		//(void)game->mlx;
		free(game->mlx);
	}
	if (game->win)
	{
		(void)game->win;
	}
	free (game);
}
