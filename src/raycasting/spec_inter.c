/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:31:04 by oemelyan          #+#    #+#             */
/*   Updated: 2024/08/09 11:23:33 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//copy functions

int out_check(t_mlx *mlx)
{
	printf("out check\n");
	// printf("coordinates: x1: %f, y1: %f, width %d\n", mlx->ray->x1, mlx->ray->y1, mlx->parse->rows * 64);
	if (mlx->ray->x1 < 0 || mlx->ray->x1 > mlx->parse->rows * 64)
	{
		printf("out check: KO\n");
		return (1);
	}
	else if (mlx->ray->y1 < 0 || mlx->ray->y1 > mlx->parse->cols * 64)
	{
		printf("out check: KO\n");
		return (1);
	}
	printf("out check: OK\n");
	return (0);
}

int check_if_wall_v_s(t_mlx *mlx)
{
	printf("\n--check wall v_s--\n");
	int		i1;
	int		j1;

	j1 = 0;
	j1 = mlx->ray->x1 / TILE_SIZE;
	i1 = mlx->ray->y1 / TILE_SIZE;
	printf("passed coordinates of inter: y1: %f, x1: %f\n", mlx->ray->y1, mlx->ray->x1);
	printf("map indexes: [%d][%d]\n", i1, j1);
	if (j1 == mlx->parse->rows || i1 == mlx->parse->cols || i1 < 0 || j1 < 0)
	{
		printf("reached the last row or colummn\n");
		return(1);
	}
	printf("map [%d][%d], map char %c\n", i1, j1, mlx->parse->map[i1][j1]);
	if (mlx->parse->map[i1][j1] == '1')
	{
		printf("yes, wall\n");
		return (1);
	}
	printf("---check if wall end---\n");
	return (0);
}

int	check_if_wall_h_s(t_mlx *mlx)
{
	printf("\n---check if wall h_s start---\n\n");
	int		i1;
	int		j1;

	i1 = 0;
	printf("y1: %f, x1: %f\n", mlx->ray->y1, mlx->ray->x1);
	i1 = mlx->ray->y1 / TILE_SIZE;
	j1 = mlx->ray->x1 / TILE_SIZE;

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

//main part
void intersec_zero(t_mlx *mlx)
{
	mlx->ray->x1 = (mlx->ply->map_i + 1) * 64;
	mlx->ray->y1 = mlx->ply->coord_y;
	mlx->ray->d_h = 64 - fmod(mlx->ply->coord_x, 64);
	mlx->ray->distance_to_wall = mlx->ray->d_h;
	if (out_check(mlx) == 1)
		return ;
	//draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
	while (1)
	{
		if (check_if_wall_v_s(mlx) == 1)
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
		//draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
	}
}

void intersec_90(t_mlx *mlx)
{
	printf("intersec 90\n");
	printf("player's position: [%d][%d]\n", mlx->ply->map_j, mlx->ply->map_i);
	mlx->ray->x1 = mlx->ply->coord_x;
	mlx->ray->y1 = (mlx->ply->map_j) * 64 - 1;
	printf("y1 for first inter: %f\n", mlx->ray->y1);
	mlx->ray->distance_to_wall = fmod(mlx->ply->coord_y, 64);
	if (out_check(mlx) == 1)
		return ;
	printf("coord for inter: [%f][%f]\n", mlx->ray->x1, mlx->ray->y1);
	//draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
	while (1)
	{
		if (check_if_wall_h_s(mlx) == 1)
		{
			mlx->ray->wall_x = mlx->ray->x1;
			mlx->ray->wall_y = mlx->ray->y1;
			return;
		}
		mlx->ray->y1 -= TILE_SIZE;	//
		mlx->ray->distance_to_wall += TILE_SIZE;
		if (out_check(mlx) == 1)
			return ;
		//draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
	}
}

void intersec_180(t_mlx *mlx)
{
	printf("intersec 180\n");
	mlx->ray->x1 = (mlx->ply->map_i) * TILE_SIZE - 1;
	mlx->ray->y1 = mlx->ply->coord_y;
	mlx->ray->distance_to_wall = fmod(mlx->ply->coord_x, TILE_SIZE);
	if (out_check(mlx) == 1)
		return ;
	//draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
	while (1)
	{
		if (check_if_wall_v_s(mlx) == 1)
		{
			mlx->ray->wall_x = mlx->ray->x1;
			mlx->ray->wall_y = mlx->ray->y1;
			return;
		}
		mlx->ray->x1 -= TILE_SIZE;

		mlx->ray->distance_to_wall += TILE_SIZE;
		if (out_check(mlx) == 1)
			return ;
		//draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
	}
}

void intersec_270(t_mlx *mlx)
{
	printf("intersec 270\n");
	mlx->ray->x1 = mlx->ply->coord_x;
	mlx->ray->y1 = (mlx->ply->map_j + 1) * 64; //first inter
	mlx->ray->d_h = 64 - fmod(mlx->ply->coord_y, 64);
	mlx->ray->distance_to_wall = mlx->ray->d_h;
	if (out_check(mlx) == 1)
		return ;
	printf("coord for inter: [%f][%f]\n", mlx->ray->x1, mlx->ray->y1);
	//draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
	while (1)
	{
		if (check_if_wall_h_s(mlx) == 1)
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
		//draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
	}
}

void	specific_intersections(t_mlx *mlx)
{
	printf("--specific intersection--\n");
	printf("the plr coord: [%d][%d]\n", mlx->ply->coord_x, mlx->ply->coord_y);
	if (mlx->ply->most_right_angle == 0.0 || mlx->ply->most_right_angle == 360.0)
		intersec_zero(mlx);
	else if (mlx->ply->most_right_angle == 90.0)
		intersec_90(mlx);
	else if (mlx->ply->most_right_angle == 180.0)
		intersec_180(mlx);
	else if (mlx->ply->most_right_angle == 270.0)
		intersec_270(mlx);
	//minimap_draw_line(mlx, mlx->ray->wall_x, mlx->ray->wall_y);
	reinit(mlx);
	printf("coordinates of inter: [%f][%f], distance: %f\n", mlx->ray->wall_x, mlx->ray->wall_y, mlx->ray->distance_to_wall);
}