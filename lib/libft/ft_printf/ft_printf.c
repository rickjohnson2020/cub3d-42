/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:05:14 by takaito           #+#    #+#             */
/*   Updated: 2025/01/21 11:15:06 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_choose_format(const char *format, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	result = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format, 1);
			result++;
		}
		else
		{
			format++;
			result = result + ft_choose_format(format, args);
		}
		format++;
	}
	return (result);
}

static int	ft_choose_format(const char *format, va_list args)
{
	int	result;

	result = 0;
	if (*format == 'c')
		result = ft_print_char(va_arg(args, int));
	else if (*format == 's')
		result = ft_print_str(va_arg(args, char *));
	else if (*format == 'i' || *format == 'd')
		result = ft_print_int(va_arg(args, int));
	else if (*format == 'u')
		result = ft_print_u_int(va_arg(args, unsigned int));
	else if (*format == 'x')
		result = ft_print_hex(va_arg(args, int), "0123456789abcdef");
	else if (*format == 'X')
		result = ft_print_hex(va_arg(args, int), "0123456789ABCDEF");
	else if (*format == 'p')
		result = ft_print_ptr(va_arg(args, void *), "0123456789abcdef");
	else if (*format == '%')
		result = ft_print_char('%');
	return (result);
}
