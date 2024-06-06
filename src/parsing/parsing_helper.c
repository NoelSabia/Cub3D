/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:05:20 by nsabia            #+#    #+#             */
/*   Updated: 2024/06/06 17:05:48 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*clean_data(char *str)
{
	int		i;
	int		len;
	char	*result;

	i = 0;
	while (str[i] && (str[i] == 'N' || str[i] == 'O' || str[i] == 'S'
			|| str[i] == 'W' || str[i] == 'A' || str[i] == 'F'
			|| str[i] == 'C' || str[i] == 32))
		i++;
	len = ft_strlen(str);
	printf("len: %d\n", len);
	printf("i: %d\n", i);
	result = ft_strncpy(str, i, len);
	printf("%s\n", result);
	return (result);
}

void	fill_structures(t_parsing *parse, char *str1, char *str2)
{
	(void)parse;
	(void)str1;
	(void)str2;
}

void	check_if_exists(char *str1, char *str2, t_parsing *parse)
{
	char	*str;

	printf("str1: %s\nstr2: %s\n", str1, str2);
	if (ft_strncmp(str1, "NO", 2) == 0)
	{
		str = clean_data(str1);
		fill_structures(parse, str, "NO");
	}
	else if (ft_strncmp(str1, "SO", 2) == 0)
	{
		str = clean_data(str1);
		fill_structures(parse, str1, "SO");
	}
	else if (ft_strncmp(str1, "WE", 2) == 0)
	{
		str = clean_data(str1);
		fill_structures(parse, str1, "WE");
	}
	else if (ft_strncmp(str1, "EA", 2) == 0)
	{
		str = clean_data(str1);
		fill_structures(parse, str1, "EA");
	}
	else if (ft_strncmp(str2, "F", 2) == 0)
	{
		str = clean_data(str2);
		fill_structures(parse, str2, "F");
	}
	else if (ft_strncmp(str2, "C", 2) == 0)
	{
		str = clean_data(str2);
		fill_structures(parse, str2, "C");
	}
	else if (ft_strncmp(str2, "\n", 1) == 0)
		return ;
	else
		clean_exit("Not all elements included in the .cub file!");
}

void	fill_parse_struct(t_parsing *parse)
{
	int		i;
	char	*str1;
	char	*str2;

	i = -1;
	while (parse->input[++i])
	{
		printf("%s\n", parse->input[i]);
		str1 = ft_strncpy(parse->input[i], 0, 1);
		str2 = ft_strncpy(parse->input[i], 0, 0);
		check_if_exists(str1, str2, parse);
	}
}
