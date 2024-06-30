/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 13:08:22 by oemelyan          #+#    #+#             */
/*   Updated: 2024/06/30 13:33:22 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void find_player(t_parsing *parse)
{
	int		i;
	int		j;

	i = 0;
	while(i < parse->cols)
	{
		j = 0;
		while(parse->map[i][j] != '\n')
		{
			if (parse->map[i][j] == 'N' || parse->map[i][j] == 'S'\
			|| parse->map[i][j] == 'W' || parse->map[i][j] == 'E')
			{
				parse->x = i;
				parse->y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

char	**map_copy_it(t_parsing *parse)
{
	char	**copy;
	int		i;

	copy = ft_malloc((parse->cols + 1)*sizeof(char *));
	i = 0;
	while (i < parse->cols)
	{
		copy[i] = ft_strdup(parse->map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
