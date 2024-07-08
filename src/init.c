/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:15:49 by nsabia            #+#    #+#             */
/*   Updated: 2024/07/08 17:07:10 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void game_loop(void *mlx_copy)
{
    t_mlx *mlx;

    mlx = mlx_copy;
    mlx_delete_image(mlx->mlx_p, mlx->img);
    // mlx->img = mlx_new_image(mlx->mlx_p, SCREEN_WIDTH, SCREEN_HEIGHT);
    // mlx_image_to_window(mlx->mlx_p, mlx->img, 0, 0);
    // floor_and_ceiling_color_display(mlx);
    // raycasting(mlx);
    mlx->ray->minimap = mlx_new_image(mlx->mlx_p, 64*(mlx->parse->rows + 1), 64*(mlx->parse->cols + 1));
    mlx_image_to_window(mlx->mlx_p, mlx->ray->minimap, 0, 0);
    minimap_draw(mlx);
}

void	init(t_mlx *mlx)
{
    mlx->ply->plyr_x = mlx->parse->x;
    mlx->ply->plyr_y = mlx->parse->y;
	mlx->ply->fov_radians = (FOV * M_PI) / 180;
	mlx->ply->angle = M_PI;
	floor_and_ceiling_color(mlx);
	mlx_loop_hook(mlx->mlx_p, &game_loop, mlx);
	mlx_key_hook(mlx->mlx_p, &keyhook_organizer, mlx);
	mlx_loop(mlx->mlx_p);
}
