/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:58:45 by oemelyan          #+#    #+#             */
/*   Updated: 2024/07/15 16:33:06 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void first_inter(t_mlx *mlx)
{
	printf("map indexes: [%d][%d]\n", mlx->ply->map_i, mlx->ply->map_j);
	printf("right angle: %d\n", mlx->ply->most_right_angle);
	printf("alpha is: %f, 90 deg: %f, 270 is: %f\n", mlx->ray->alpha, M_PI / 2, M_PI * 3 / 2);
		if ((mlx->ray->alpha < M_PI / 2 && mlx->ray->alpha > 0) \
		|| mlx->ray->alpha < M_PI > 3 * M_PI / 2)
	{
		mlx->ray->da = 64 - fmod(mlx->ply->coord_x, 64);
		printf("positive da, da is : %f\n", mlx->ray->da);
	}
	else
	{
		mlx->ray->da = fmod(mlx->ply->coord_x, 64);
		printf("negative da, da is : %f\n", mlx->ray->da);
	}
	mlx->ray->db = ft_abs2(tan(mlx->ray->alpha) * mlx->ray->da);
	mlx->ray->d_h = ft_abs2(mlx->ray->da / cos(mlx->ray->alpha)); //abs value

	if (mlx->ray->alpha < M_PI / 2 || mlx->ray->alpha > 3 * M_PI / 2)
		mlx->ray->x1 = (mlx->ply->map_i + 1) * 64;
	else
		mlx->ray->x1 = 64 * mlx->ply->map_i;
	if (mlx->ray->alpha < M_PI)
		mlx->ray->y1 = mlx->ply->coord_y - mlx->ray->db;
	else
		mlx->ray->y1 = mlx->ply->coord_y + mlx->ray->db;
	mlx->ray->dist_vert_i += mlx->ray->d_h;
	draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
	printf("the coordinates of first inter are: [%f][%f]\n", mlx->ray->x1, mlx->ray->y1);
}

void next_vert_i(t_mlx *mlx)
{
	mlx->ray->da = 64;
	mlx->ray->db = ft_abs2(tan(mlx->ray->alpha) * mlx->ray->da);
	mlx->ray->d_h = ft_abs2(mlx->ray->da / cos(mlx->ray->alpha)); //abs value
	mlx->ray->dist_vert_i += mlx->ray->d_h;
	if (mlx->ray->alpha < M_PI / 2 || mlx->ray->alpha > 3 * M_PI / 2)
		mlx->ray->x1 += 64;
	else
		mlx->ray->x1 -= 64;
	if (mlx->ray->alpha < M_PI)
		mlx->ray->y1 -= mlx->ray->db;
	else
		mlx->ray->y1 += mlx->ray->db;
}

void vert_inter(t_mlx *mlx)
{
	first_inter(mlx);
	while (1)
	{
		if (check_if_wall_h(mlx, mlx->ray->x1, mlx->ray->y1) == 1)
		{
			mlx->ray->vert_x_wall = mlx->ray->x1;
			mlx->ray->vert_y_wall = mlx->ray->y1;
			return;
		}
		else
		{
			next_vert_i(mlx);
			draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
		}
	}
}
