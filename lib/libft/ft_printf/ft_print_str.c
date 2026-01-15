/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:28:41 by takaito           #+#    #+#             */
/*   Updated: 2025/01/21 11:14:55 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	length;

	if (str == NULL)
	{
		length = ft_strlen("(null)");
		ft_putstr_fd("(null)", STDOUT_FILENO);
	}
	else
	{
		length = ft_strlen(str);
		ft_putstr_fd(str, STDOUT_FILENO);
	}
	return (length);
}
