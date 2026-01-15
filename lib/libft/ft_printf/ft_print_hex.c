/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:05:28 by takaito           #+#    #+#             */
/*   Updated: 2025/01/21 11:14:32 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(int nbr, char *base)
{
	int		length;
	char	*str;

	str = ft_convert_to_hex_int((unsigned int)nbr, base);
	ft_print_str(str);
	length = ft_strlen(str);
	free(str);
	return (length);
}
