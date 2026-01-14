/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:08:02 by takaito           #+#    #+#             */
/*   Updated: 2025/01/21 11:15:14 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft.h"

int		ft_printf(const char *format, ...);
int		ft_print_char(int i);
int		ft_print_str(char *str);
int		ft_print_u_int(unsigned int u);
void	ft_put_u_int_fd(unsigned int u, int fd);
int		ft_print_int(int i);
int		ft_print_hex(int nbr, char *base);
int		ft_print_ptr(void *ptr, char *base);
char	*ft_convert_to_hex(unsigned long nbr, char *base);
char	*ft_convert_to_hex_int(unsigned int nbr, char *base);
int		ft_print_null_ptr(void);

#endif
