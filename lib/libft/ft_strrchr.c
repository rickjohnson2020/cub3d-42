/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:13:10 by takaito           #+#    #+#             */
/*   Updated: 2024/11/27 18:28:00 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	uc;
	int				i;

	uc = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
		i++;
	if (uc == '\0')
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == uc)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
/*
{
	unsigned char	uc;
	int				i;

	uc = (unsigned char)c;
	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
			i++;
		while (i < 0)
		{
			if (s[i] == uc)
				return ((char *)s);
			i--;
		}
	}
	return (NULL);
}


int	main()
{
	char	*res;

	res = ft_strrchr("abcde",'a');
	printf("1:%s\n", res);
	res = ft_strrchr("abcde",'b');
	printf("2:%s\n", res);
	res = ft_strrchr("abcde",'c');
	printf("3:%s\n", res);
	res = ft_strrchr("abcde",'d');
	printf("4:%s\n", res);
	res = ft_strrchr("abcde",'e');
	printf("5:%s\n", res);
	res = ft_strrchr("abcde",'\0');
	printf("6:%s\n", res);
	res = ft_strrchr("abcde",'a'+256);
	printf("7:%s\n", res);
	return(0);
}
*/