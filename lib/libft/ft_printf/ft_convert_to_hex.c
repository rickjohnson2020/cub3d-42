/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:39:34 by takaito           #+#    #+#             */
/*   Updated: 2025/01/21 11:14:10 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	case_zero(char *str);
static void	case_not_zero(char *str, char *base,
				unsigned long nbr, unsigned long base_len);

char	*ft_convert_to_hex(unsigned long nbr, char *base)
{
	unsigned long	base_len;
	char			*str;

	base_len = (unsigned long)ft_strlen(base);
	str = (char *)malloc(17 * sizeof(char));
	if (str == NULL || base_len < 2)
		return (NULL);
	if (nbr == 0)
		case_zero(str);
	else
		case_not_zero(str, base, nbr, base_len);
	return (str);
}

static void	case_not_zero(char *str, char *base,
				unsigned long nbr, unsigned long base_len)
{
	long	tmp;
	int		i;

	i = 0;
	tmp = nbr;
	while (tmp != 0)
	{
		tmp = tmp / base_len;
		i++;
	}
	str[i--] = '\0';
	while (nbr != 0)
	{
		str[i--] = base[nbr % base_len];
		nbr = nbr / base_len;
	}
}

static void	case_zero(char *str)
{
	str[0] = '0';
	str[1] = '\0';
}
