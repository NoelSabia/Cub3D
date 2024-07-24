/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:30:42 by oemelyan          #+#    #+#             */
/*   Updated: 2024/07/24 13:30:56 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void draw_player (t_mlx *mlx)
{
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->coord_x, mlx->ply->coord_y, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->coord_x + 1, mlx->ply->coord_y, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->coord_x + 2, mlx->ply->coord_y, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->coord_x - 1, mlx->ply->coord_y, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->coord_x - 2, mlx->ply->coord_y, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->coord_x, mlx->ply->coord_y + 1, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->coord_x, mlx->ply->coord_y - 1, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->coord_x, mlx->ply->coord_y + 2, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->coord_x, mlx->ply->coord_y - 2, 0x00FF00FF);
}

void draw_walls(t_mlx *mlx)
{
	int		i;
	int		j;

	mlx->ray->sq_unit = 64;
	i = 0;
	while (i < mlx->parse->cols)
	{
		j = 0;
		while (j < mlx->parse->rows)
		{
			if (mlx->parse->map[i][j] == '1')
				put_block(mlx, j * 64, i * 64);
			j++;
		}
		j = 0;
		i++;
	}
}
void init_values(t_mlx *mlx)
{
	mlx->ply->map_i = mlx->ply->plyr_y; //they are like coordinates, i means x_axis
	mlx->ply->map_j = mlx->ply->plyr_x; // y_axis, the row index
	mlx->ply->coord_x = mlx->ply->map_i * 64 + 32 + 15; //DELETE +10
	mlx->ply->coord_y = mlx->ply->map_j * 64 + 32 + 10; //DELETE +10
	mlx->ray->alpha = deg_to_rad(mlx->ply->most_right_angle);
	mlx->ply->fov_radians = 0;
	mlx->ray->da = 0;
	mlx->ray->db = 0;
	mlx->ray->d_h = 0;
	mlx->ray->dist_hor_i = 0;
	mlx->ray->dist_vert_i = 0;
	mlx->ray->ray_step = FOV / SCREEN_WIDTH;
	mlx->ray->distance_to_wall = 0;
	mlx->ray->flag_for_wall = 0;
	mlx->ray->x1 = 0;
	mlx->ray->y1 = 0;
}

void	minimap_draw(t_mlx *mlx)
{
	// printf("x_pos: %d\n", mlx->ply->coord_x);
	// printf("y_pos: %d\n", mlx->ply->coord_y);
	// init_values(mlx);
	draw_walls(mlx);
	draw_vert(mlx);
	draw_horiz(mlx);
	draw_player(mlx);
	raycasting(mlx);
}
