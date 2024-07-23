/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 01:07:58 by nsabia            #+#    #+#             */
/*   Updated: 2024/07/23 11:12:05 by nsabia           ###   ########.fr       */
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
# define ROTATION_SPEED 2
# define PLAYER_SPEED 1

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
	int			player_x; //values are mixed, do we need them?
	int			player_y;
}	t_parsing;


/*Player_movement functions and structs*/
typedef struct s_player
{
	int		plyr_x;
	int		plyr_y;
	int		map_i; //player's position map index
	int		map_j; //player's position map index
	int		coord_x; //to store player's position in pixels
	int		coord_y;
	int		plyr_inside_tile_x;
	int		plyr_inside_tile_y;
	int		most_left_angle; //FOV
	int		angle; //player's view central point
	int		most_right_angle; //FOV
	float	fov_radians;
	int		rotation;
	int		left_or_right;
	int		up_or_down;
}	t_player;

void	keyhook_organizer(mlx_key_data_t keydata, void *mlx);

/*Raycasting functions and structs*/
typedef struct s_raytracing
{
	mlx_image_t		*minimap;
	float			da; //increase by x_axis
	float			db; //increase by y_axis
	float			d_h; //distance to intersection;
	double			alpha; //angle for calculations;
	double			alpha2; //for horiz intersections calculation;
	int				ray_step;
	float			x1; //intersections
	float			y1;
	float			dist_vert_i;
	float			vert_x_wall;
	float			vert_y_wall;
	float			dist_hor_i;
	float			hor_x_wall;
	float			hor_y_wall;
	float			wall_x; //intersection with the wall
	float			wall_y; //intersection with the wall
	int				sq_unit; //haven't used yet;
	double			distance_to_wall;
	int				flag_for_wall;
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
void	minimap_draw(t_mlx *mlx);
void	put_block(t_mlx *mlx, int i, int j);
void	draw_vert (t_mlx *mlx);
void	draw_horiz (t_mlx *mlx);
void	draw_player (t_mlx *mlx);
void	draw_walls(t_mlx *mlx);
void	init(t_mlx *mlx);
float	deg_to_rad(int angle);
void	vert_inter(t_mlx *mlx);
void	first_inter(t_mlx *mlx);
void	next_vert_i(t_mlx *mlx);
void	draw_inter(t_mlx *mlx, float x, float y);
int		out_check(t_mlx *mlx);
int		check_if_wall_h(t_mlx *mlx);
int		check_if_wall_v(t_mlx *mlx);
float	ft_abs2(float a);
void	horiz_inter(t_mlx *mlx);
void	first_hor_inter(t_mlx *mlx);
void	next_hor_i(t_mlx *mlx);
void	specific_intersections(t_mlx *mlx);
void	intersec_270(t_mlx *mlx);
void	intersec_180(t_mlx *mlx);
void	intersec_90(t_mlx *mlx);
void	intersec_zero(t_mlx *mlx);
void	choose_min_dist(t_mlx *mlx);
void	minimap_draw_line(t_mlx *mlx, float x_coord, float y_coord);
void reinit(t_mlx *mlx);


/*Walls funcitons and structs*/
void	floor_and_ceiling_color(t_mlx *mlx);

/*Main*/
void	clean_exit(char *str);

#endif
