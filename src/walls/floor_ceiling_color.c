/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:41:50 by nsabia            #+#    #+#             */
/*   Updated: 2024/07/01 16:27:56 by nsabia           ###   ########.fr       */
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

void    floor_color(t_mlx *mlx)
{
    uint8_t floor_color[3];
    char    *temp;
    char    *temp2;
    int     i;
    int     k;

    k = 0;
    i = 0;
    check_string(mlx->parse->floor);
    while (strchr(" \t", mlx->parse->floor[k]))
        k++;
    while (mlx->parse->floor[k] && i < 3)
    {
        temp = malloc(1);
        temp[0] = '\0';
        while (strchr("0123456789", mlx->parse->floor[k]))
        {
            temp2 = char_to_str(mlx->parse->floor[k++]);
            temp = ft_strjoin(temp, temp2);
        }
        floor_color[i++] = ft_atoi(temp);
        if (ft_atoi(temp) < 0 || ft_atoi(temp) > 255)
            clean_exit("Wrong number in F or C choose between 0 and 255!");
        if (mlx->parse->floor[k] == ',')
            k++;
    }
    if (i != 3)
        clean_exit("Invalid floor color format!");
   mlx->parse->floor_color = (floor_color[0] << 24) | (floor_color[1] << 16) | (floor_color[2] << 8) | 0xFF;
}

void floor_and_ceiling_color(t_mlx *mlx)
{
    uint8_t ceiling[3];
    char    *temp;
    char    *temp2;
    int     i;
    int     k;

    k = 0;
    i = 0;
    floor_color(mlx);
    check_string(mlx->parse->ceiling);
    while (strchr(" \t", mlx->parse->ceiling[k]))
        k++;
    while (mlx->parse->ceiling[k] && i < 3)
    {
        temp = malloc(1);
        temp[0] = '\0';
        while (strchr("0123456789", mlx->parse->ceiling[k]))
        {
            temp2 = char_to_str(mlx->parse->ceiling[k++]);
            temp = ft_strjoin(temp, temp2);
        }
        ceiling[i++] = ft_atoi(temp);
        if (ft_atoi(temp) < 0 || ft_atoi(temp) > 255)
            clean_exit("Wrong number in F or C choose between 0 and 255!");
        if (mlx->parse->ceiling[k] == ',')
            k++;
    }
    if (i != 3)
        clean_exit("Invalid ceiling color format!");
   mlx->parse->ceiling_color = (ceiling[0] << 24) | (ceiling[1] << 16) | (ceiling[2] << 8) | 0xFF;
}
    
