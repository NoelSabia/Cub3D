/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fill_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:05:20 by nsabia            #+#    #+#             */
/*   Updated: 2024/07/01 16:13:47 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*clean_data(char *str)
{
	int		i;
	char	*result;

	i = 0;
	while (str[i] && ft_strchr("NOSWAFEC 	", str[i]))
		i++;
	result = ft_strncpy(str, i, ft_strlen(str));
	return (result);
}

void	check_if_exists(char *str1, char *str2, t_mlx *mlx, char *line)
{
	char	*str;

	if (ft_strncmp(str2, "\n", 1) == 0)
		return ;
	else if (ft_strncmp(str1, "NO", 2) == 0)
	{
		if (mlx->parse->north_set)
			clean_exit("Error: 'NO' specified more than once.");
		str = clean_data(line);
		mlx->parse->north = str;
		mlx->parse->north_set = 1;
	}
	else if (ft_strncmp(str1, "SO", 2) == 0)
	{
		if (mlx->parse->south_set)
			clean_exit("Error: 'SO' specified more than once.");
		str = clean_data(line);
		mlx->parse->south = str;
		mlx->parse->south_set = 1;
	}
	else if (ft_strncmp(str1, "WE", 2) == 0)
	{
		if (mlx->parse->west_set)
			clean_exit("Error: 'WE' specified more than once.");
		str = clean_data(line);
		mlx->parse->west = str;
		mlx->parse->west_set = 1;
	}
	else if (ft_strncmp(str1, "EA", 2) == 0)
	{
		if (mlx->parse->east_set)
			clean_exit("Error: 'EA' specified more than once.");
		str = clean_data(line);
		mlx->parse->east = str;
		mlx->parse->east_set = 1;
	}
	else if (ft_strncmp(str2, "F", 1) == 0)
	{
		if (mlx->parse->floor_set)
			clean_exit("Error: 'F' specified more than once.");
		str = clean_data(line);
		mlx->parse->floor = str;
		mlx->parse->floor_set = 1;
	}
	else if (ft_strncmp(str2, "C", 1) == 0)
	{
		if (mlx->parse->ceiling_set)
			clean_exit("Error: 'C' specified more than once.");
		str = clean_data(line);
		mlx->parse->ceiling = str;
		mlx->parse->ceiling_set = 1;
	}
	else if (ft_strncmp(str1, "0", 1) == 0 || ft_strncmp(str1, "1", 1) == 0
		|| ft_strncmp(str2, "0", 1) == 0 || ft_strncmp(str2, "1", 1) == 0)
		return ;
	else
		clean_exit("Not all elements included in the .cub file!");
	mlx->parse->input_counter++;
}

void	fill_parse_struct(t_mlx *mlx)
{
	int		i;
	int		m;
	char	*str1;
	char	*str2;
	char	*line;

	i = -1;
	mlx->parse->input_counter = 0;
	while (mlx->parse->input[++i])
	{
		m = 0;
		while (mlx->parse->input[i][m] == '\t' || mlx->parse->input[i][m] == 32)
			m++;
		str1 = ft_strncpy(&mlx->parse->input[i][m], 0, 1);
		str2 = ft_strncpy(&mlx->parse->input[i][m], 0, 0);
		line = mlx->parse->input[i];
		check_if_exists(str1, str2, mlx, line);
	}
	if (mlx->parse->north_set != 1 || mlx->parse->west_set != 1
		|| mlx->parse->south_set != 1 || mlx->parse->east_set != 1
		|| mlx->parse->ceiling_set != 1 || mlx->parse->floor_set != 1)
		clean_exit("Not all elements included in the .cub file!");
}
