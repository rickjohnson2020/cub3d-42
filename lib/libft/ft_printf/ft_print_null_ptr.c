/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_null_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:00:32 by takaito           #+#    #+#             */
/*   Updated: 2025/01/21 11:14:45 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_null_ptr(void)
{
	char	*str;
	int		length;

	str = "(nil)";
	length = ft_print_str(str);
	return (length);
}
