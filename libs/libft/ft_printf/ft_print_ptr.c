/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:05:43 by takaito           #+#    #+#             */
/*   Updated: 2025/01/16 20:05:45 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr, char *base)
{
	char	*str_hex;
	char	*str;
	char	*str_prefix;
	int		length;

	if (ptr == NULL)
	{
		length = ft_print_null_ptr();
		return (length);
	}
	str_prefix = "0x";
	str = (char *)malloc(19 * sizeof(char));
	str_hex = ft_convert_to_hex((long)ptr, base);
	if (str == NULL || str_hex == NULL)
	{
		length = ft_print_null_ptr();
		return (length);
	}
	ft_strlcpy(str, str_prefix, 3);
	ft_strlcat(str, str_hex, 19);
	ft_putstr_fd(str, STDOUT_FILENO);
	length = ft_strlen(str);
	free(str_hex);
	free(str);
	return (length);
}
