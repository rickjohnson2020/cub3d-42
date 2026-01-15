/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:55:19 by takaito           #+#    #+#             */
/*   Updated: 2024/12/15 15:55:22 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_word_count(char const *s, char c)
{
	unsigned int	res;
	int				in_word;

	res = 0;
	in_word = 0;
	while (*s != '\0')
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			res++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (res);
}

static unsigned int	ft_word_len(char const *s, char c)
{
	unsigned int	res;

	res = 0;
	while (*s != '\0' && *s != c)
	{
		res++;
		s++;
	}
	return (res);
}

static char	**ft_free(char **res, int i)
{
	while (i > 0)
		free(res[--i]);
	free(res);
	return (NULL);
}

static char	**ft_arg_create(char const *s, char c, char **res)
{
	int				i;
	unsigned int	len;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len = ft_word_len(s, c);
			res[i] = (char *)malloc(sizeof(char) * (len + 1));
			if (res[i] == NULL)
				return (ft_free(res, i));
			ft_strlcpy(res[i], s, len + 1);
			s = s + len;
			i++;
		}
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!res)
		return (NULL);
	return (ft_arg_create(s, c, res));
}
