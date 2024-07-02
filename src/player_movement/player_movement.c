/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:10:10 by nsabia            #+#    #+#             */
/*   Updated: 2024/07/02 11:00:48 by nsabia           ###   ########.fr       */
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

void	w_a_s_d(mlx_key_data_t keydata)
{
	(void)keydata;
}

void	arrow_left_arrow_right(mlx_key_data_t keydata)
{
	(void)keydata;
}

void	*keyhook_organizer(mlx_key_data_t keydata)
{
	esc_key(keydata);
	w_a_s_d(keydata);
	arrow_left_arrow_right(keydata);
	return (0);
}
