/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:33:49 by takaito           #+#    #+#             */
/*   Updated: 2024/11/26 15:34:50 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
int	main(int argc, char **argv)
{
	char	*em;
	int		len;

	em = "Error\n";
	if(argc != 2)
	{
		write (1, em, 6);
		return (0);
	}
	else
	{
		len = ft_strlen(argv[1]);
		printf ("input:%s\n" , argv[1]);
		printf ("length:%d\n", len);
		return (1);
	}
}
*/
