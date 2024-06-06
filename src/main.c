/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 00:47:44 by nsabia            #+#    #+#             */
/*   Updated: 2024/06/06 08:52:10 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	clean_exit(char *str)
{
	printf("Error\n");
	printf("%s\n", str);
	ft_free_all();
	exit(1);
}

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
