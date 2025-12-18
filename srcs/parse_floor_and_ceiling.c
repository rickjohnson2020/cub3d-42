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

#include "../include/cub3d.h"

static bool	are_colours_set(t_map *map);
static char	*convert_dec_to_hex(char *str);
static char	*case_not_zero(char *str, int nbr, int pos);
static char	*case_zero(char *str, int pos);

bool	parse_colour(t_map *map, char ***file)
{
	bool	are_all_set;

	are_all_set = false;
	skip_empty_line(file);
	if (ft_strncmp("F ", **file, 2) == 0)
		map->floor = ft_strndup(**file, 2, ft_strlen(**file) - 2);
	(*file)++;
	skip_empty_line(file);
	if (ft_strncmp("C ", **file, 2) == 0)
		map->ceiling = ft_strndup(**file, 2, ft_strlen(**file) - 2);
	(*file)++;
	if (map->floor != NULL && map->floor[0] != '\0')
		map->floor_hex = convert_dec_to_hex(map->floor);
	if (!map->floor_hex)
		return (false);
	if (map->ceiling != NULL && map->ceiling[0] != '\0')
		map->ceiling_hex = convert_dec_to_hex(map->ceiling);
	if (!map->ceiling_hex)
		return (false);
	are_all_set = are_colours_set(map);
	return (are_all_set);
}

static bool	are_colours_set(t_map *map)
{
	if (map->floor == NULL || map->floor[0] == '\0')
		return (false);
	if (map->floor_hex == NULL || map->floor_hex[0] == '\0')
		return (false);
	if (map->ceiling == NULL || map->ceiling[0] == '\0')
		return (false);
	if (map->ceiling_hex == NULL || map->ceiling_hex[0] == '\0')
		return (false);
	return (true);
}

// This function converts xxx.xxx.xxx as hex value.
// xxx can be 0 to 255.

static char	*convert_dec_to_hex(char *str)
{
	int			tmp;
	int			i;
	char		*hex;

	i = 0;
	hex = malloc(sizeof(char) * 7);
	if (!str)
		return (NULL);
	while (*str != '\0')
	{
		tmp = 0;
		while (ft_isdigit(*str))
			tmp = (tmp * 10) + (*(str++) - '0');
		if (tmp == 0)
			hex = case_zero(hex, i);
		else
			hex = case_not_zero(hex, tmp, i);
		if (hex == NULL)
			return (NULL);
		i = i + 2;
		if (*str != '\0')
			str++;
	}
	hex[6] = '\0';
	return (hex);
}

static char	*case_not_zero(char *str, int nbr, int pos)
{
	int			tmp;
	static char	*base = "0123456789ABCDEF\0";
	int			base_len;

	if (nbr < 0 || nbr > 255)
	{
		free(str);
		return (NULL);
	}
	base_len = ft_strlen(base);
	tmp = nbr;
	while (tmp != 0)
	{
		tmp = tmp / base_len;
		pos++;
	}
	str[pos--] = '\0';
	while (nbr != 0)
	{
		str[pos--] = base[nbr % base_len];
		nbr = nbr / base_len;
	}
	return (str);
}

static char	*case_zero(char *str, int pos)
{
	str[pos] = '0';
	str[pos + 1] = '0';
	return (str);
}
