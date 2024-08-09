/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:57:52 by nsabia            #+#    #+#             */
/*   Updated: 2024/08/09 15:04:35 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void draw_inter(t_mlx *mlx, float x, float y)
{
	printf("draw inter\n");
	//to limit drawing with boundaries of the map
	mlx_put_pixel(mlx->ray->minimap, x, y, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, x + 1, y, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, x + 2, y, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, x - 1, y, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, x - 2, y, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, x, y + 1, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, x, y - 1, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, x, y + 2, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, x, y - 2, 0x00FF00FF);
}

double deg_to_rad(double angle)
{
	return ((angle * M_PI) / 180);
}

void angles_update (t_mlx *mlx)
{
	if (mlx->ply->angle == 0)
		mlx->ply->most_right_angle = 330;
	else
		mlx->ply->most_right_angle = mlx->ply->angle - 30;
}

void angles_correction(t_mlx *mlx)
{
	if (mlx->ply->most_right_angle > 360)
		mlx->ply->most_right_angle -= 360;
}
void reinit(t_mlx *mlx)
{
	mlx->ray->da = 0;
	mlx->ray->db = 0;
	mlx->ray->d_h = 0;
	mlx->ray->x1 = mlx->ply->coord_x;
	mlx->ray->y1 = mlx->ply->coord_y;
}

void	minimap_draw_line(t_mlx *mlx, float x_coord, float y_coord)
{
	int dx;
    int dy;
    int sx;
    int sy;
    int err;
    int e2;
	int width;
	int height;
	int that_x;
	int that_y;

	that_x = mlx->ply->coord_x;
	that_y = mlx->ply->coord_y;
	width = 64*(mlx->parse->rows + 1);
	height = 64*(mlx->parse->cols + 1);
    dx = ft_abs((int)x_coord - mlx->ply->coord_x);
    dy = ft_abs((int)y_coord - mlx->ply->coord_y);
    if (mlx->ply->coord_x < (int)x_coord)
        sx = 1;
    else
        sx = -1;
    if (mlx->ply->coord_y < (int)y_coord)
        sy = -1;
    else
        sy = 1;
    err = dx - dy;
    while (1)
	{
		if (that_x >= 0 && that_x < width
            && that_y >= 0 && that_y < height) //corrected width and height
			mlx_put_pixel(mlx->ray->minimap, that_x, that_y, 0x00FF00FF); //corrected img of minimap
		if (that_x == (int)x_coord
            && that_y == (int)y_coord)
			break;
        e2 = err * 2;
        if (e2 > -dy)
		{
            err -= dy;
            that_x += sx;
        }
        if (e2 < dx)
		{
            err += dx;
            that_y -= sy;
        }
    }
}

void raycasting(t_mlx *mlx)
{
    int     step;
	float	abr;

    abr = ((float)FOV / SCREEN_WIDTH);
	printf("abr is: %f\n", abr);
	// mlx->ply->angle = 180;
	// angles_update(mlx); //to set most right angle
	ft_putstr_fd("player angle: \n", 2);
	ft_putnbr_fd(mlx->ply->angle, 2);
	ft_putstr_fd("\n", 2);

	ft_putstr_fd("player coord: \n", 2);
	ft_putnbr_fd(mlx->ply->coord_x, 2);
	ft_putstr_fd(" ", 2);
	ft_putnbr_fd(mlx->ply->coord_y, 2);
	ft_putstr_fd("\n", 2);

	step = 0;
	printf("Player co-ordinates: %d, %d\n\n", mlx->ply->coord_x, mlx->ply->coord_y);
	mlx->ply->most_right_angle = mlx->ply->angle;
    while(step < SCREEN_WIDTH)
    {
		printf("\n---step number is: %d----\n", step);

		angles_correction(mlx); //in case most right is > 360
		printf("the most right angle is: %f\n", mlx->ply->most_right_angle);
		// if (mlx->ply->most_right_angle == 0.0 || mlx->ply->most_right_angle == 360.0 || mlx->ply->most_right_angle == 90.0 || mlx->ply->most_right_angle == 180.0 || mlx->ply->most_right_angle == 270.0)
		// {
		// 	specific_intersections(mlx);
		// }
		// else
		{
			mlx->ray->alpha = deg_to_rad(mlx->ply->most_right_angle);

			horiz_inter(mlx);
			reinit(mlx);

			vert_inter(mlx);
			choose_min_dist(mlx);
			reinit(mlx);
			mlx->ray->dist_vert_i = 0;
			mlx->ray->dist_hor_i = 0;
			//draw_inter(mlx, mlx->ray->x1, mlx->ray->y1);
			//minimap_draw_line(mlx, mlx->ray->wall_x, mlx->ray->wall_y);

		}
		dist_to_wall(mlx);
		draw_wall(mlx, &step);
        mlx->ply->most_right_angle += abr;
		printf("most right ngl after increase is: %f\n", mlx->ply->most_right_angle);
		step++;
    }
}
