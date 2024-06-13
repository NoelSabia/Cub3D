/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:15:49 by nsabia            #+#    #+#             */
/*   Updated: 2024/06/13 13:40:08 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	game_loop(void	*mlx_copy)
{
	t_mlx	*mlx;

	mlx = mlx_copy;
	mlx_delete_image(mlx->mlx_p, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx_p, SCREEN_WIDTH, SCREEN_HEIGHT);
	raycasting(mlx);
	mlx_image_to_window(mlx->mlx_p, mlx->img, 0, 0);
}

void	init(t_mlx *mlx, t_parsing *parse)
{
	mlx->ply->plyr_x = parse->player_x * TILE_SIZE + TILE_SIZE / 2;
	mlx->ply->plyr_y = parse->player_y * TILE_SIZE + TILE_SIZE / 2;
	mlx->ply->fov_radians = (FOV * M_PI) / 180;
	printf("%f\n", mlx->ply->fov_radians);
	mlx->ply->angle = M_PI;
	mlx_loop_hook(mlx->mlx_p, &game_loop, mlx);
	// mlx_key_hook(mlx->mlx_p, &keyhook_organizer, &mlx);
	mlx_loop(mlx->mlx_p);
}
