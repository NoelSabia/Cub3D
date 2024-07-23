/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:10:10 by nsabia            #+#    #+#             */
/*   Updated: 2024/07/23 19:02:37 by nsabia           ###   ########.fr       */
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
	(void)keydata;
	if (mlx_is_key_down(mlx->mlx_p, MLX_KEY_W))
		mlx->ply->coord_y -= PLAYER_SPEED;
	else if (mlx_is_key_down(mlx->mlx_p, MLX_KEY_S))
		mlx->ply->coord_y += PLAYER_SPEED;
	else if (mlx_is_key_down(mlx->mlx_p, MLX_KEY_D))
		mlx->ply->coord_x += PLAYER_SPEED;
	else if (mlx_is_key_down(mlx->mlx_p, MLX_KEY_A))
		mlx->ply->coord_x -= PLAYER_SPEED;
	else if (mlx_is_key_down(mlx->mlx_p, MLX_KEY_LEFT))
	{
		if (mlx->ply->angle + ROTATION_SPEED == 360 + ROTATION_SPEED)
			mlx->ply->angle = 0 + ROTATION_SPEED;
		else
			mlx->ply->angle += ROTATION_SPEED;
		if (mlx->ply->most_left_angle + ROTATION_SPEED == 360 + ROTATION_SPEED)
			mlx->ply->most_left_angle = 0 + ROTATION_SPEED;
		else
			mlx->ply->most_left_angle += ROTATION_SPEED;
		if (mlx->ply->most_right_angle + ROTATION_SPEED == 360 + ROTATION_SPEED)
			mlx->ply->most_right_angle = 0 + ROTATION_SPEED;
		else
			mlx->ply->most_right_angle += ROTATION_SPEED;
	}
	else if (mlx_is_key_down(mlx->mlx_p, MLX_KEY_RIGHT))
	{
		if (mlx->ply->angle - ROTATION_SPEED == 0 - ROTATION_SPEED)
			mlx->ply->angle = 360 - ROTATION_SPEED;
		else
			mlx->ply->angle -= ROTATION_SPEED;
		if (mlx->ply->most_left_angle - ROTATION_SPEED == 0 - ROTATION_SPEED)
			mlx->ply->most_left_angle = 360 - ROTATION_SPEED;
		else
			mlx->ply->most_left_angle -= ROTATION_SPEED;
		if (mlx->ply->most_right_angle - ROTATION_SPEED == 0 - ROTATION_SPEED)
			mlx->ply->most_right_angle = 360 - ROTATION_SPEED;
		else
			mlx->ply->most_right_angle -= ROTATION_SPEED;
	}
}

void	keyhook_organizer(mlx_key_data_t keydata, void *mlx_copy)
{
	t_mlx *mlx;

	mlx = mlx_copy;
		printf("====================================\n");
		printf("mlx->ply->most_left_angle: %d\n", mlx->ply->most_left_angle);
		printf("mlx->ply->angle: %d\n", mlx->ply->angle);
		printf("mlx->ply->most_right_angle: %d\n", mlx->ply->most_right_angle);
		printf("====================================\n");
	esc_key(keydata);
	walk_and_look_around(keydata, mlx);
}
