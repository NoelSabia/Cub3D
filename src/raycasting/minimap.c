/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:30:42 by oemelyan          #+#    #+#             */
/*   Updated: 2024/07/09 10:08:47 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void draw_player (t_mlx *mlx)
{
	mlx->ply->coord_x = mlx->ply->plyr_y * 64 + 32;
	mlx->ply->coord_y = mlx->ply->plyr_x * 64 + 32;
	//printf("init values2: [%d][%d]\n", mlx->ply->coord_x, mlx->ply->coord_y);

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
			//printf("%c", mlx->parse->map[i][j]);
			if (mlx->parse->map[i][j] == '1')
				put_block(mlx, j * 64, i * 64);
			j++;
		}
		//printf("\n");
		j = 0;
		i++;
	}
}

void	minimap_draw(t_mlx *mlx)
{
	draw_walls(mlx);
	draw_vert(mlx);
	draw_horiz(mlx);
	draw_player(mlx);
}