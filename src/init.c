/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:15:49 by nsabia            #+#    #+#             */
/*   Updated: 2024/07/01 13:00:35 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void game_loop(void *mlx_copy)
{
    t_mlx *mlx;
    int x;
    int y;

    mlx = mlx_copy;
    mlx_delete_image(mlx->mlx_p, mlx->img);
    mlx->img = mlx_new_image(mlx->mlx_p, SCREEN_WIDTH, SCREEN_HEIGHT);
    y = 0;
    while (y < SCREEN_HEIGHT)
    {
        x = 0;
        while (x < SCREEN_WIDTH)
        {
            if (y <= SCREEN_HEIGHT / 2)
                mlx_put_pixel(mlx->img, x, y, 14753280);
            else
                mlx_put_pixel(mlx->img, x, y, 14753280);
            x++;
        }
        y++;
    }
    // raycasting(mlx);
}

void	init(t_mlx *mlx, t_parsing *parse)
{
	// mlx->ply->plyr_x = parse->player_x * TILE_SIZE + TILE_SIZE / 2;
	// mlx->ply->plyr_y = parse->player_y * TILE_SIZE + TILE_SIZE / 2;
	// mlx->ply->fov_radians = (FOV * M_PI) / 180;
	// mlx->ply->angle = M_PI;
	floor_and_ceiling_color(parse);
	mlx_loop_hook(mlx->mlx_p, &game_loop, mlx);
	// mlx_key_hook(mlx->mlx_p, &keyhook_organizer, &mlx);
	mlx_loop(mlx->mlx_p);
}
