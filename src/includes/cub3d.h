/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 01:07:58 by nsabia            #+#    #+#             */
/*   Updated: 2024/06/13 12:00:59 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include <math.h>

# include "../../libft/libft.h"
# include "../../MLX42/include/MLX42/MLX42.h"

/*Defines*/
# define SCREEN_WIDTH 1900
# define SCREEN_HEIGHT 1000
# define TILE_SIZE 50 
# define FOV 60
# define ROTATION_SPEED 0.045
# define PLAYER_SPEED 4

/*Parsing functions and structs*/
typedef struct s_parsing
{
	char	**input;
	int		input_counter;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	int		north_set;
	int		south_set;
	int		west_set;
	int		east_set;
	int		floor_set;
	int		ceiling_set;
	char	*ceiling;
	char	**map;
	int		x;
	int		y;
	int		rows;
	int		cols;
	int		player_x;
	int		player_y;
}	t_parsing;

void	parsing(t_parsing *parse, char *filename);
void	fill_parse_struct(t_parsing *parse);
void	validate_map(t_parsing *parse);
void	flood_fill_organizer(t_parsing *parse);

/*Player_movement functions and structs*/
typedef struct s_player
{
	int		plyr_x;
	int		plyr_y;
	double	angle;
	float	fov_radians;
	int		rotation;
	int		left_or_right;
	int		up_or_down;
}	t_player;

void	keyhook_organizer(void *mlx_copy);

/*Raycasting functions and structs*/
typedef struct s_ray
{
	double	distance_to_wall;
	int		flag_for_wall;
}	t_ray;

typedef struct s_mlx
{
	mlx_image_t		*img;
	mlx_t			*mlx_p;
	t_ray			*ray;
	t_player		*ply;
}	t_mlx;

void	raycasting(t_mlx *mlx);
void	init(t_mlx *mlx, t_parsing *parse);

/*Walls funcitons and structs*/

/*Main*/
void	clean_exit(char *str);

#endif
