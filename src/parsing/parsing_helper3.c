/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:27:24 by nsabia            #+#    #+#             */
/*   Updated: 2024/06/10 18:35:57 by nsabia           ###   ########.fr       */
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

char	*ft_combine_two_str(char *str1, char *str2)
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
	i = -1;
	while (parse->map[++i])
	{
		m = 0;
		while (parse->map[i][m])
			m++;
		parse->map[i]
			= ft_combine_two_str(parse->map[i], fill_spaces(longest - m));
	}
}

void	flood_fill(t_parsing *parse)
{

}

void	flood_fill_organizer(t_parsing *parse)
{
	out_of_bounce_procection(parse);
	flood_fill(parse);
}
