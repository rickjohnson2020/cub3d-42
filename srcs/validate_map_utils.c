/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   validate_map.c                                      :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*   By: takaito <takaito@student.42london.com>       +#+  +:+       +#+      */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/01/19 22:10:14 by takaito             #+#    #+#           */
/*   Updated: 2026/01/19 22:10:14 by takaito           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

// map は empty line を含まない

#include "../includes/cub3d.h"

static char	*pad_spaces(char *str, int max_len);

char	**create_vmap(char **map, int num_lines, int max_len)
{
	char	**vmap;
	int		i;

	i = 0;
	vmap = ft_calloc(num_lines + 3, sizeof(char *));
	if (!vmap)
		return (NULL);
	vmap[i++] = pad_spaces(NULL, max_len);
	while (i < num_lines + 1)
	{
		vmap[i] = pad_spaces(map[i - 1], max_len);
		if (!vmap[i])
		{
			free_dstr(vmap);
			return (NULL);
		}
		i++;
	}
	vmap[i++] = pad_spaces(NULL, max_len);
	vmap[i] = NULL;
	return (vmap);
}

char	*pad_spaces(char *str, int max_len)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_calloc(max_len + 3, sizeof(char));
	if (!new)
		return (NULL);
	if (!str)
	{
		while (i < max_len + 2)
			new[i++] = ' ';
	}
	else
	{
		new[i++] = ' ';
		while (*str)
			new[i++] = *(str++);
		while (i < max_len + 2)
			new[i++] = ' ';
	}
	new[i] = '\0';
	return (new);
}

int	count_lines(char **dstr)
{
	int	i;

	i = 0;
	if (!dstr)
		return (i);
	while (dstr[i])
		i++;
	return (i);
}

int	get_longest_str_len(char **dstr)
{
	int	max;
	int	tmp;
	int	i;

	max = 0;
	i = 0;
	tmp = 0;
	if (!dstr)
		return (max);
	while (dstr[i])
	{
		tmp = ft_strlen(dstr[i]);
		if (tmp > max)
			max = tmp;
		i++;
	}
	return (max);
}
