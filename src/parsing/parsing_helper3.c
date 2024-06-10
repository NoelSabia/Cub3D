/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:27:24 by nsabia            #+#    #+#             */
/*   Updated: 2024/06/08 15:43:05 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool    check_if_allowed_chars(char *str)
{
    int i;
    
    i = -1;
    while (str[++i])
    {
		if (!(str[i] == '0' || str[i] == '1' || str[i] == 'N'
				|| str[i] == 'W' || str[i] == 'E' || str[i] == 'S'
				|| str[i] == '\n' || str[i] == 32 || str[i] == '\t'))
            return (false);
    }
    return (true);
}

void    check_row_for_row(t_parsing *parse)
{
    int i;
    int m;

    i = -1;
    for (int i = 0; parse->map[i]; i++)
        printf("%s\n", parse->map[i]);
    while (parse->map[++i])
    {
		m = 0;
		while (parse->map[i][m] == '\t' || parse->map[i][m] == 32)
			m++;
        if (check_if_allowed_chars(&parse->map[i][m]) == false)
            clean_exit("Invalid Map! Unallowed char detected.");
    }
}
