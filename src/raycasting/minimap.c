/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:30:42 by oemelyan          #+#    #+#             */
/*   Updated: 2024/07/10 14:13:09 by oemelyan         ###   ########.fr       */
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
	mlx->ply->coord_x = 0;
	mlx->ply->coord_y = 0;
	mlx->ply->coord_x = mlx->ply->plyr_y * 64 + 32;
	mlx->ply->coord_y = mlx->ply->plyr_x * 64 + 32;

	mlx->ply->angle = 0;
	mlx->ply->fov_radians = 0;
	mlx->ray->da = 0;
	mlx->ray->db = 0;
	mlx->ray->d_h = 0;
	mlx->ray->first_ray_angle = 0;
	mlx->ray->ray_step = 0;
	mlx->ray->distance_to_wall = 0;
	mlx->ray->flag_for_wall = 0;
}

void	minimap_draw(t_mlx *mlx)
{
	init_values(mlx);
	draw_walls(mlx);
	draw_vert(mlx);
	draw_horiz(mlx);
	draw_player(mlx);
	//raycasting(mlx);
}