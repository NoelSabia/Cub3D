/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:10:10 by nsabia            #+#    #+#             */
/*   Updated: 2024/07/03 17:11:05 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	esc_key(mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_free_all();
		exit (0);
	}
}

void	walk_and_look_around(mlx_key_data_t keydata, t_mlx *mlx)
{
	if (mlx_is_key_down(mlx->mlx_p, MLX_KEY_W))
	{
		mlx->ply->plyr_inside_tile_y += PLAYER_SPEED;
		if (mlx->ply->plyr_inside_tile_y > 50)
		{
			mlx->ply->plyr_inside_tile_y = -50;
			mlx->ply->plyr_y++;
		}
	}
	else if (mlx_is_key_down(mlx->mlx_p, MLX_KEY_S))
	{
		mlx->ply->plyr_inside_tile_y -= PLAYER_SPEED;
		if (mlx->ply->plyr_inside_tile_y < -50)
		{
			mlx->ply->plyr_inside_tile_y = 50;
			mlx->ply->plyr_y--;
		}
	}
	else if (mlx_is_key_down(mlx->mlx_p, MLX_KEY_D))
	{
		mlx->ply->plyr_inside_tile_x += PLAYER_SPEED;
		if (mlx->ply->plyr_inside_tile_x > 50)
		{
			mlx->ply->plyr_inside_tile_x = -50;
			mlx->ply->plyr_x++;
		}
	}
	else if (mlx_is_key_down(mlx->mlx_p, MLX_KEY_A))
	{
		mlx->ply->plyr_inside_tile_x -= PLAYER_SPEED;
		if (mlx->ply->plyr_inside_tile_x < -50)
		{
			mlx->ply->plyr_inside_tile_x = 50;
			mlx->ply->plyr_x--;
		}
	}
	else if (mlx_is_key_down(mlx->mlx_p, MLX_KEY_LEFT))
		printf("left\n");
	else if (mlx_is_key_down(mlx->mlx_p, MLX_KEY_RIGHT))
		printf("right\n");
}

void	*keyhook_organizer(mlx_key_data_t keydata, void *mlx_copy)
{
	t_mlx *mlx;

	mlx = mlx_copy;
	esc_key(keydata);
	walk_and_look_around(keydata, mlx);
	return (0);
}
