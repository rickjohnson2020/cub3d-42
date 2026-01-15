/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:55:19 by takaito           #+#    #+#             */
/*   Updated: 2024/12/15 15:55:22 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*res;
	size_t		s1_len;
	size_t		s2_len;
	size_t		i;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (res == NULL)
		return (NULL);
	while (s1 && *s1 != '\0')
		res[i++] = *s1++;
	while (s2 && *s2 != '\0')
		res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}
/*
int	main(int argc, char **argv)
{
	char	*em;
	char	*result;
	em = "Error! Please input correct parameter";
	if (argc != 3)
		write (1, em, 39);
	result = ft_strjoin(argv[1], argv[2]);
	printf ("result is :%s", result);
	return (0);
}
*/