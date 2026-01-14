/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:55:19 by takaito           #+#    #+#             */
/*   Updated: 2024/12/15 15:55:22 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_min(void)
{
	char	*res;

	res = ft_strdup("-2147483648");
	return (res);
}

static char	*ft_itoa_zero(void)
{
	char	*res;

	res = ft_strdup("0");
	return (res);
}

static char	*ft_itoa_plus(int n)
{
	char	*res;
	int		org_n;
	int		i;

	org_n = n;
	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (NULL);
	res[i] = '\0';
	i--;
	while (i >= 0)
	{
		res[i--] = '0' + (org_n % 10);
		org_n = org_n / 10;
	}
	return (res);
}

static char	*ft_itoa_minus(int n)
{
	char	*res;
	int		org_n;
	int		i;

	n = -n;
	org_n = n;
	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	res = (char *)malloc(sizeof(char) * (i + 2));
	if (res == NULL)
		return (NULL);
	res[i + 1] = '\0';
	while (i > 0)
	{
		res[i] = '0' + (org_n % 10);
		org_n = org_n / 10;
		i--;
	}
	res[i] = '-';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;

	res = NULL;
	if (n == -2147483648)
		res = ft_itoa_min();
	else if (n == 0)
		res = ft_itoa_zero();
	else if (n > 0)
		res = ft_itoa_plus(n);
	else if (n < 0)
		res = ft_itoa_minus(n);
	return (res);
}
/*
int	main()
{
	int	i_min = -2147483648;
	int	i_max = 2147483647;
	int	i_minus1 = -3456;
	int	i_minus2 = -2147483647;
	int i_plus = 1234567890;
	printf("%d:%s\n", i_min, ft_itoa(i_min));
	printf("%d:%s\n", i_max, ft_itoa(i_max));
	printf("%d:%s\n", i_minus1, ft_itoa(i_minus1));
	printf("%d:%s\n", i_minus2, ft_itoa(i_minus2));
	printf("%d:%s\n", i_plus, ft_itoa(i_plus));
	return (0);
}
*/