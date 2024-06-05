/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 02:31:36 by nsabia            #+#    #+#             */
/*   Updated: 2024/06/05 15:33:07 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	read_into_input(t_parsing *parse, char *filename)
{
	int	fd;

	(void)parse;
	fd = open(filename, O_RDONLY);
}

void	parsing(t_parsing *parse, char *filename)
{
	read_into_input(parse, filename);
}
