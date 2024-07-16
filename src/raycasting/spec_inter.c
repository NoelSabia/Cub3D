/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:31:04 by oemelyan          #+#    #+#             */
/*   Updated: 2024/07/16 20:35:08 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//fix distance and coordinates to wall

void intersec_zero(t_mlx *mlx)
{
	mlx->ray->x1 = (mlx->ply->map_i + 1) * 64;
	mlx->ray->y1 = mlx->ply->coord_y;
	mlx->ray->d_h = 64 - fmod(mlx->ply->coord_x, 64);
	mlx->ray->distance_to_wall = mlx->ray->d_h;
	if (out_check(mlx) == 1)
		return ;
	draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
	while (1)
	{
		if (check_if_wall_v(mlx) == 1)
		{
			mlx->ray->wall_x = mlx->ray->x1;
			mlx->ray->wall_y = mlx->ray->y1;
			return;
		}
		mlx->ray->x1 += 64;
		mlx->ray->d_h += 64;
		mlx->ray->distance_to_wall = mlx->ray->d_h;
		if (out_check(mlx) == 1)
			return ;
		draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
	}
}

void intersec_90(t_mlx *mlx)
{
	mlx->ray->x1 = mlx->ply->coord_x;
	mlx->ray->y1 = (mlx->ply->map_j) * 64;
	mlx->ray->d_h = fmod(mlx->ply->coord_y, 64);
	mlx->ray->distance_to_wall = mlx->ray->d_h;
	if (out_check(mlx) == 1)
		return ;
	draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
	while (1)
	{
		if (check_if_wall_h(mlx) == 1)
		{
			mlx->ray->wall_x = mlx->ray->x1;
			mlx->ray->wall_y = mlx->ray->y1;
			return;
		}
		mlx->ray->y1 -= 64;
		mlx->ray->d_h += 64;
		mlx->ray->distance_to_wall = mlx->ray->d_h;
		if (out_check(mlx) == 1)
			return ;
		draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
	}
}

void intersec_180(t_mlx *mlx)
{
	mlx->ray->x1 = (mlx->ply->map_i) * 64;
	mlx->ray->y1 = mlx->ply->coord_y;
	mlx->ray->d_h = fmod(mlx->ply->coord_x, 64);
	mlx->ray->distance_to_wall = mlx->ray->d_h;
	if (out_check(mlx) == 1)
		return ;
	draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
	while (1)
	{
		if (check_if_wall_v(mlx) == 1)
		{
			mlx->ray->wall_x = mlx->ray->x1;
			mlx->ray->wall_y = mlx->ray->y1;
			return;
		}
		mlx->ray->x1 -= 64;
		mlx->ray->d_h += 64;
		mlx->ray->distance_to_wall = mlx->ray->d_h;
		if (out_check(mlx) == 1)
			return ;
		draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
	}
}

void intersec_270(t_mlx *mlx)
{
	mlx->ray->x1 = mlx->ply->coord_x;
	mlx->ray->y1 = (mlx->ply->map_j + 1) * 64;
	mlx->ray->d_h = 64 - fmod(mlx->ply->coord_y, 64);
	mlx->ray->distance_to_wall = mlx->ray->d_h;
	if (out_check(mlx) == 1)
		return ;
	draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
	while (1)
	{
		if (check_if_wall_h(mlx) == 1)
		{
			mlx->ray->wall_x = mlx->ray->x1;
			mlx->ray->wall_y = mlx->ray->y1;
			return;
		}
		mlx->ray->y1 += 64;
		mlx->ray->d_h += 64;
		mlx->ray->distance_to_wall = mlx->ray->d_h;
		if (out_check(mlx) == 1)
			return ;
		draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
	}
}

void	specific_intersections(t_mlx *mlx)
{
	printf("--specific intersection--\n");
	if (mlx->ply->most_right_angle == 0 || mlx->ply->most_right_angle == 360)
		intersec_zero(mlx);
	else if (mlx->ply->most_right_angle == 90)
		intersec_90(mlx);
	else if (mlx->ply->most_right_angle == 180)
		intersec_180(mlx);
	else if (mlx->ply->most_right_angle == 270)
		intersec_270(mlx);
	printf("coordinates of inter: [%f][%f], distance: %f\n", mlx->ray->wall_x, mlx->ray->wall_y, mlx->ray->distance_to_wall);
}