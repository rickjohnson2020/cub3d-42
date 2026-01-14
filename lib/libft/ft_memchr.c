/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:40:49 by takaito           #+#    #+#             */
/*   Updated: 2024/12/04 12:40:50 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*sptr;
	unsigned char		uc;
	unsigned int		i;

	sptr = (unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (n > i)
	{
		if (sptr[i] == uc)
		{
			return ((void *)&sptr[i]);
		}
		i++;
	}
	return (NULL);
}
