/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   error.c                                             :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*   By: takaito <takaito@student.42london.com>       +#+  +:+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2025/11/26 21:20:14 by takaito             #+#    #+#           */
/*   Updated: 2025/11/26 21:21:26 by takaito           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_error(char *msg)
{
	write (STDERR_FILENO, "Error\n", 6);
	if (!msg)
		return ;
	write (STDERR_FILENO, msg, ft_strlen(msg));
}

void	put_file_error(char *msg, char *filename)
{
	if (!msg || !filename)
		return ;
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, filename, ft_strlen(filename));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
}

void	put_msg(char *msg)
{
	if (!msg)
		return ;
	write(STDERR_FILENO, msg, ft_strlen(msg));
}
