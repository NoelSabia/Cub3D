/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_flood_fill_preparation.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:17:21 by nsabia            #+#    #+#             */
/*   Updated: 2024/07/01 16:30:19 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_in_map(int *i, t_mlx *mlx)
{
	int	len;
	int	k;

	len = 0;
	k = -1;
	while (mlx->parse->input[(*i)++])
		len++;
	(*i) -= len;
	len += (*i);
	mlx->parse->map = ft_malloc(len * sizeof(char *));
	(*i) -= 2;
	while (mlx->parse->input[++(*i)])
		mlx->parse->map[++k] = ft_strdup(mlx->parse->input[(*i)]);
	mlx->parse->map[++k] = NULL;
}

bool	is_only_included(char *str)
{
	int		i;
	size_t	is_inside;

	i = -1;
	is_inside = 0;
	if (ft_strchr(str, '0') == NULL && ft_strchr(str, '1') == NULL)
		return (false);
	while (str[++i])
	{
		if (str[i] == '0' || str[i] == '1' || str[i] == 'N'
			|| str[i] == 'W' || str[i] == 'E' || str[i] == 'S'
			|| str[i] == 32 || str[i] == '\t' || str[i] == '\n')
			is_inside++;
	}
	if (is_inside == ft_strlen(str))
		return (true);
	return (false);
}

void	search_for_map_start(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->parse->input[i])
	{
		if (is_only_included(mlx->parse->input[i]) == true)
		{
			put_in_map(&i, mlx);
			return ;
		}
		i++;
	}
}

void	search_player_position(t_mlx *mlx)
{
	int	i;
	int	m;

	i = -1;
	while (mlx->parse->map[++i])
	{
		m = 0;
		while (mlx->parse->map[i][m] == '\t' || mlx->parse->map[i][m] == ' '
			|| mlx->parse->map[i][m] == '1' || mlx->parse->map[i][m] == '0')
			m++;
		if (mlx->parse->map[i][m] == 'N' || mlx->parse->map[i][m] == 'S'
			|| mlx->parse->map[i][m] == 'W' || mlx->parse->map[i][m] == 'E')
		{
			mlx->parse->player_y = i;
			mlx->parse->player_x = m;
			return ;
		}
	}
}

void	validate_map(t_mlx *mlx)
{
	search_for_map_start(mlx);
	search_player_position(mlx);
	flood_fill_organizer(mlx);
}
