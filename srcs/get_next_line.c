
#include <unistd.h> // for read
#include <stdlib.h> // for malloc
#include <stdio.h> // for printf and End Of File
#include <fcntl.h> // for open txt file
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

typedef struct s_string
{
	char	*str;
	size_t	len;
	size_t	capa;
}	t_string;

int	ft_putc(t_string *str, char c)
{
	size_t	i;
	char	*tmp;

	//if it will over capacity, allocate additional memory
	if (str->len + 1 > str->capa)
	{
		tmp = str->str;
		str->str = (char *)malloc((str->capa + 4096) * sizeof(char));
		if (!str->str)
		{
			free(tmp);
			return (1);
		}
		//copy original str
		i = 0;
		while (i < str->len)
		{
			str->str[i] = tmp[i];
			i++;
		}
		free(tmp);
		str->capa += 4096;
	}
	// put c at the end of str
	str->str[str->len] = c;
	str->len++;
	return (0);
}

int	ft_getc(int fd)
{
	static char buf[BUFFER_SIZE];
	static char *bufp;
	static int n = 0;

	//if no buffer left, read
	if (n == 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		//if failed reset n and return errno
		if (n < 0)
		{
			n = 0;
			return (-99);
		}
		bufp = buf;
	}
	//if there is buffer left, return the char
	if (--n >= 0)
		return ((unsigned char)*bufp++);
	//otherwise reset n and return EOF
	n = 0;
	return (EOF);
}

char	*get_next_line(int fd)
{
	t_string	str;
	char		c;

	//init str
	str.str = NULL;
	str.len = 0;
	str.capa = 0;

	//inside infinite loop, getc, check if err, EOF, putc, newline
	//if failed for putc always retrun NULL
	//if EOF or newline just break
	while (1)
	{
		c = ft_getc(fd);
		if (c == -99)
		{
			free(str.str);
			return (NULL);
		}
		if (c == EOF)
			break ;
		if (ft_putc(&str, c))
			return (NULL);
		if (c == '\n')
			break ;
	}
	if (str.len > 0)
		if (ft_putc(&str, '\0'))
			return (NULL);
	return (str.str);
}
