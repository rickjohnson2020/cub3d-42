/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:41:05 by takaito           #+#    #+#             */
/*   Updated: 2024/12/04 12:41:07 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*sptr = (const unsigned char*)src;
	unsigned char		*dptr;
	unsigned int		i;

	dptr = (unsigned char *)dest;
	i = 0;
	while (n > i)
	{
		dptr[i] = sptr[i];
		i++;
	}
	return (dptr);
}
/*
int	main(int argc, char **argv)
{
	char	src[] = "12345678";
	char	dest[] = "00000000";

	printf("Source      : %s\n", src);
	printf("Dest before : %s\n", dest);
	printf("Soruce mem  : %p\n", src);
	printf("Dest mem    : %p\n", dest);
	ft_memcpy(dest, src, 8);
	printf("Dest after  : %s\n", dest);
	printf("Dest mem    : %p\n", dest);
	return (0);
}
*/