/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:52:10 by nsabia            #+#    #+#             */
/*   Updated: 2024/07/15 17:59:59 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	minimap_draw_line(t_mlx *mlx, float x_coord, float y_coord)
{
	int dx;
    int dy;
    int sx;
    int sy;
    int err;
    int e2;

    dx = ft_abs((int)x_coord - mlx->ply->coord_x);
    dy = ft_abs((int)y_coord - mlx->ply->coord_y);
    if (mlx->ply->coord_x < (int)x_coord)
        sx = 1;
    else
        sx = -1;
    if (mlx->ply->coord_y < (int)y_coord)
        sy = -1;
    else
        sy = 1;
    err = dx - dy;
    while (1)
	{
		if (mlx->ply->coord_x >= 0 && mlx->ply->coord_x < SCREEN_WIDTH
            && mlx->ply->coord_y >= 0 && mlx->ply->coord_y < SCREEN_HEIGHT)
			mlx_put_pixel(mlx->img, mlx->ply->coord_x,
                mlx->ply->coord_y, 0x00FF00FF);
		if (mlx->ply->coord_x == (int)x_coord
            && mlx->ply->coord_y == (int)y_coord)
			break;
        e2 = err * 2;
        if (e2 > -dy)
		{
            err -= dy;
            mlx->ply->coord_x += sx;
        }
        if (e2 < dx)
		{
            err += dx;
            mlx->ply->coord_y -= sy;
        }
    }
}
