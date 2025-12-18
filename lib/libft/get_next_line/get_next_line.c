/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaito <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:53:34 by takaito           #+#    #+#             */
/*   Updated: 2025/02/03 11:30:20 by takaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *file_contents)
{
	char	*buf;
	char	*tmp;
	ssize_t	byte_read;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	byte_read = 1;
	while (!ft_strchr(file_contents, '\n') && byte_read > 0)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(file_contents);
			break ;
		}
		if (byte_read == 0)
			break ;
		buf[byte_read] = '\0';
		tmp = ft_strjoin(file_contents, buf);
		free(file_contents);
		file_contents = tmp;
	}
	free(buf);
	return (file_contents);
}

static char	*store_rest_contents(char *file_contents, int nl_pos)
{
	char	*tmp;

	tmp = ft_strdup(file_contents + nl_pos);
	free(file_contents);
	file_contents = tmp;
	return (file_contents);
}

char	*get_next_line(int fd)
{
	static char		*file_contents = NULL;
	int				i;
	char			*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	if (!file_contents)
		file_contents = ft_strdup("");
	file_contents = read_file(fd, file_contents);
	if (file_contents == NULL || file_contents[0] == '\0')
	{
		free(file_contents);
		return (NULL);
	}
	while (file_contents[i] != '\n' && file_contents[i] != '\0')
		i++;
	if (file_contents[i] == '\n')
		i++;
	result = (char *)malloc((i + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, file_contents, i + 1);
	file_contents = store_rest_contents(file_contents, i);
	return (result);
}
