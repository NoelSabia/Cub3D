/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:58:45 by oemelyan          #+#    #+#             */
/*   Updated: 2024/08/09 10:40:09 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/cub3d.h"

// void change_v_values(t_mlx *mlx)
// {
// 	mlx->ray->da = TILE_SIZE;
// 	mlx->ray->db = TILE_SIZE * fabs(tan(mlx->ray->alpha));
// 	mlx->ray->d_h = sqrt(mlx->ray->db * mlx->ray->db  + mlx->ray->da * mlx->ray->da);
// 	printf("\nconstant da: %f, db: %f\n", mlx->ray->da, mlx->ray->db);
// }

// void first_v_inter(t_mlx *mlx)
// {
// 	printf("\n---first horiz inter----\n");
// 	printf("plr coord: [%d][%d]\n", mlx->ply->coord_x, mlx->ply->coord_y);

// 	if ((mlx->ply->most_right_angle < 90.0 && mlx->ply->most_right_angle > 0.0) \
// 		|| (mlx->ply->most_right_angle > 270.0 && mlx->ply->most_right_angle < 360.0))
// 		mlx->ray->da = TILE_SIZE - fmod(mlx->ply->coord_x, 64);
// 	else
// 		mlx->ray->da = fmod(mlx->ply->coord_x, 64);
// 	mlx->ray->db = fabs(tan(mlx->ray->alpha) * mlx->ray->da);
// 	mlx->ray->d_h = sqrt(mlx->ray->db * mlx->ray->db  + mlx->ray->da * mlx->ray->da);
// 	if (mlx->ply->most_right_angle < 90.0 || mlx->ply->most_right_angle > 270.0)
// 		mlx->ray->x1 = (mlx->ply->map_i + 1) * 64;
// 	else
// 		mlx->ray->x1 = 64 * mlx->ply->map_i;
// 	if (mlx->ply->most_right_angle < 180.0)
// 		mlx->ray->y1 = mlx->ply->coord_y - mlx->ray->db;
// 	else
// 		mlx->ray->y1 = mlx->ply->coord_y + mlx->ray->db;
// 	mlx->ray->dist_vert_i += mlx->ray->d_h;

// 	printf("1st inter coordinates: [%f][%f]\n", mlx->ray->x1, mlx->ray->y1);
// 	// if (!(mlx->ply->most_right_angle > 90.0 && mlx->ply->most_right_angle < 270.0))
// 	// 	mlx->ray->x1 = floor(mlx->ply->coord_x / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
// 	// else
// 	// 	mlx->ray->x1 = floor(mlx->ply->coord_x / TILE_SIZE) * TILE_SIZE;
// 	// mlx->ray->y1 = mlx->ply->coord_y + (mlx->ray->x1 - mlx->ply->coord_x) / tan(mlx->ray->alpha);
// 	// mlx->ray->d_h = sqrt(mlx->ray->db * mlx->ray->db  + mlx->ray->da * mlx->ray->da);
// 	// mlx->ray->dist_hor_i += mlx->ray->d_h;

// 	change_v_values(mlx);
// }
// void next_vert_i(t_mlx *mlx)
// {
// 	printf("\n---next inter---\n");

// 	mlx->ray->dist_vert_i += mlx->ray->d_h;
// 	// printf("dist to wall after sum is: %f\n", mlx->ray->dist_vert_i);
// 	if (mlx->ply->most_right_angle < 90.0 || mlx->ply->most_right_angle > 270.0)
// 		mlx->ray->x1 += mlx->ray->da;
// 	else
// 		mlx->ray->x1 -= mlx->ray->da;
// 	if (mlx->ply->most_right_angle < 180.0 && mlx->ply->most_right_angle > 0.0)
// 		mlx->ray->y1 -= mlx->ray->db;
// 	else
// 		mlx->ray->y1 += mlx->ray->db;
// 	printf("new coordinates: [%f][%f]\n", mlx->ray->x1, mlx->ray->y1);
// 	printf("---next inter end---\n");
// }

// int	check_if_wall_v(t_mlx *mlx)
// {
// 	printf("\n--check wall--\n");
// 	int		i1;
// 	int		j1;

// 	j1 = 0;
// 	if (mlx->ply->most_right_angle < 90.0 && mlx->ply->most_right_angle > 270.0)
// 		j1 = mlx->ray->x1 / TILE_SIZE + 1;
// 	else
// 		j1 = mlx->ray->x1 / TILE_SIZE - 1;
// 	i1 = mlx->ray->y1 / TILE_SIZE;
// 	if (i1 == mlx->parse->cols || j1 == mlx->parse->rows || i1 < 0 || j1 < 0)
// 		return(1);
// 	printf("map [%d][%d], map char %c\n", j1, i1, mlx->parse->map[i1][j1]);
// 	if (mlx->parse->map[i1][j1] == '1') //should it be like that, why negative values passed
// 	{
// 		printf("yes, wall\n");
// 		return (1);
// 	}
// 	return (0);
// }

// void vert_inter(t_mlx *mlx)
// {
// 	printf("--vert inter--\n");

// 	first_v_inter(mlx);
// 	if (out_check(mlx) == 1)
// 		return ;
// 	//draw_inter(mlx, mlx->ray->x1, mlx->ray->y1); //for the first inter
// 	while (1)
// 	{
// 		if (check_if_wall_h(mlx) == 1)
// 		{
// 			mlx->ray->vert_x_wall = mlx->ray->x1;
// 			mlx->ray->vert_y_wall = mlx->ray->y1;
// 			draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
// 			printf("the last vert inter: %f, %f\n\n", mlx->ray->vert_x_wall, mlx->ray->vert_y_wall);
// 			return;
// 		}
// 		next_vert_i(mlx);
// 		if (out_check(mlx) == 1)
// 			return ;
// 	}
// 	mlx->ray->dist_vert_i = sqrt(pow((mlx->ray->x1 - mlx->ply->coord_x), 2) + pow((mlx->ray->y1 - mlx->ply->coord_y), 2)); //the distance formula
// }

#include "../includes/cub3d.h"

// int out_check(t_mlx *mlx)
// {
// 	// printf("out check\n");
// 	// printf("coordinates: x1: %f, y1: %f, width %d\n", mlx->ray->x1, mlx->ray->y1, mlx->parse->rows * 64);
// 	if (mlx->ray->x1 < 0 || mlx->ray->x1 > mlx->parse->rows * 64)
// 	{
// 		// printf("rows: %d, upper x1 limit: %d\n", mlx->parse->cols, mlx->parse->cols * 64);
// 		return (1);
// 	}
// 	else if (mlx->ray->y1 < 0 || mlx->ray->y1 > mlx->parse->cols * 64)
// 		return (1);
// 	// printf("out check: OK\n");
// 	return (0);
// }
void change_v_values(t_mlx *mlx)
{
	// printf("angle alpha: %f\n", mlx->ray->alpha);
	mlx->ray->da = 64;
	mlx->ray->db = 64 * fabs(tan(mlx->ray->alpha));
	mlx->ray->d_h = sqrt(mlx->ray->db * mlx->ray->db  + mlx->ray->da * mlx->ray->da); //abs value
	printf("\nconstant da: %f, db: %f, dh: %f\n", mlx->ray->da, mlx->ray->db, mlx->ray->d_h);
}

void first_inter(t_mlx *mlx)
{
	printf("\n---first vert inter----\n");
	printf("dist to wall before is: %f\n", mlx->ray->dist_vert_i);
	if (mlx->ply->most_right_angle > 90.0 &&  mlx->ply->most_right_angle < 270.0)
	{
		mlx->ray->da = fmod(mlx->ply->coord_x, 64);
		mlx->ray->x1 = mlx->ply->coord_x - fmod(mlx->ply->coord_x, 64);
	}
	else
	{
		mlx->ray->da = 64 - fmod(mlx->ply->coord_x, 64);
		mlx->ray->x1 = mlx->ply->coord_x + (64 - fmod(mlx->ply->coord_x, 64));
	}
	mlx->ray->db = fabs(tan(mlx->ray->alpha) * mlx->ray->da);

	if (mlx->ply->most_right_angle < 180.0 && mlx->ply->most_right_angle > 0.0)
		mlx->ray->y1 = mlx->ply->coord_y - mlx->ray->db;
	else
		mlx->ray->y1 = mlx->ply->coord_y + mlx->ray->db;
	// printf("dist to wall 1st inter after is: %f\n", mlx->ray->dist_vert_i);
	printf("x1: %f, y1: %f\n", mlx->ray->x1, mlx->ray->y1);
	if (out_check(mlx) == 1)
		return ;
	mlx->ray->d_h = sqrt(mlx->ray->db * mlx->ray->db  + mlx->ray->da * mlx->ray->da);
	mlx->ray->dist_vert_i += mlx->ray->d_h;
	//draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
	change_v_values(mlx);
}

void next_vert_i(t_mlx *mlx)
{
	printf("\n---next inter---\n");

	mlx->ray->dist_vert_i += mlx->ray->d_h;
	// printf("dist to wall after sum is: %f\n", mlx->ray->dist_vert_i);
	if (mlx->ply->most_right_angle > 90.0 &&  mlx->ply->most_right_angle < 270.0)
		mlx->ray->x1 -= TILE_SIZE;
	else
		mlx->ray->x1 += TILE_SIZE;
	if (mlx->ply->most_right_angle < 180.0 && mlx->ply->most_right_angle > 0.0)
		mlx->ray->y1 -= mlx->ray->db;
	else
		mlx->ray->y1 += mlx->ray->db;
	printf("new coordinates: [%f][%f]\n", mlx->ray->x1, mlx->ray->y1);
	printf("---next inter end---\n");
}
void	corner_wall(t_mlx *mlx, int *i1, int *j1)
{
	printf("\n--corner wall--\n");
	if (mlx->ply->most_right_angle == 45.0)
	{
		*i1 = mlx->ray->y1 / TILE_SIZE - 1;
		*j1 = mlx->ray->x1 / TILE_SIZE;
		return ;
	}
	else if (mlx->ply->most_right_angle == 135.0)
	{
		*i1 = mlx->ray->y1 / TILE_SIZE - 1;
		*j1 = mlx->ray->x1 / TILE_SIZE - 1;
		return ;
	}
	else if (mlx->ply->most_right_angle == 225.0)
	{
		*i1 = mlx->ray->y1 / TILE_SIZE;
		*j1 = mlx->ray->x1 / TILE_SIZE - 1;
		return ;
	}
	else
	{
		*i1 = mlx->ray->y1 / TILE_SIZE;
		*j1 = mlx->ray->x1 / TILE_SIZE;
		return ;
	}
}

int check_if_wall_v(t_mlx *mlx)
{
		printf("----check wall v strarts---\n");
	int		i1;
	int		j1;

	if (mlx->ply->most_right_angle == 45.0 || mlx->ply->most_right_angle == 135.0 || mlx->ply->most_right_angle == 225.0 || mlx->ply->most_right_angle == 315.0)
	{
		printf("yes the corner\n");
		corner_wall(mlx, &i1, &j1);
	}
	else
	{
		if (mlx->ply->most_right_angle > 90.0 && mlx->ply->most_right_angle < 270.0)
			j1 = mlx->ray->x1 / 64 - 1;
		else
			j1 = mlx->ray->x1 / 64;
		i1 = mlx->ray->y1 / 64;
	}

	if (j1 == mlx->parse->rows || i1 == mlx->parse->cols || i1 < 0 || j1 < 0)
		return(1);
	printf("map [%d][%d], map char %c\n", i1, j1, mlx->parse->map[i1][j1]);
	if (i1 > 0 && j1 > 0 && mlx->parse->map[i1][j1] == '1') //should it be like that, why negative values passed
	{
		// printf("yes, wall\n");
		return (1);
	}
	return (0);
}

void vert_inter(t_mlx *mlx)
{
	first_inter(mlx);
	while (1)
	{
		// mlx->ray->dist_vert_i = sqrt(pow(mlx->ray->x1 - mlx->ply->coord_x , 2)
		// 	+ pow(mlx->ray->y1 - mlx->ply->coord_y, 2));
		if (out_check(mlx) == 1)
			return ;
		if (check_if_wall_v(mlx) == 1)
		{
			mlx->ray->vert_x_wall = mlx->ray->x1;
			mlx->ray->vert_y_wall = mlx->ray->y1;
			//minimap_draw_line(mlx, mlx->ray->x1, mlx->ray->y1);
			//draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
			return ;
		}
		next_vert_i(mlx);
	}
}