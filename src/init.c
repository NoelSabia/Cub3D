/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:15:49 by nsabia            #+#    #+#             */
/*   Updated: 2024/06/11 19:05:31 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	init(t_mlx *mlx)
{
	mlx->ply->plyr_x = mlx->parse->player_x * TILE_SIZE + TILE_SIZE / 2;
	mlx->ply->plyr_y = mlx->parse->player_y * TILE_SIZE + TILE_SIZE / 2;
	mlx->ply->fov_radius = (FOV * M_PI) / 180;
	mlx->ply->angle = M_PI;
}
