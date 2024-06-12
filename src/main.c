/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 00:47:44 by nsabia            #+#    #+#             */
/*   Updated: 2024/06/11 18:40:54 by nsabia           ###   ########.fr       */
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

void	init_mlx_structs(void)
{
	t_mlx	mlx;

	mlx.ply = ft_calloc(1, sizeof(t_player));
	mlx.ray = ft_calloc(1, sizeof(t_ray));
	mlx.mlx_p = mlx_init(SCREEN_HEIGHT, SCREEN_HEIGHT, "Cub3D", 0);
	init(&mlx);
}

int	main(int argc, char *argv[])
{
	t_parsing	*parse;

	parse = ft_calloc(1, sizeof(t_parsing));
	if (argc < 2 || argc > 2)
		clean_exit("Usage: ./Cub3d <filename>.cub\n");
	parsing(parse, argv[1]);
	init_mlx_structs();
	ft_free_all();
	return (0);
}
