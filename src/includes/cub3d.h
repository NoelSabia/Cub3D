/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 01:07:58 by nsabia            #+#    #+#             */
/*   Updated: 2024/06/11 16:36:03 by nsabia           ###   ########.fr       */
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

# include "../../libft/libft.h"
# include "../../MLX42/include/MLX42/MLX42.h"

/*Defines*/
# define SCREEN_WIDTH 1900
# define SCREEN_HEIGHT 1000
# define TILE_SIZE 30
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
	float	fov_radius;
	int		rotation;
	int		left_or_right;
	int		up_or_down;
}	t_player;


/*Raycasting functions and structs*/
typedef struct s_ray
{
	double	ray_angle;
	double	distance_to_wall;
	int		flag_for_wall;
}	t_ray;

/*with parse you have access to parse->map(2d) or
parse->map_widht(rows) or parse->map_height*/
typedef struct s_data
{
	t_parsing	*parse;
	int		player_x;
	int		player_y;
}	t_data;

typedef struct s_mlx
{
	mlx_image_t		*img;
	mlx_t			*mlx_p;
	t_ray			*ray;
	t_data			*dt;
	t_player		*ply;
}	t_mlx;

/*Walls funcitons and structs*/

/*Main*/
void	clean_exit(char *str);

#endif
