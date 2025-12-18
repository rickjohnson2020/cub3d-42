/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:41:18 by takaito           #+#    #+#             */
/*   Updated: 2024/12/04 12:41:19 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*sptr = (const unsigned char*)src;
	unsigned char		*dptr;
	unsigned int		i;

	dptr = (unsigned char *)dest;
	i = 0;
	if (dptr < sptr)
	{
		while (n > i)
		{
			dptr[i] = sptr[i];
			i++;
		}
	}
	else if (dptr > sptr)
	{
		i = n;
		while (i > 0)
		{
			i--;
			dptr[i] = sptr[i];
		}
	}
	return (dptr);
}
