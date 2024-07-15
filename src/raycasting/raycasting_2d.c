/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:57:52 by nsabia            #+#    #+#             */
/*   Updated: 2024/07/15 18:00:56 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	minimap_draw_line(t_mlx *mlx, float x_coord, float y_coord);

float deg_to_rad(int angle)
{
	return angle * (M_PI / 180);
}

void draw_inter(t_mlx *mlx, float x, float y)
{
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

void	raycasting(t_mlx *mlx)
{
	mlx->ply->fov_radians = deg_to_rad(FOV);
	mlx->ply->angle = (M_PI * 3 / 2); //PI/2 shows 90 degree minus the FOV/2 which is 30 so = 60 for each side
	mlx->ray->first_ray_angle = mlx->ply->angle - mlx->ply->fov_radians / 2;
	mlx->ray->ray_step = (mlx->ply->angle + mlx->ply->fov_radians) / SCREEN_WIDTH;

	printf("init values2: [%f][%f]\n", mlx->ply->coord_x, mlx->ply->coord_y);
	mlx->ray->da = 64 * (mlx->ply->plyr_y + 1) - mlx->ply->coord_x; // x and y, what for coordinate
	printf("the y index is: %d, the coordinate is: %f\n", mlx->ply->plyr_y, mlx->ply->coord_x);
	printf("the dx is: %f\n", mlx->ray->da);
	mlx->ray->db = tan(mlx->ray->first_ray_angle) * mlx->ray->da;
	printf("the x index is: %d, the coordinate is: %f\n", mlx->ply->plyr_x, mlx->ply->coord_y);
	printf("the dy is: %f\n", mlx->ray->db);
	mlx->ray->d_h = mlx->ray->da / cos(mlx->ray->first_ray_angle);
	printf("the distance is: %f\n", mlx->ray->d_h);

	float x1;
	float y1;

	x1 = (mlx->ply->plyr_y + 1) * 64;
	y1 = mlx->ply->coord_y - mlx->ray->db;
	printf("the new coordinates are: [%f][%f]\n", x1, y1);
	draw_inter(mlx, x1, y1);
	minimap_draw_line(mlx, x1, y1);
}
