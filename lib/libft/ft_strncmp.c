/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:12:10 by takaito           #+#    #+#             */
/*   Updated: 2024/11/27 18:10:00 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	s1_len;
	unsigned int	s2_len;
	int				comp_result;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	comp_result = 0;
	while ((i < n) && (i <= s1_len || i <= s2_len))
	{
		comp_result = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (comp_result != 0)
			return (comp_result);
		i++;
	}
	return (comp_result);
}
/*
int	main(void)
{
	char	*s1 = "bb\200";
	char	*s2 = "bb";
	char	*s3 = "CAB";
	char	*s4 = "ABC";
	char	*s5 = "@";
	char	*s6 = "@";
	int	res1;
	int	res2;
	int	res3;


	res1 = ft_strncmp(s1, s2, 3);
	printf("compare s1 and s2 : %d\n", res1);
	res2 = ft_strncmp(s3, s4, 2);
	printf("compare s3 and s4 : %d\n", res2);
	res3 = ft_strncmp(s5, s6 ,2);
	printf("compare s5 and s6 : %d\n", res3);
}
*/
