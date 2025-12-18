/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:34:02 by takaito           #+#    #+#             */
/*   Updated: 2024/12/01 13:34:04 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src);

char	*ft_strdup(const char *src)
{
	int		i;
	char	*res;

	i = ft_strlen(src) + 1;
	res = (char *)malloc(i * sizeof(char));
	if (res == NULL)
		return (NULL);
	res = ft_strcpy(res, src);
	return (res);
}

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
