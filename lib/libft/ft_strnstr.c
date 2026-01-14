/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:41:47 by takaito           #+#    #+#             */
/*   Updated: 2024/12/04 12:41:49 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *s);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	while (*big != '\0' && len >= little_len)
	{
		if (ft_memcmp(big, little, little_len) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
/*
int	main()
{
	char	*big = "abcdefg";
	char	*little = "";
	size_t	n = 2;
	char	*res = ft_strnstr(big, little, n);

	printf("big address: %p\n", big);
	printf("little in big address: %p\n", res);
	return (0);
}
*/