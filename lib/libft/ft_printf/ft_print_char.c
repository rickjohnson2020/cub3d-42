/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:26:18 by takaito           #+#    #+#             */
/*   Updated: 2025/01/21 11:14:24 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int i)
{
	int	length;

	length = 1;
	ft_putchar_fd(i, STDOUT_FILENO);
	return (length);
}
