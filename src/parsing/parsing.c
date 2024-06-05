/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 02:31:36 by nsabia            #+#    #+#             */
/*   Updated: 2024/06/05 18:21:10 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*read_into_input(char *filename)
{
	int		fd;
	char	*buffer;
	int		size;
	int		i;

	size = 1000000;
	buffer = ft_calloc(1, size);
	i = 0;
	fd = open(filename, O_RDONLY);
	while (read(fd, buffer, size))
	{
		buffer = ft_realloc(buffer, size, size + 100);
		size = size + 100;
		i = size;
	}
	buffer[size] = '\0';
	close(fd);
	return (buffer);
}

void	parsing(t_parsing *parse, char *filename)
{
	char	*result;

	(void)parse;
	result = read_into_input(filename);
}
