/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_determ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:08:19 by oemelyan          #+#    #+#             */
/*   Updated: 2024/08/09 14:16:59 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void draw_wall(t_mlx *mlx, int *step)
{
	printf("--draw wall--\n");
	int		start;

	start = mlx->ray->top_wall_y;
	if (mlx->ray->top_wall_y < 0)
		mlx->ray->top_wall_y = 0;
	else if (mlx->ray->bottom_wall_y > SCREEN_HEIGHT - 1)
		mlx->ray->bottom_wall_y = SCREEN_HEIGHT - 1;



	while(start <= mlx->ray->bottom_wall_y)
	{
		printf("put pixel coord: [%d][%d]\n", *step, start);
		mlx_put_pixel(mlx->img, *step, start, 0x00FF00FF);
		start++;
	}
	printf("--draw wall ends--\n");
	return ;
}

void dist_to_wall(t_mlx *mlx)
{
	mlx->ray->dtpp = (SCREEN_WIDTH / 2) / (fabs(tan(FOV / 2))); //distance to the projection plane
	//printf("the dist to the projection plane is: %f\n", mlx->ray->dtpp);

	//printf("distance to wall: %f\n", mlx->ray->distance_to_wall);
	mlx->ray->wall_height = (64 / mlx->ray->distance_to_wall) * mlx->ray->dtpp;
	mlx->ray->top_wall_y = 539 - (mlx->ray->wall_height / 2) + 1;
	mlx->ray->bottom_wall_y = 539 + (mlx->ray->wall_height / 2);
	printf("\n\n****************** WALL ********************\n\n");
	printf("the wall height: %f, top coordinate: %d, bottom coordinate: %d\n", mlx->ray->wall_height, mlx->ray->top_wall_y, mlx->ray->bottom_wall_y);
	printf("\n\n**************************************\n\n");

}