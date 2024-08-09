/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:30:42 by oemelyan          #+#    #+#             */
/*   Updated: 2024/08/09 13:58:24 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void draw_player (t_mlx *mlx)
{
	//printf("draw player\n");
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
	// printf("draw walls\n");
	int		i;
	int		j;

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
	mlx->ply->coord_x = mlx->ply->map_i * TILE_SIZE + TILE_SIZE / 2; //DELETE
	mlx->ply->coord_y = mlx->ply->map_j * TILE_SIZE + TILE_SIZE / 2; //DELETE


	mlx->ray->da = 0;
	mlx->ray->db = 0;
	mlx->ray->d_h = 0;
	mlx->ray->dist_hor_i = 0;
	mlx->ray->dist_vert_i = 0;
	mlx->ray->distance_to_wall = 0;
	mlx->ray->x1 = 0;
	mlx->ray->y1 = 0;
	mlx->ray->dtpp = 0;
	mlx->ray->wall_height = 0;
}

void	minimap_draw(t_mlx *mlx)
{
	init_values(mlx);
	// draw_walls(mlx);
	// draw_vert(mlx);
	// draw_horiz(mlx);
	// draw_player(mlx);
	raycasting(mlx);
}