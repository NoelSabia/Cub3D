/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:43:47 by oemelyan          #+#    #+#             */
/*   Updated: 2024/08/08 23:00:46 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void choose_min_dist(t_mlx *mlx)
{

	printf("Horizontal dist_to_wall from choose dist: %f\n", mlx->ray->dist_hor_i);
	printf("Vertical dist_to_wall from choose dist: %f\n", mlx->ray->dist_vert_i);

	if (mlx->ray->dist_hor_i == 0)
	{
		mlx->ray->distance_to_wall = mlx->ray->dist_vert_i;
	printf("Vertical dist_to_wall from choose dist: %f\n", mlx->ray->distance_to_wall);
		mlx->ray->wall_x = mlx->ray->vert_x_wall;
		mlx->ray->wall_y = mlx->ray->vert_y_wall;
	}
	else if (mlx->ray->dist_vert_i == 0)
	{
		mlx->ray->distance_to_wall = mlx->ray->dist_hor_i;
	printf("Horizontal dist_to_wall from choose dist: %f\n", mlx->ray->distance_to_wall);
		mlx->ray->wall_x = mlx->ray->hor_x_wall;
		mlx->ray->wall_y = mlx->ray->hor_y_wall;
	}
	else if (mlx->ray->dist_hor_i > mlx->ray->dist_vert_i)
	{
		mlx->ray->distance_to_wall = mlx->ray->dist_vert_i;
	printf("Vertical dist_to_wall from choose dist: %f\n", mlx->ray->distance_to_wall);
		mlx->ray->wall_x = mlx->ray->vert_x_wall;
		mlx->ray->wall_y = mlx->ray->vert_y_wall;
	printf("Verticla final coord are [%f][%f]\n", mlx->ray->wall_x, mlx->ray->wall_y);
	}
	else
	{
		mlx->ray->distance_to_wall = mlx->ray->dist_hor_i;
	printf("Horizontal dist_to_wall from choose dist: %f\n", mlx->ray->distance_to_wall);
		mlx->ray->wall_x = mlx->ray->hor_x_wall;
		mlx->ray->wall_y = mlx->ray->hor_y_wall;
	printf("Horizontal final coord are [%f][%f]\n", mlx->ray->wall_x, mlx->ray->wall_y);

	}
	printf("final coord are [%f][%f]\n", mlx->ray->wall_x, mlx->ray->wall_y);
	printf("dist_to_wall from choose dist: %f\n", mlx->ray->distance_to_wall);
	// draw_inter(mlx, mlx->ray->wall_x, mlx->ray->wall_y);
	// minimap_draw_line(mlx, mlx->ray->wall_x, mlx->ray->wall_y);
}