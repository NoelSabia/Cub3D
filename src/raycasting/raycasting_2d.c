/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:57:52 by nsabia            #+#    #+#             */
/*   Updated: 2024/07/24 16:25:35 by oemelyan         ###   ########.fr       */
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
	printf("\n\ndraw inter\n");
	printf("coordinates passed: %f, %f\n", x, y);
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
	int that_x;
	int that_y;

	that_x = mlx->ply->coord_x;
	that_y = mlx->ply->coord_y;
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
		if (that_x >= 0 && that_x < width
            && that_y >= 0 && that_y < height) //corrected width and height
			mlx_put_pixel(mlx->ray->minimap, that_x, that_y, 0x00FF00FF); //corrected img of minimap
		if (that_x == (int)x_coord
            && that_y == (int)y_coord)
			break;
        e2 = err * 2;
        if (e2 > -dy)
		{
            err -= dy;
            that_x += sx;
        }
        if (e2 < dx)
		{
            err += dx;
            that_y -= sy;
        }
    }
}
void reinit(t_mlx *mlx)
{
	mlx->ray->da = 0;
	mlx->ray->db = 0;
	mlx->ray->d_h = 0;
	mlx->ray->x1 = mlx->ply->coord_x;
	mlx->ray->y1 = mlx->ply->coord_y;

}
void ray_angle_correction(t_mlx *mlx)
{
	if (mlx->ply->most_right_angle > 360)
		mlx->ply->most_right_angle -= 360;
}

void	raycasting(t_mlx *mlx)
{
	printf("\n*****this updated raycasting****\n");
	int		i;

	mlx->ply->angle = 90;
	//mlx->ray->alpha = deg_to_rad(60); //DELETE
	angles_update(mlx); //at some point when the player changes the angle
	angles_correction(mlx);

	i = 0;
	while (i < 360)
	{
		printf("----i is: %d-----\n", i);
		printf("the angle is: %d\n", mlx->ply->most_right_angle);
		mlx->ray->alpha = deg_to_rad(mlx->ply->most_right_angle);
		if (mlx->ply->most_right_angle == 0 || mlx->ply->most_right_angle == 360 \
		|| mlx->ply->most_right_angle == 90 || mlx->ply->most_right_angle  == 180 \
		|| mlx->ply->most_right_angle == 270)
			specific_intersections(mlx);
		else
		{
			vert_inter(mlx);
			reinit(mlx);
			horiz_inter(mlx);
			choose_min_dist(mlx);
			reinit(mlx);
			mlx->ray->dist_vert_i = 0;
			mlx->ray->dist_hor_i = 0;
		}
		minimap_draw_line(mlx, mlx->ray->wall_x, mlx->ray->wall_y);
		mlx->ply->most_right_angle += 1;
		ray_angle_correction(mlx);
		i++;
	}
}
