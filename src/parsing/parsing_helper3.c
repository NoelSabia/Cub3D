/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:27:24 by nsabia            #+#    #+#             */
/*   Updated: 2024/06/16 13:08:55 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*fill_spaces(int len)
{
	char	*str;
	int		counter;

	str = ft_malloc(len + 1);
	counter = 0;
	while (counter++ <= len)
		str = ft_strjoin(" ", str);
	return (str);
}

char	*combine_strs(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*result;
	int		len;

	i = 0;
	j = 0;
	result = ft_malloc(ft_strlen(str1) + ft_strlen(str2) + 2);
	len = ft_strlen(str1);
	if (len > 0 && str1[len - 1] == '\n')
		str1[len - 1] = '\0';
	while (str1[i])
	{
		result[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		result[i + j] = str2[j];
		j++;
	}
	result[i + j] = '\n';
	result[i + j + 1] = '\0';
	return (result);
}

void	out_of_bounce_procection(t_parsing *parse)
{
	int	len;
	int	longest;
	int	i;
	int	m;

	len = 0;
	i = -1;
	longest = 0;
	while (parse->map[++i])
	{
		len = ft_strlen(parse->map[i]);
		if (len > longest)
			longest = len;
	}
	longest--;
	parse->cols = i;
	parse->rows = longest;
	i = -1;
	while (parse->map[++i])
	{
		m = 0;
		while (parse->map[i][m])
			m++;
		parse->map[i] = combine_strs(parse->map[i], fill_spaces(longest - m));
	}
}

//x - line index, y - column index, so that map[x][y]
//in our code cols - how many lines, rows - how many columns
void	flood_fill(t_parsing *parse, int x, int y, char **map_copy)
{
	printf("ff coordinates: [%d] [%d]\n", x, y);

	if (x < 0 || x >= parse->cols || y < 0\
		|| y >= (int)ft_strlen(map_copy[x]))
		clean_exit("Error: player isn't locked inside the map\n");
	else if (map_copy[x][y] == '1' || map_copy[x][y] == '*')
		return ;
	printf("the length of line: %d\n", (int)ft_strlen(map_copy[x]));
	map_copy[x][y] = '*';
	flood_fill(parse, x - 1, y, map_copy);
	flood_fill(parse, x + 1, y, map_copy);
	flood_fill(parse, x, y - 1, map_copy);
	flood_fill(parse, x, y + 1, map_copy);
}

void	flood_fill_organizer(t_parsing *parse)
{
	char	**map_copy;

	out_of_bounce_procection(parse);
	parse->x = 0;
	parse->y = 0;
	for (int i = 0; parse->map[i]; i++)
		printf("%s", parse->map[i]);
	printf("the rows: %d, the columns: %d\n", parse->rows, parse->cols);
	find_player(parse);
	map_copy = map_copy_it(parse);
	flood_fill(parse, parse->x, parse->y, map_copy);
	printf("success, player locked\n");
}
