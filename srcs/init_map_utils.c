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

static char	**read_config_helper(char *line, char **file, int fd);

char	**read_config(char *filename)
{
	int		fd;
	char	*line;
	char	**file;

	fd = validate_file(filename);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	file = ft_calloc(sizeof(char *), 2);
	if (!file)
	{
		free(line);
		return (NULL);
	}
	file = read_config_helper(line, file, fd);
	return (file);
}

static char	**read_config_helper(char *line, char **file, int fd)
{
	while (line)
	{
		if (!*file)
			*file = ft_strndup(line, 0, ft_strlen(line) - 1);
		else
			file = store_file(file, line);
		free (line);
		if (!check_store_file(file, *file))
			return (NULL);
		line = get_next_line(fd);
	}
	close (fd);
	return (file);
}

// This function moves pointer until string contains valid values. 
void	skip_empty_line(char ***file)
{
	char	*line;

	if (!file || !*file)
		return ;
	while (**file)
	{
		line = **file;
		while (*line && is_space(*line))
			line++;
		if (*line == '\0')
			(*file)++;
		else
			break ;
	}
}

bool	is_space(char c)
{
	if (c == 9 || c == 11 || c == 32)
		return (true);
	return (false);
}

int	count_spaces(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] == ' ')
		i++;
	return (i);
}
