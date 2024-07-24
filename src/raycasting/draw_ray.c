/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:43:47 by oemelyan          #+#    #+#             */
/*   Updated: 2024/07/22 10:24:04 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void choose_min_dist(t_mlx *mlx)
{
	if (mlx->ray->dist_hor_i > mlx->ray->dist_vert_i)
	{
		mlx->ray->distance_to_wall = mlx->ray->dist_vert_i;
		mlx->ray->wall_x = mlx->ray->vert_x_wall;
		mlx->ray->wall_y = mlx->ray->vert_y_wall;
	}
	else
	{
		mlx->ray->distance_to_wall = mlx->ray->dist_hor_i;
		mlx->ray->wall_x = mlx->ray->hor_x_wall;
		mlx->ray->wall_y = mlx->ray->hor_y_wall;
	}
	// printf("final coord are [%f][%f]\n", mlx->ray->wall_x, mlx->ray->wall_y);
	draw_inter(mlx, mlx->ray->wall_x, mlx->ray->wall_y);
}