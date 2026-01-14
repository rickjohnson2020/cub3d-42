/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:53:40 by takaito           #+#    #+#             */
/*   Updated: 2025/02/01 21:51:21 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stdlib.h>
# include "../libft.h"

char	*get_next_line(int fd);
// int		ft_strlen(const char *str);
// char	*ft_strdup(char *src);
// size_t	ft_strlcpy(char *dst, char *src, size_t size);
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_strchr(const char *s, int c);

#endif
