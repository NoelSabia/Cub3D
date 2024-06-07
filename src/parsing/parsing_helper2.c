/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:17:21 by nsabia            #+#    #+#             */
/*   Updated: 2024/06/07 22:09:21 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdbool.h>

void    put_in_map(int *i, t_parsing *parse)
{
	(void)i;
	(void)parse;
}

char    **fill_allowed_chars()
{
	char    **allowed_chars;

	allowed_chars = ft_malloc(9 * sizeof(char *));
	allowed_chars[0] = ft_strdup("0");
	allowed_chars[1] = ft_strdup("1");
	allowed_chars[2] = ft_strdup("N");
	allowed_chars[3] = ft_strdup("S");
	allowed_chars[4] = ft_strdup("W");
	allowed_chars[5] = ft_strdup("E");
	allowed_chars[6] = ft_strdup(" ");
	allowed_chars[7] = ft_strdup("	");
	allowed_chars[8] = NULL;
	return (allowed_chars);
}

bool    is_only_included(char *str)
{
    char    **allowed_chars;
    int     i;
    int     k;
    size_t  is_inside;

    allowed_chars = fill_allowed_chars();
    i = -1;
    is_inside = 0;
    while (str[++i])
    {
        k = -1;
        while (allowed_chars[++k] != NULL)
        {
            if (str[i] == allowed_chars[k][0])
				is_inside++;
        }
    }
	if (is_inside == ft_strlen(str))
		return (true);
	return (false);
}


void    search_for_map_start(t_parsing *parse)
{
	int i;

	i = 0;
while (parse->input[i]) 
{
		if (is_only_included(parse->input[i]) == true)
		{
			printf("here: %s\n", parse->input[i]);
			put_in_map(&i, parse);
			return ;
		}
		i++;
}
}

void    validate_map(t_parsing *parse)
{
	search_for_map_start(parse);
	// flood_fill(parse);
}
