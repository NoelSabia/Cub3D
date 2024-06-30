/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:17:21 by nsabia            #+#    #+#             */
/*   Updated: 2024/06/11 19:14:31 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_in_map(int *i, t_parsing *parse)
{
	int	len;
	int	k;

	len = 0;
	k = -1;
	while (parse->input[(*i)++])
		len++;
	(*i) -= len;
	len += (*i);
	parse->map = ft_malloc(len * sizeof(char *));
	(*i) -= 2;
	while (parse->input[++(*i)])
		parse->map[++k] = ft_strdup(parse->input[(*i)]);
	parse->map[++k] = NULL;
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

void	search_for_map_start(t_parsing *parse)
{
	int	i;

	i = 0;
	while (parse->input[i])
	{
		if (is_only_included(parse->input[i]) == true)
		{
			put_in_map(&i, parse);
			return ;
		}
		i++;
	}
}

void	search_player_position(t_parsing *parse)
{
	int	i;
	int	m;

	i = -1;
	while (parse->map[++i])
	{
		m = 0;
		while (parse->map[i][m] == '\t' || parse->map[i][m] == ' '
			|| parse->map[i][m] == '1' || parse->map[i][m] == '0')
			m++;
		if (parse->map[i][m] == 'N' || parse->map[i][m] == 'S'
			|| parse->map[i][m] == 'W' || parse->map[i][m] == 'E')
		{
			parse->player_y = i;
			parse->player_x = m;
			return ;
		}
	}
}

void	validate_map(t_parsing *parse)
{
	search_for_map_start(parse);
	search_player_position(parse);
	flood_fill_organizer(parse);
}
