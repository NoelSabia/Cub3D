/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 02:31:36 by nsabia            #+#    #+#             */
/*   Updated: 2024/06/05 20:31:18 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <string.h>

char	*read_into_input(char *filename)
{
	int		fd;
	char	*buffer;
	int		size;

	size = 1000000;
	buffer = ft_calloc(1, size);
	fd = open(filename, O_RDONLY);
	while (read(fd, buffer, size - 1))
	{
		buffer = ft_realloc(buffer, size, size + 100);
		size = size + 100;
	}
	close(fd);
	return (buffer);
}

char	*replace_tab(const char *str, char old_char, const char *new_str)
{
	int		i;
	int		count;
	int		new_str_len;
	char	*result;
	int		j;

	i = -1;
	count = 0;
	j = -1;
	new_str_len = ft_strlen(new_str);
	while (str[++i])
		if (str[i] == old_char)
			count++;
	result = ft_calloc(1, (count * new_str_len) + (ft_strlen(str) + 1));
	i = -1;
	while (str[++i])
	{
		if (str[i] == old_char)
		{
			ft_strlcpy(&result[j], new_str, ft_strlen(new_str));
			j += new_str_len;
		}
		else
			result[++j] = str[i];
	}
	result[++j] = '\0';
	return (result);
}

void	parsing(t_parsing *parse, char *filename)
{
	char	*output;
	char	*clean_output;

	(void)parse;
	output = read_into_input(filename);
	clean_output = replace_tab(output, '	', "    ");
	// fill_parse_struct(parse, clean_output);
	printf("%s\n", clean_output);
}
