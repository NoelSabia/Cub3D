/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:41:50 by nsabia            #+#    #+#             */
/*   Updated: 2024/06/30 16:41:05 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	floor_and_ceiling_color(t_parsing *parse)
{
	uint8_t red = 80;
    uint8_t green = 255;
    uint8_t blue = 122;
    uint8_t alpha = 255; // Assuming no transparency (fully opaque)
	
	uint8_t red2 = 120;
    uint8_t green2 = 120;
    uint8_t blue2 = 120;
    uint8_t alpha2 = 255; // Assuming no transparency (fully opaque)

    // Pack RGB values into a uint32_t variable (RGBA format)
   parse->ceiling_color = ((uint32_t)red << 24) | ((uint32_t)green << 16) | ((uint32_t)blue << 8) | alpha;
   parse->floor_color = ((uint32_t)red2 << 24) | ((uint32_t)green2 << 16) | ((uint32_t)blue2 << 8) | alpha2;
}
