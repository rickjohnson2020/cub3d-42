/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   validate_argv.c                                     :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*   By: takaito <takaito@student.42london.com>       +#+  +:+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2025/11/26 21:20:14 by takaito             #+#    #+#           */
/*   Updated: 2025/11/26 21:21:33 by takaito           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	is_valid_filename(char *filename)
{
	int		i;
	int		j;
	char	*ext;

	ext = ".cub";
	j = ft_strlen(ext);
	i = ft_strlen(filename);
	if (i < 5)
		return (false);
	while (j >= 0)
	{
		if (filename[i] != ext[j])
			return (false);
		j--;
		i--;
	}
	return (true);
}

bool	is_valid_argv(int argc, char **argv)
{
	if (argc != 2)
	{
		put_error("Please input configuration file name as a parameter.\n");
		return (false);
	}
	if (!is_valid_filename(argv[1]))
	{
		put_error("Please input configuration file name as *.cub.\n");
		return (false);
	}
	return (true);
}
