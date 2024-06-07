/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:05:20 by nsabia            #+#    #+#             */
/*   Updated: 2024/06/06 17:27:45 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*clean_data(char *str)
{
	int		i;
	char	*result;

	i = 0;
	while (str[i] && (str[i] == 'N' || str[i] == 'O' || str[i] == 'S'
			|| str[i] == 'W' || str[i] == 'A' || str[i] == 'F' || str[i] == 'E'
			|| str[i] == 'C' || str[i] == 32 || str[i] == '\t'))
		i++;
	result = ft_strncpy(str, i, ft_strlen(str));
	return (result);
}

void	check_if_exists(char *str1, char *str2, t_parsing *parse, char *line)
{
	char	*str;

	if (ft_strncmp(str1, "NO", 2) == 0)
	{
		str = clean_data(line);
		parse->north = str;
	}
	else if (ft_strncmp(str1, "SO", 2) == 0)
	{
		str = clean_data(line);
		parse->south = str;
	}
	else if (ft_strncmp(str1, "WE", 2) == 0)
	{
		str = clean_data(line);
		parse->west = str;
	}
	else if (ft_strncmp(str1, "EA", 2) == 0)
	{
		str = clean_data(line);
		parse->east = str;
	}
	else if (ft_strncmp(str2, "F", 2) == 0)
	{
		str = clean_data(line);
		parse->floor = str;
	}
	else if (ft_strncmp(str2, "C", 2) == 0)
	{
		str = clean_data(line);
		parse->ceiling = str;
	}
	else if (ft_strncmp(str2, "\n", 1) == 0)
		return ;
	else
		clean_exit("Not all elements included in the .cub file!");
	parse->input_counter++;
}

void	fill_parse_struct(t_parsing *parse)
{
	int		i;
	int		m;
	char	*str1;
	char	*str2;
	char	*line;

	i = -1;
	while (parse->input[++i] && parse->input_counter < 6)
	{
		m = 0;
		while (parse->input[i][m] == '\t' || parse->input[i][m] == 32)
			m++;
		str1 = ft_strncpy(&parse->input[i][m], 0, 1);
		str2 = ft_strncpy(&parse->input[i][m], 0, 0);
		line = parse->input[i];
		check_if_exists(str1, str2, parse, line);
	}
}
