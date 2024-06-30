/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:57:52 by nsabia            #+#    #+#             */
/*   Updated: 2024/06/30 12:08:09 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	raycasting(t_mlx *mlx)
{
	double	intersection_x;
	double	intersection_y;
	int		i;

	i = 0;
	intersection_x = 0;
	intersection_y = 0;
	mlx->ply->angle = (M_PI / 2) - FOV / 2; //PI/2 shows 90 degree minus the FOV/2 which is 30 so = 60 for each side
	while (i < SCREEN_WIDTH)
	{
		intersection_x = get_intersection_x
		break;
	}
}
