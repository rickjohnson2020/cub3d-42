/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:30:42 by takaito           #+#    #+#             */
/*   Updated: 2025/01/21 11:15:35 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_u_int_len(unsigned int u);

int	ft_print_u_int(unsigned int u)
{
	int	length;

	ft_put_u_int_fd(u, STDOUT_FILENO);
	length = ft_u_int_len(u);
	return (length);
}

static int	ft_u_int_len(unsigned int u)
{
	int	length;

	length = 0;
	if (u == 0)
		length++;
	while (u != 0)
	{
		u = u / 10;
		length++;
	}
	return (length);
}
