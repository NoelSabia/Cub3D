/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:15:49 by nsabia            #+#    #+#             */
/*   Updated: 2024/07/08 17:33:27 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void    floor_and_ceiling_color_display(t_mlx *mlx)
{
    int x;
    int y;
    y = 0;
    while (y < SCREEN_HEIGHT)
    {
        x = 0;
        while (x < SCREEN_WIDTH)
        {
            if (y <= SCREEN_HEIGHT / 2)
                mlx_put_pixel(mlx->img, x, y, mlx->parse->ceiling_color);
            else
                mlx_put_pixel(mlx->img, x, y, mlx->parse->floor_color);
            x++;
        }
        y++;
    }
}

void game_loop(void *mlx_copy)
{
    t_mlx *mlx;

    mlx = mlx_copy;
    mlx_delete_image(mlx->mlx_p, mlx->img);
    mlx->img = mlx_new_image(mlx->mlx_p, SCREEN_WIDTH, SCREEN_HEIGHT);
    mlx_image_to_window(mlx->mlx_p, mlx->img, 0, 0);
    floor_and_ceiling_color_display(mlx);
    // raycasting(mlx);
}

void	init(t_mlx *mlx)
{
	mlx->ply->plyr_x = mlx->parse->x;
    mlx->ply->plyr_y = mlx->parse->y;
	mlx->ply->fov_radians = (FOV * M_PI) / 180;
	floor_and_ceiling_color(mlx);
	mlx_loop_hook(mlx->mlx_p, &game_loop, mlx);
	mlx_key_hook(mlx->mlx_p, &keyhook_organizer, mlx);
	mlx_loop(mlx->mlx_p);
}
