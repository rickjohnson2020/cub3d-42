/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:13:10 by takaito           #+#    #+#             */
/*   Updated: 2024/11/27 18:28:00 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == uc)
		{
			return ((char *)s);
		}
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	return (NULL);
}
/*
int	main()
{
	char	*res;

	res = ft_strchr("abcde",'a');
	printf("1:%s\n", res);
	res = ft_strchr("abcde",'b');
	printf("2:%s\n", res);
	res = ft_strchr("abcde",'c');
	printf("3:%s\n", res);
	res = ft_strchr("abcde",'d');
	printf("4:%s\n", res);
	res = ft_strchr("abcde",'e');
	printf("5:%s\n", res);
	res = ft_strchr("abcde",'\0');
	printf("6:%s\n", res);
	res = ft_strchr("abcde",'a'+256);
	printf("7:%s\n", res);
	return(0);
}
*/