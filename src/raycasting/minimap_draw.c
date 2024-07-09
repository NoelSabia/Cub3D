/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:08:06 by oemelyan          #+#    #+#             */
/*   Updated: 2024/07/09 10:08:42 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//rows and cols show the index, not a number, it's one less and they are mixed
void put_block(t_mlx *mlx, int i, int j)
{
	int		i_end;
	int		j_end;
	int		j_zero;

	j_zero = j;
	i_end = i + 64;
	j_end = j + 64;
	//printf("i_start: %d, i_end: %d, j_start: %d, j_end: %d, j_zero: %d\n", i, i_end, j, j_end, j_zero);
	while (i < i_end)
	{
		while (j < j_end)
		{
			//printf("coordinates to put pixel: [%d][%d]\n", i, j);
			mlx_put_pixel(mlx->ray->minimap, i, j, 0xFF00FFFF);
			j++;
		}
		j = j_zero;
		i++;
	}

}

void draw_vert (t_mlx *mlx)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 1;
	while (k < (mlx->parse->rows))
	{
		while (i < 64 * (mlx->parse->cols))
		{
			mlx_put_pixel(mlx->ray->minimap, 64*j, i, 0xFF00FFFF);
			i++;
		}
		i = 0;
		j++;
		k++;
	}
}

void draw_horiz (t_mlx *mlx)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 1;
	while (k < (mlx->parse->cols))
	{
		while (i < 64 * (mlx->parse->rows))
		{
			mlx_put_pixel(mlx->ray->minimap, i, 64 * j, 0xFF00FFFF);
			i++;
		}
		i = 0;
		j++;
		k++;
	}
}