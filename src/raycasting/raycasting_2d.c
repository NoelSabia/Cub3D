/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:57:52 by nsabia            #+#    #+#             */
/*   Updated: 2024/07/16 12:00:30 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float ft_abs2(float a)
{
	if (a < 0)
		return (a * (-1));
	return a;
}

int	check_if_wall_h(t_mlx *mlx, int i, int j)
{
	int		i1;
	int		j1;

	if (i % 64 == 0)
		i1 = i / 64 - 1;
	else
		i1 = i / 64;
	if (j % 64 == 0)
		j1 = j / 64 - 1;
	else
		j1 = j / 64;
	printf("check if wall start\n");
	printf("passed coord: %d, %d\n", i, j);

	printf("the cell: [%d][%d]\n", j1, i1);
	printf("the map char: %c\n", mlx->parse->map[j1][i1]);
	if (mlx->parse->map[j1][i1] == '1')
		return (1);
	printf("check if wall end\n");
	return (0);
}

float deg_to_rad(int angle)
{
	return angle * (M_PI / 180);
}

void draw_inter(t_mlx *mlx, float x, float y)
{
	printf("draw inter\n");
	//to limit drawing with boundaries of the map
	mlx_put_pixel(mlx->ray->minimap, x, y, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, x + 1, y, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, x + 2, y, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, x - 1, y, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, x - 2, y, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, x, y + 1, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, x, y - 1, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, x, y + 2, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, x, y - 2, 0x00FF00FF);
}

void angles_correction(t_mlx *mlx)
{
	if (mlx->ply->angle == 0)
	{
		mlx->ply->most_left_angle = 330;
	}
	if (mlx->ray->alpha > 2 * M_PI)
		mlx->ray->alpha -= 2 * M_PI;
}

void	raycasting(t_mlx *mlx)
{
	angles_correction(mlx);
	vert_inter(mlx);

	horiz_inter(mlx);
}
