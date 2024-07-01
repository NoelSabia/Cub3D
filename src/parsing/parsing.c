/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 02:31:36 by nsabia            #+#    #+#             */
/*   Updated: 2024/07/01 16:30:00 by nsabia           ###   ########.fr       */
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

void	put_in_2d_array(t_mlx *mlx, char *clean_output)
{
	int		i;
	int		j;
	int		k;
	int		line_count;
	char	*str;

	i = -1;
	j = 0;
	k = 0;
	line_count = 0;
	while (clean_output[++i])
		if (clean_output[i] == '\n')
			line_count++;
	mlx->parse->input = ft_malloc((line_count + 3) * sizeof(char *));
	i = 0;
	while (clean_output[i])
	{
		while (clean_output[i] && clean_output[i] != '\n')
			i++;
		str = ft_strncpy(clean_output, j, i);
		i++;
		j = i;
		mlx->parse->input[k++] = ft_strdup(str);
	}
	mlx->parse->input[k] = NULL;
}

void	parsing(t_mlx *mlx, char *filename)
{
	char	*output;
	char	*clean_output;

	output = read_into_input(filename);
	clean_output = replace_tab(output, '	', "    ");
	put_in_2d_array(mlx , clean_output);
	fill_parse_struct(mlx);
	validate_map(mlx);
}
