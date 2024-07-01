/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:10:10 by nsabia            #+#    #+#             */
/*   Updated: 2024/07/01 22:40:41 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	esc_key(mlx_key_data_t *keydata)
{
	if (keydata->key == MLX_KEY_ESCAPE && keydata->action == MLX_PRESS)
	{
		ft_free_all();
		exit (0);
	}
}

void	*keyhook_organizer(void *mlx_copy)
{
	t_mlx *mlx;

	mlx = mlx_copy;
	
	esc_key(mlx->key_data);
	// w_a_s_d(mlx);
	// arrow_left_arrow_right(mlx);
	return (0);
}
