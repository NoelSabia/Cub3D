/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:07:14 by noel              #+#    #+#             */
/*   Updated: 2023/11/14 18:23:39 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
	{
		return (-1);
	}
	while (s[i] != '\0' && s[i] != (char)c)
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == (char)c)
	{
		return (i);
	}
	return (-1);
}

char	*ft_read_in_buf(int fd, char *str, int *read_bytes)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	int		newline_counter;

	*read_bytes = 0;
	newline_counter = (ft_strchr(str, '\n') == -1);
	while (newline_counter)
	{
		*read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (*read_bytes <= 0)
			break ;
		buffer[*read_bytes] = '\0';
		if (str == NULL)
		{
			str = ft_strdup(buffer);
		}
		else
		{
			temp = ft_strjoin(str, buffer);
			ft_free(str);
			str = temp;
		}
		newline_counter = (ft_strchr(buffer, '\n') == -1);
	}
	return (str);
}

void	ft_free_buf(char **buf)
{
	if (buf != NULL)
	{
		ft_free(*buf);
		*buf = NULL;
	}
}

int	ft_copy(char **str, char **result, int i)
{
	int		eos;
	char	*temp;

	eos = ft_strchr(*str, '\n');
	if (eos >= 0)
	{
		*result = ft_substr(*str, 0, eos + 1);
		temp = ft_strdup(&(*str)[eos + 1]);
		ft_free (*str);
		*str = temp;
		if (*(*str) == '\0')
			ft_free_buf(str);
	}
	else
	{
		if (i == 0)
		{
			*result = ft_strdup(*str);
			ft_free_buf(str);
			return (0);
		}
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	char		*line;
	int			i;

	i = 0;
	buf = ft_read_in_buf(fd, buf, &i);
	if (i < 0)
	{
		ft_free(buf);
		buf = NULL;
		return (NULL);
	}
	if (i == 0 && buf == NULL && ft_strchr(buf, '\n') == -1)
	{
		ft_free(buf);
		buf = NULL;
		return (NULL);
	}
	if (ft_copy(&buf, &line, i) == 1 || (i == 0 && line))
	{
		return (line);
	}
	ft_free(buf);
	buf = NULL;
	return (NULL);
}
