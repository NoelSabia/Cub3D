/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:41:50 by nsabia            #+#    #+#             */
/*   Updated: 2024/07/01 12:45:26 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    check_string(char *str)
{
    int i;

    i = 0;
    while (str[i] && ft_strchr(" 	,0123456789", str[i]))
		i++;
	if (!ft_strchr(" 	,0123456789\n\0", str[i]))
		clean_exit("Unallowed chars in F or C detected!");
}

char    *char_to_str(char c)
{
    char    *result;

    result = ft_malloc(2);
    result[0] = c;
    result[1] = '\0';
    return (result);
}

void    floor_color(t_parsing*parse)
{
    uint8_t floor_color[3];
    char    *temp;
    char    *temp2;
    int     i;
    int     k;

    k = 0;
    i = 0;
    check_string(parse->floor);
    while (strchr(" \t", parse->floor[k]))
        k++;
    while (parse->floor[k] && i < 3)
    {
        temp = malloc(1);
        temp[0] = '\0';
        while (strchr("0123456789", parse->floor[k]))
        {
            temp2 = char_to_str(parse->floor[k++]);
            temp = ft_strjoin(temp, temp2);
        }
        floor_color[i++] = ft_atoi(temp);
        if (ft_atoi(temp) < 0 || ft_atoi(temp) > 255)
            clean_exit("Wrong number in F or C choose between 0 and 255!");
        if (parse->floor[k] == ',')
            k++;
    }
    if (i != 3)
        clean_exit("Invalid floor color format!");
   parse->floor_color = (floor_color[0] << 16) | (floor_color[1] << 8) | floor_color[2]; 
}

void floor_and_ceiling_color(t_parsing *parse)
{
    uint8_t ceiling[3];
    char    *temp;
    char    *temp2;
    int     i;
    int     k;

    k = 0;
    i = 0;
    floor_color(parse);
    check_string(parse->ceiling);
    while (strchr(" \t", parse->ceiling[k]))
        k++;
    while (parse->ceiling[k] && i < 3)
    {
        temp = malloc(1);
        temp[0] = '\0';
        while (strchr("0123456789", parse->ceiling[k]))
        {
            temp2 = char_to_str(parse->ceiling[k++]);
            temp = ft_strjoin(temp, temp2);
        }
        ceiling[i++] = ft_atoi(temp);
        if (ft_atoi(temp) < 0 || ft_atoi(temp) > 255)
            clean_exit("Wrong number in F or C choose between 0 and 255!");
        if (parse->ceiling[k] == ',')
            k++;
    }
    if (i != 3)
        clean_exit("Invalid ceiling color format!");
   parse->ceiling_color = (ceiling[0] << 16) | (ceiling[1] << 8) | ceiling[2];
}
    
