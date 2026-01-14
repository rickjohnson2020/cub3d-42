/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:53:59 by takaito           #+#    #+#             */
/*   Updated: 2024/12/15 15:54:03 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_calc_size(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	res_size;
	size_t	i;

	i = 0;
	res_size = ft_calc_size(s, start, len);
	res = (char *)malloc(sizeof(char) * res_size);
	if (res == NULL)
		return (NULL);
	if (res_size > 1)
	{
		while (s[i + start] != '\0' && i < res_size - 1)
		{
			res[i] = s[i + start];
			i++;
		}
	}
	res[i] = '\0';
	return (res);
}

static size_t	ft_calc_size(char const *s, unsigned int start, size_t len)
{
	size_t	res;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		res = 1;
	else if (s_len - start < len)
		res = s_len - start + 1;
	else
		res = len + 1;
	return (res);
}

/*
int	main(int argc, char **argv)
{
	char	*em;
	char	*result;
	em = "Error! Please input correct parameter";
	if (argc != 2)
		write (1, em, 39);
	result = ft_substr(em, 5, 5);
	printf ("result is :%s", result);
	return (0);
}
*/