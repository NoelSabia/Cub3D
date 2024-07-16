/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:57:52 by nsabia            #+#    #+#             */
/*   Updated: 2024/07/16 22:06:19 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float ft_abs2(float a)
{
	if (a < 0)
		return (a * (-1));
	return a;
}

float deg_to_rad(int angle)
{
	return angle * (M_PI / 180);
}

void draw_inter(t_mlx *mlx, float x, float y)
{
	printf("draw inter\n");
	//to limit drawing with boundaries of the map
	mlx_put_pixel(mlx->ray->minimap, x, y, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, x + 1, y, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, x + 2, y, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, x - 1, y, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, x - 2, y, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, x, y + 1, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, x, y - 1, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, x, y + 2, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, x, y - 2, 0x00FF00FF);
}

void angles_correction(t_mlx *mlx)
{
	if (mlx->ply->angle == 0)
	{
		mlx->ply->most_left_angle = 30;
		mlx->ply->most_right_angle = 330;
	}
}
void angles_update (t_mlx *mlx)
{
	mlx->ply->most_left_angle = mlx->ply->angle + 30;
	mlx->ply->most_right_angle = mlx->ply->angle - 30;
}

void	minimap_draw_line(t_mlx *mlx, float x_coord, float y_coord)
{
	int dx;
    int dy;
    int sx;
    int sy;
    int err;
    int e2;
	int width;
	int height;

	width = 64*(mlx->parse->rows + 1);
	height = 64*(mlx->parse->cols + 1);
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
		printf("***draw line check***\n");
		if (mlx->ply->coord_x >= 0 && mlx->ply->coord_x < width
            && mlx->ply->coord_y >= 0 && mlx->ply->coord_y < height) //corrected width and height
			mlx_put_pixel(mlx->ray->minimap, mlx->ply->coord_x, mlx->ply->coord_y, 0x00FF00FF); //corrected img of minimap
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

void	raycasting(t_mlx *mlx)
{
	//int		i;

	mlx->ply->most_right_angle = 70;
	mlx->ray->alpha = deg_to_rad(70); //DELETE
	//angles_update(mlx); //at some point when the player changes the angle
	angles_correction(mlx);

	// i = 0;
	// while (i < 5)
	// {
	// 	mlx->ray->alpha = deg_to_rad(mlx->ply->most_right_angle);
	// 	if (mlx->ply->most_right_angle == 0 || mlx->ply->most_right_angle == 360 \
	// 	|| mlx->ply->most_right_angle == 90 || mlx->ply->most_right_angle  == 180 \
	// 	|| mlx->ply->most_right_angle == 270)
	// 		specific_intersections(mlx);
	// 	else
	// 	{
	// 		vert_inter(mlx);
	// 		horiz_inter(mlx);
	// 		choose_min_dist(mlx);
	// 	}
	// 	//draw the line function
	// 	mlx->ply->most_right_angle += 5;
	// 	i++;
	// }

	if (mlx->ply->most_right_angle == 0 || mlx->ply->most_right_angle == 360 \
	|| mlx->ply->most_right_angle == 90 || mlx->ply->most_right_angle  == 180 \
	|| mlx->ply->most_right_angle == 270)
		specific_intersections(mlx);
	else
	{
		vert_inter(mlx);
		horiz_inter(mlx);
		choose_min_dist(mlx);
	}
	printf("coord*** [%f][%f]\n", mlx->ray->wall_x, mlx->ray->wall_y);
	printf("player coord: [%d][%d]\n", mlx->ply->coord_x, mlx->ply->coord_y);
	minimap_draw_line(mlx, mlx->ray->wall_y, mlx->ray->wall_x);

}
