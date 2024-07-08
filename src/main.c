/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 00:47:44 by nsabia            #+#    #+#             */
/*   Updated: 2024/07/08 17:16:47 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	clean_exit(char *str)
{
	printf("Error\n");
	printf("%s", str);
	ft_free_all();
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_mlx	*mlx;


	if (argc < 2 || argc > 2)
		clean_exit("Usage: ./Cub3d <filename>.cub\n");
	mlx = ft_calloc(1, sizeof(t_mlx));
	mlx->parse = ft_calloc(1, sizeof(t_parsing));
	mlx->ply = ft_calloc(1, sizeof(t_player));
	mlx->ray = ft_calloc(1, sizeof(t_raytracing));

	parsing(mlx, argv[1]);
	int 	width = 64 * (mlx->parse->rows);
	int 	height = 64 * (mlx->parse->cols);
	printf("the width: %d, the height %d\n", width, height);
	mlx->mlx_p = mlx_init(width, height, "Cub3D", 0);
	init(mlx);

	ft_free_all();
	return (0);
}
