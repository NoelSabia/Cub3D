/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horiz_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:35:26 by oemelyan          #+#    #+#             */
/*   Updated: 2024/07/24 16:05:26 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void change_h_values(t_mlx *mlx)
{
	printf("\n changing da, db, dh to repeated\n");
	mlx->ray->db = 64;
	mlx->ray->da = ft_abs(mlx->ray->db / tan(mlx->ray->alpha));
	mlx->ray->d_h = ft_abs(mlx->ray->db / sin(mlx->ray->alpha));
	printf("\nconstant da: %f, db: %f, dh: %f\n", mlx->ray->da, mlx->ray->db, mlx->ray->d_h);
	printf("da is: %f\n", mlx->ray->da);
	printf("db is: %f\n", mlx->ray->db);
	printf("dh is: %f\n", mlx->ray->d_h);
}

void first_hor_inter(t_mlx *mlx)
{
	printf("\n---first horiz inter----\n");
	printf("plr coord: [%d][%d]\n", mlx->ply->coord_x, mlx->ply->coord_y);
	if (mlx->ray->alpha < M_PI)
		mlx->ray->db = fmod(mlx->ply->coord_y, 64); //changed on y
	else
		mlx->ray->db = 64 - fmod(mlx->ply->coord_y, 64); //changed on y
	mlx->ray->da = ft_abs(mlx->ray->db / tan(mlx->ray->alpha));
	mlx->ray->d_h = ft_abs(mlx->ray->db / sin(mlx->ray->alpha));
	if (mlx->ray->alpha < M_PI / 2 || mlx->ray->alpha > 3 * M_PI / 2)
		mlx->ray->x1 = mlx->ply->coord_x + mlx->ray->da;
	else
		mlx->ray->x1 = mlx->ply->coord_x - mlx->ray->da;
	if (mlx->ray->alpha < M_PI)
		mlx->ray->y1 = mlx->ply->coord_y - mlx->ray->db;
	else
		mlx->ray->y1 = mlx->ply->coord_y + mlx->ray->db;
	mlx->ray->dist_hor_i += mlx->ray->d_h;
	if (out_check(mlx) == 1)
		return ;
	printf("da is: %f\n", mlx->ray->da);
	printf("db is: %f\n", mlx->ray->db);
	printf("dh is: %f\n", mlx->ray->d_h);
	printf("x1: %f, y1: %f", mlx->ray->x1, mlx->ray->y1);
	//draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
	change_h_values(mlx);
}

void next_hor_i(t_mlx *mlx)
{
	printf("\n---next horiz inter---\n");
	mlx->ray->dist_hor_i += mlx->ray->d_h;
	if (mlx->ray->alpha < M_PI / 2 || mlx->ray->alpha > 3 * M_PI / 2)
		mlx->ray->x1 += mlx->ray->da;
	else
		mlx->ray->x1 -= mlx->ray->da;
	if (mlx->ray->alpha < M_PI)
		mlx->ray->y1 -= mlx->ray->db;
	else
		mlx->ray->y1 += mlx->ray->db;
	printf("new x1 and y1 coordinates: [%f][%f]\n", mlx->ray->x1, mlx->ray->y1);
	printf("dist to wall is: %f\n", mlx->ray->dist_vert_i);
	printf("---next inter end---\n");
}

int	check_if_wall_h(t_mlx *mlx)
{
	printf("\n---check if wall start---\n\n");
	int		i1;
	int		j1;
  
	if (mlx->ray->alpha > 0 && mlx->ray->alpha < M_PI)
		i1 = mlx->ray->y1 / 64 - 1;
	else
		i1 = mlx->ray->y1 / 64;
	j1 = mlx->ray->x1 / 64;
	printf("CHECK: i1: %d, rows: %d\n", i1, mlx->parse->cols);
	if (i1 == mlx->parse->cols || j1 == mlx->parse->rows)
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
	printf("\n------horiz inter start------\n");
	first_hor_inter(mlx);
	// mlx->ray->db = 64;
	// mlx->ray->da = ft_abs(mlx->ray->db / tan(mlx->ray->alpha));
	// mlx->ray->d_h = ft_abs(mlx->ray->db / sin(mlx->ray->alpha));
	while (1)
	{
		if (out_check(mlx) == 1)
				return ;
		if (check_if_wall_h(mlx) == 1)
		{
			mlx->ray->hor_x_wall = mlx->ray->x1;
			mlx->ray->hor_y_wall = mlx->ray->y1;
			printf("the last horiz inter: %f, %f\n\n", mlx->ray->hor_x_wall, mlx->ray->hor_y_wall = mlx->ray->y1);
			return;
		}
			next_hor_i(mlx);
			if (out_check(mlx) == 1)
				return ;
			//draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
	}
}