/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 00:47:44 by nsabia            #+#    #+#             */
/*   Updated: 2024/06/05 19:36:49 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	main(int argc, char *argv[])
{
	t_parsing	*parse;

	parse = ft_malloc(sizeof(parse));
	if (argc < 2 || argc > 2)
		printf("Usage: ./Cub3d <filename>.cub\n");
	else
		parsing(parse, argv[1]);
	ft_free_all();
	return (0);
}
