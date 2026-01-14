/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:04:59 by takaito           #+#    #+#             */
/*   Updated: 2024/12/04 12:19:40 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	res;

	res = 0;
	if (ft_isalpha(c) != 0 || ft_isdigit(c))
		res = 1;
	return (res);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	res;
	int	i;
	char	*ms;

	i = 0;
	if (argc != 2)
	{
		printf ("Error : Please input a parameter.\n");
		return (1);
	}
	while (argv[1][i] != '\0')
	{
		res = (ft_isalnum(argv[1][i]));
		if (res != 0)
			ms = "input is alphabet or number\n";
		else
			ms = "input is not alphabet or number\n";
		printf ("input : %c\n", argv[1][i]);
		printf ("return = %d %s\n", res, ms);
		i++;
	}
	return (0);
}
*/