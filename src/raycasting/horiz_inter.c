/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horiz_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:35:26 by oemelyan          #+#    #+#             */
/*   Updated: 2024/07/15 23:43:42 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void first_hor_inter(t_mlx *mlx)
{
	if (mlx->ray->alpha < M_PI)
		mlx->ray->db = fmod(mlx->ply->coord_x, 64);
	else
		mlx->ray->db = 64 - fmod(mlx->ply->coord_x, 64);
	printf("coord of plr: [%d][%d], db is: %f\n", mlx->ply->coord_x, mlx->ply->coord_y, mlx->ray->db);
	mlx->ray->da = ft_abs(mlx->ray->db / tan(mlx->ray->alpha));
	printf("da is: %f\n", mlx->ray->da);
	mlx->ray->d_h = ft_abs(mlx->ray->db / sin(mlx->ray->alpha));
	if (mlx->ray->alpha < M_PI / 2 || mlx->ray->alpha > 3 * M_PI / 2)
		mlx->ray->x1 = mlx->ply->coord_x + mlx->ray->da;
	else
		mlx->ray->x1 = mlx->ply->coord_x - mlx->ray->da;
	printf("x1 check: %f\n", mlx->ray->x1);
	if (mlx->ray->alpha < M_PI)
		mlx->ray->y1 = mlx->ply->coord_y - mlx->ray->db;
	else
		mlx->ray->y1 = mlx->ply->coord_y + mlx->ray->db;
	mlx->ray->dist_hor_i += mlx->ray->d_h;
	if (out_check(mlx) == 1)
		return ;
	draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
}

void next_hor_i(t_mlx *mlx)
{
	mlx->ray->db = 64;
	mlx->ray->da = ft_abs(mlx->ray->db / tan(mlx->ray->alpha));
	mlx->ray->d_h = ft_abs(mlx->ray->db / sin(mlx->ray->alpha));
	mlx->ray->dist_hor_i += mlx->ray->d_h;
	if (mlx->ray->alpha < M_PI / 2 || mlx->ray->alpha > 3 * M_PI / 2)
		mlx->ray->x1 += mlx->ray->da;
	else
		mlx->ray->x1 -= mlx->ray->da;
	if (mlx->ray->alpha < M_PI)
		mlx->ray->y1 -= mlx->ray->db;
	else
		mlx->ray->y1 += mlx->ray->db;
}

void horiz_inter(t_mlx *mlx)
{
	printf("horiz inter start\n");
	//mlx->ray->alpha = deg_to_rad(100); //DELETE
	//mlx->ray->alpha2 = deg_to_rad(90 - FOV / 2);
	first_hor_inter(mlx);
	while (1)
	{
		if (check_if_wall_h(mlx, mlx->ray->x1, mlx->ray->y1) == 1)
		{
			mlx->ray->hor_x_wall = mlx->ray->x1;
			mlx->ray->hor_y_wall = mlx->ray->y1;
			return;
		}
			next_hor_i(mlx);
			if (out_check(mlx) == 1)
				return ;
			draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
	}
}