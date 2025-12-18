/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   init_game.c                                         :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*   By: takaito <takaito@student.42london.com>       +#+  +:+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2025/11/26 21:20:14 by takaito             #+#    #+#           */
/*   Updated: 2025/11/26 21:21:26 by takaito           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_game	*init_game(t_game *game, char *filename)
{
	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
	{
		free_game (game);
		return (NULL);
	}
	if (!init_map(game, filename))
	{
		free_game (game);
		return (NULL);
	}
	return (game);
}
