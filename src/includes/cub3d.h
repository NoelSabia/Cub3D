/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 01:07:58 by nsabia            #+#    #+#             */
/*   Updated: 2024/07/03 17:15:29 by nsabia           ###   ########.fr       */
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
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define TILE_SIZE 50
# define FOV 60
# define ROTATION_SPEED 0.045
# define PLAYER_SPEED 10

/*Parsing functions and structs*/
typedef struct s_parsing
{
	char		**input;
	int			input_counter;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*floor;
	char		*ceiling;
	int			north_set;
	int			south_set;
	int			west_set;
	int			east_set;
	int			floor_set;
	int			ceiling_set;
	uint32_t	floor_color;
	uint32_t	ceiling_color;
	char		**map;
	int			x;
	int			y;
	int			rows;
	int			cols;
	int			player_x;
	int			player_y;
}	t_parsing;


/*Player_movement functions and structs*/
typedef struct s_player
{
	int		plyr_x;
	int		plyr_y;
	int		plyr_inside_tile_x;
	int		plyr_inside_tile_y;
	double	angle;
	float	fov_radians;
	int		rotation;
	int		left_or_right;
	int		up_or_down;
}	t_player;

void	*keyhook_organizer(mlx_key_data_t keydata, void *mlx);

/*Raycasting functions and structs*/
typedef struct s_raytracing
{
	double	distance_to_wall;
	int		flag_for_wall;
}	t_raytracing;

typedef struct s_mlx
{
	mlx_image_t		*img;
	mlx_t			*mlx_p;
	t_raytracing	*ray;
	t_player		*ply;
	t_parsing		*parse;
	mlx_key_data_t	*key_data;
}	t_mlx;

void	parsing(t_mlx *mlx, char *filename);
void	fill_parse_struct(t_mlx *mlx);
void	validate_map(t_mlx *mlx);
void	flood_fill_organizer(t_mlx *mlx);
void	find_player(t_mlx *mlx);
char	**map_copy_it(t_mlx *mlx);

int		ft_abs(int num);

void	raycasting(t_mlx *mlx);
void	init(t_mlx *mlx);

/*Walls funcitons and structs*/
void	floor_and_ceiling_color(t_mlx *mlx);

/*Main*/
void	clean_exit(char *str);

#endif
