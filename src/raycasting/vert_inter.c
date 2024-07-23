/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:58:45 by oemelyan          #+#    #+#             */
/*   Updated: 2024/07/22 17:54:53 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void calculate_db(t_mlx *mlx)
// {
// 	if (mlx->ray->alpha > M_PI / 2 && mlx->ray->alpha < M_PI)
// 		mlx->ray->db = ft_abs2(tan(M_PI - mlx->ray->alpha) * mlx->ray->da);
// 	else if (mlx->ray->alpha > M_PI && mlx->ray->alpha < M_PI * 3 / 2)
// 		mlx->ray->db = ft_abs2(tan(mlx->ray->alpha - M_PI) * mlx->ray->da);
// 	else if (mlx->ray->alpha > M_PI * 3 / 2 && mlx->ray->alpha < 2 * M_PI)
// 		mlx->ray->db = ft_abs2(tan(mlx->ray->alpha - M_PI * 3 / 2) * mlx->ray->da);
// 	else
// 		mlx->ray->db = ft_abs2(tan(mlx->ray->alpha) * mlx->ray->da);
// }

int out_check(t_mlx *mlx)
{
	// printf("out check\n");
	// printf("coordinates: x1: %f, y1: %f, width %d\n", mlx->ray->x1, mlx->ray->y1, mlx->parse->rows * 64);
	if (mlx->ray->x1 < 0 || mlx->ray->x1 > mlx->parse->rows * 64)
	{
		// printf("rows: %d, upper x1 limit: %d\n", mlx->parse->cols, mlx->parse->cols * 64);
		return (1);
	}
	else if (mlx->ray->y1 < 0 || mlx->ray->y1 > mlx->parse->cols * 64)
		return (1);
	return (0);
}

void first_inter(t_mlx *mlx)
{
	// printf("first vert inter\n");
	if ((mlx->ply->most_right_angle < 90 && mlx->ply->most_right_angle > 0) \
		|| (mlx->ply->most_right_angle > 270 && mlx->ply->most_right_angle < 360))
		mlx->ray->da = 64 - fmod(mlx->ply->coord_x, 64);
	else
		mlx->ray->da = fmod(mlx->ply->coord_x, 64);
	// printf("da is: %f\n", mlx->ray->da);
	mlx->ray->db = fabs(tan(mlx->ray->alpha) * mlx->ray->da);
	// printf("db is: %f\n", mlx->ray->db);
	mlx->ray->d_h = fabs(mlx->ray->da / cos(mlx->ray->alpha)); //abs value
	if (mlx->ply->most_right_angle < 90 || mlx->ply->most_right_angle > 270)
		mlx->ray->x1 = (mlx->ply->map_i + 1) * 64;
	else
		mlx->ray->x1 = 64 * mlx->ply->map_i;
	if (mlx->ply->most_right_angle < 180)
		mlx->ray->y1 = mlx->ply->coord_y - mlx->ray->db;
	else
		mlx->ray->y1 = mlx->ply->coord_y + mlx->ray->db;
	mlx->ray->dist_vert_i += mlx->ray->d_h;
	if (out_check(mlx) == 1)
		return ;
	//draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
}

void next_vert_i(t_mlx *mlx)
{
	// printf("next inter\n");
	// mlx->ray->da = 64;
	// mlx->ray->db = ft_abs2(tan(mlx->ray->alpha) * mlx->ray->da);
	// printf("next db: %f\n", mlx->ray->db);
	// mlx->ray->d_h = ft_abs2(mlx->ray->da / cos(mlx->ray->alpha)); //abs value
	mlx->ray->dist_vert_i += mlx->ray->d_h;
	if (mlx->ray->alpha < M_PI / 2 || mlx->ray->alpha > 3 * M_PI / 2)
		mlx->ray->x1 += 64;
	else
		mlx->ray->x1 -= 64;
	if (mlx->ray->alpha < M_PI)
		mlx->ray->y1 -= mlx->ray->db;
	else
		mlx->ray->y1 += mlx->ray->db;
	// printf("new coordinates: [%f][%f]\n", mlx->ray->x1, mlx->ray->y1);
	// printf("next inter end\n");
}
int check_if_wall_v(t_mlx *mlx)
{
	int		i1;
	int		j1;

	if (mlx->ray->alpha > M_PI / 2 && mlx->ray->alpha < M_PI * 3 / 2)
		j1 = mlx->ray->x1 / 64 - 1;
	else
		j1 = mlx->ray->x1 / 64;
	i1 = mlx->ray->y1 / 64;
	if (j1 == mlx->parse->cols || i1 == mlx->parse->rows)
		return(1);
	// printf("map [%d][%d], map char %c\n", j1, i1, mlx->parse->map[i1][j1]);
	if (i1 > 0 && j1 > 0 && mlx->parse->map[i1][j1] == '1') //should it be like that, why negative values passed
		return (1);
	return (0);
}

void vert_inter(t_mlx *mlx)
{
	// printf("---vert inter starts---\n");
	first_inter(mlx);
	mlx->ray->da = 64;
	mlx->ray->db = ft_abs2(tan(mlx->ray->alpha) * mlx->ray->da);
	mlx->ray->d_h = ft_abs2(mlx->ray->da / cos(mlx->ray->alpha)); //abs value
	while (1)
	{
		if (out_check(mlx) == 1)
				return ;
		if (check_if_wall_v(mlx) == 1)
		{
			mlx->ray->vert_x_wall = mlx->ray->x1;
			mlx->ray->vert_y_wall = mlx->ray->y1;
			return;
		}
			next_vert_i(mlx);
			// if (out_check(mlx) == 1)
			// 	return ;
			//draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
	}
}
