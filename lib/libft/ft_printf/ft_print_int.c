/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:30:42 by takaito           #+#    #+#             */
/*   Updated: 2025/01/21 11:14:37 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_int_len(int i);

int	ft_print_int(int i)
{
	int	length;

	length = 0;
	ft_putnbr_fd(i, STDOUT_FILENO);
	length = ft_int_len(i);
	return (length);
}

static int	ft_int_len(int i)
{
	int	length;
	int	is_minus;

	is_minus = 0;
	length = 0;
	if (i < 0)
		is_minus = 1;
	if (i == 0)
		length++;
	while (i != 0)
	{
		i = i / 10;
		length++;
	}
	length = length + is_minus;
	return (length);
}
