/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horiz_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:35:26 by oemelyan          #+#    #+#             */
/*   Updated: 2024/08/09 10:36:07 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void change_h_values(t_mlx *mlx)
{
	printf("\n changing da, db, dh to repeated\n");
	mlx->ray->db = TILE_SIZE;
	mlx->ray->da = TILE_SIZE / fabs(tan(mlx->ray->alpha));
	mlx->ray->d_h = sqrt(mlx->ray->db * mlx->ray->db  + mlx->ray->da * mlx->ray->da);
	printf("\nconstant da: %f, db: %f, dh: %f\n", mlx->ray->da, mlx->ray->db, mlx->ray->d_h);
}

void first_hor_inter(t_mlx *mlx)
{
	printf("\n---first horiz inter----\n");
	// printf("plr coord: [%d][%d]\n", mlx->ply->coord_x, mlx->ply->coord_y);
	if (mlx->ply->most_right_angle < 180.0 && mlx->ply->most_right_angle > 0.0)
		mlx->ray->db = fmod(mlx->ply->coord_y, 64);
	else
		mlx->ray->db = 64 - fmod(mlx->ply->coord_y, 64);
	mlx->ray->da = fabs(mlx->ray->db / tan(mlx->ray->alpha));
	if (mlx->ply->most_right_angle > 90.0 &&  mlx->ply->most_right_angle < 270.0)
		mlx->ray->x1 = mlx->ply->coord_x - mlx->ray->da;
	else
		mlx->ray->x1 = mlx->ply->coord_x + mlx->ray->da;
	if (mlx->ply->most_right_angle < 180.0 && mlx->ply->most_right_angle > 0.0)
		mlx->ray->y1 = mlx->ply->coord_y - mlx->ray->db;
	else
		mlx->ray->y1 = mlx->ply->coord_y + mlx->ray->db;
	// printf("dh is: %f\n", mlx->ray->d_h);
	// printf("distance to wall horiz: %d\n", mlx->ray->dist_hor_i);
	if (out_check(mlx) == 1)
		return ;
	mlx->ray->d_h = sqrt(mlx->ray->db * mlx->ray->db  + mlx->ray->da * mlx->ray->da);
	mlx->ray->dist_hor_i += mlx->ray->d_h;
	// printf("da is: %f\n", mlx->ray->da);
	// printf("db is: %f\n", mlx->ray->db);
	// printf("dh is: %f\n", mlx->ray->d_h);
	printf("x1: %f, y1: %f\n", mlx->ray->x1, mlx->ray->y1);
	change_h_values(mlx);
}

void next_hor_i(t_mlx *mlx)
{
	printf("\n---next horiz inter---\n");
	mlx->ray->dist_hor_i += mlx->ray->d_h;

	// printf("\n\nmost right angle: %f\n\n", mlx->ply->most_right_angle);
	if (mlx->ply->most_right_angle > 90.0 &&  mlx->ply->most_right_angle < 270.0)
	{
		printf("90 - 180 - 270\n");
		mlx->ray->x1 -= mlx->ray->da;
	}
	else {
		printf("90-0-270\n");
		mlx->ray->x1 += mlx->ray->da;
	}
	if (mlx->ply->most_right_angle < 180.0 && mlx->ply->most_right_angle > 0.0) {
		printf("180-90-0\n");
		mlx->ray->y1 -= mlx->ray->db; }
	else {
		printf("180-270-0\n");
		mlx->ray->y1 += mlx->ray->db; }
	printf("new x1 and y1 coordinates: [%f][%f]\n", mlx->ray->x1, mlx->ray->y1);
	// printf("dist to wall is: %f\n", mlx->ray->dist_vert_i);
	// printf("---next inter end---\n");
}



int	check_if_wall_h(t_mlx *mlx)
{
	printf("----check wall h strarts---\n");
	int		i1;
	int		j1;

	//i1 = 0;
	//printf("y1: %f, x1: %f\n", mlx->ray->y1, mlx->ray->x1); //
	if (mlx->ply->most_right_angle == 45.0 || mlx->ply->most_right_angle == 135.0 || mlx->ply->most_right_angle == 225.0 || mlx->ply->most_right_angle == 315.0)
	{
		printf("yes the corner\n");
		corner_wall(mlx, &i1, &j1);
	}
	else
	{
		if (mlx->ply->most_right_angle > 0.0 && mlx->ply->most_right_angle < 180.0)
			i1 = mlx->ray->y1 / TILE_SIZE - 1;
		else
			i1 = mlx->ray->y1 / TILE_SIZE;
		j1 = mlx->ray->x1 / TILE_SIZE;
	}

	if (i1 == mlx->parse->cols || j1 == mlx->parse->rows || i1 < 0 || j1 < 0)
		return(1);
	printf("the cell: [%d][%d]\n", i1, j1);
	printf("the map char: %c\n", mlx->parse->map[i1][j1]);
	if (mlx->parse->map[i1][j1] == '1')
	{
		printf("yes, the wall\n");
		return (1);
	}
	printf("---check if wall end---\n");
	return (0);
}

void horiz_inter(t_mlx *mlx)
{
	printf("--horiz inter start--\n");
	first_hor_inter(mlx);
	while (1)
	{
		// mlx->ray->dist_hor_i = sqrt(pow((mlx->ply->coord_x - mlx->ray->x1),2)
		// 			+ pow((mlx->ply->coord_y - mlx->ray->y1),2));
		if (out_check(mlx) == 1)
			return ;
		if (check_if_wall_h(mlx) == 1)
		{
			mlx->ray->hor_x_wall = mlx->ray->x1;
			mlx->ray->hor_y_wall = mlx->ray->y1;
			//draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
			return;
		}
		next_hor_i(mlx);

	}
}
