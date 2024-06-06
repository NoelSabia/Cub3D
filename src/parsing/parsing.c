/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 02:31:36 by nsabia            #+#    #+#             */
/*   Updated: 2024/06/06 11:15:07 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

char	*replace_tab_helper(const char *str, char *result, int *j, int *i)
{
	char	old_char;

	old_char = '\t';
	while (str[++(*i)])
	{
		if (str[*i] == old_char)
		{
			result[++(*j)] = ' ';
			result[++(*j)] = ' ';
			result[++(*j)] = ' ';
			result[++(*j)] = ' ';
		}
		else
			result[++(*j)] = str[*i];
	}
	return (result);
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
	result = replace_tab_helper(str, result, &j, &i);
	result[++j] = '\0';
	return (result);
}

void	put_in_2d_array(t_parsing *parse, char *clean_output)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	j = 0;
	k = 0;
	parse->input = ft_malloc(sizeof(parse->input));
	while (clean_output[i])
	{
		while (clean_output[i] && clean_output[i] != '\n')
			i++;
		str = ft_strncpy(clean_output, j, i);
		i++;
		j = i;
		parse->input[k++] = str;
	}
}

void	parsing(t_parsing *parse, char *filename)
{
	char	*output;
	char	*clean_output;

	output = read_into_input(filename);
	clean_output = replace_tab(output, '	', "    ");
	put_in_2d_array(parse, clean_output);
	fill_parse_struct(parse);
	printf("%s\n", clean_output);
}
