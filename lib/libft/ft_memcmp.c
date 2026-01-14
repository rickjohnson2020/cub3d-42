/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:40:59 by takaito           #+#    #+#             */
/*   Updated: 2024/12/04 12:41:00 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1 = s1;
	const unsigned char	*str2 = s2;
	int					res;

	res = 0;
	while (n > 0)
	{
		if (*str1 != *str2)
		{
			res = *str1 - *str2;
			return (res);
		}
		str1++;
		str2++;
		n--;
	}
	return (res);
}
/*
int	main()
{
	char	str1[] = {-128,0,127,0};
	char	str2[] = {0,0,127,0};
	int		n = 4;
	int		res;

	res = ft_memcmp(str1, str2, n);
	printf("return: %d\n", res);
}
*/