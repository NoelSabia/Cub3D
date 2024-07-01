/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_flood_fill_helper.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 13:08:22 by oemelyan          #+#    #+#             */
/*   Updated: 2024/07/01 16:14:19 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void find_player(t_mlx *mlx)
{
	int		i;
	int		j;

	i = 0;
	while(i < mlx->parse->cols)
	{
		j = 0;
		while(mlx->parse->map[i][j] != '\n')
		{
			if (mlx->parse->map[i][j] == 'N' || mlx->parse->map[i][j] == 'S'\
			|| mlx->parse->map[i][j] == 'W' || mlx->parse->map[i][j] == 'E')
			{
				mlx->parse->x = i;
				mlx->parse->y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

char	**map_copy_it(t_mlx *mlx)
{
	char	**copy;
	int		i;

	copy = ft_malloc((mlx->parse->cols + 1)*sizeof(char *));
	i = 0;
	while (i < mlx->parse->cols)
	{
		copy[i] = ft_strdup(mlx->parse->map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
