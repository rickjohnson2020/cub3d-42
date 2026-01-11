/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   file_utils.c                                         :+:      :+:    :+: */
/*                                                     +:+ +:+         +:+    */
/*   By: takaito <takaito@student.42london.com>       +#+  +:+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2025/11/26 21:20:14 by takaito             #+#    #+#           */
/*   Updated: 2025/11/26 21:20:20 by takaito            ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*store_file_helper(char *new);

int	validate_file(char *filename)
{
	int	fd;

	if (!filename)
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		put_file_error(strerror(errno), filename);
	return (fd);
}

bool	check_store_file(char **file, char *new)
{
	char	**tmp;

	tmp = file;
	if (!file)
		return (false);
	if (!new)
	{
		while (*tmp)
		{
			free(*tmp);
			tmp = NULL;
			tmp++;
		}
		free (file);
		file = NULL;
	}
	return (true);
}

char	**store_file(char **file, char *new)
{
	char	**result;
	int		i;

	i = 0;
	while (file[i])
		i++;
	result = ft_calloc(sizeof(char *), (i + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (file[i])
	{
		result[i] = ft_strdup(file[i]);
		if (!check_store_file(result, result[i]))
			return (NULL);
		i++;
	}
	result[i] = store_file_helper(new);
	if (!check_store_file(result, result[i]))
		return (NULL);
	result[i + 1] = NULL;
	free_dstr(file);
	return (result);
}

char	*ft_strndup(char *str, int start, int size)
{
	int		i;
	int		j;
	char	*result;

	if (!str || start < 0 || size < 0)
		return (NULL);
	i = start;
	j = 0;
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
	{
		put_error("malloc() failed in ft_strndup() function\n");
		return (NULL);
	}
	while (str[i] != '\0' && j < size)
	{
		result[j] = str[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}

static char	*store_file_helper(char *new)
{
	int		i;
	char	*result;

	result = NULL;
	i = 0;
	i = ft_strlen(new);
	if (new[i - 1] == '\n')
		result = ft_strndup(new, 0, ft_strlen(new) - 1);
	else
		result = ft_strndup(new, 0, ft_strlen(new));
	if (!result)
		return (NULL);
	return (result);
}
