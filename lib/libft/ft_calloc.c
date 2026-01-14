/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:40:33 by takaito           #+#    #+#             */
/*   Updated: 2024/12/04 12:40:36 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	total_size;

	total_size = nmemb * size;
	if (total_size == 0)
		total_size = 1;
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	p = malloc(total_size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, total_size);
	return (p);
}
