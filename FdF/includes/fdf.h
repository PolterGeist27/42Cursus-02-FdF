/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:44:03 by diogmart          #+#    #+#             */
/*   Updated: 2023/03/01 12:22:32 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

# define ESC 65307
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define UP 119 //w
# define LEFT 97 //a
# define DOWN 115 //s
# define RIGHT 100 //d
# define DIMENSION 65289 //TAB
# define ROT_Z1 113 // Q
# define ROT_Z2 101 // E
# define ROT_Y1 122 // Z
# define ROT_Y2 120 // X
# define ROT_X1 99 // C
# define ROT_X2 118 // V

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

typedef struct s_operations
{
	int		zoom;
	int		x_translate;
	int		y_translate;
	float	x_angle;
	float	y_angle;
	float	z_angle;
}	t_op;

typedef struct s_data {

	int 	map_w;
	int		map_h;
	int 	**map;

	// Minilibx
	void	*mlx;
	void	*mlx_win;

	// Image
	int		img_w;
	int		img_h;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	// Operations
	t_op ops;

	// Color
	int	color;

	// Dimension (2D or 3D)
	int dimension;
} t_data;

// main.c 
int	ft_close(t_data *data);

//	read_file.c
void	read_file(t_data **data, char *file_name);
int 	get_height(char *file_name);
int 	get_width(char *file_name);
void	fill_row(int *row, char *line);

//	utils.c
int		ft_countwords(char const *s, char c);
int		ft_nbr_len(long n);
int		ft_max(int x, int y);
int		module(int x);
void	choose_draw(t_data *data);

// draw.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_bresenham(t_data *data, t_vector p0, t_vector p1);
void	draw(t_data *data);
int		check_limits(t_data *data, int x, int y);

// draw_2d.c
void	draw_2d(t_data *data);
void	ft_bresenham_2d(t_data *data, t_vector p0, t_vector p1);

// keys.c
int		check_keys(int key, t_data *img);
int		mouse_hook(int button,int x,int y,void *param);

// draw_utils.c
void	draw_line(t_data *data, t_vector p0, t_vector p1);
void	draw_line_2d(t_data *data, t_vector p0, t_vector p1);
void	ft_get_color(t_data *data, int z, int z1);
t_point	ft_algebra(t_data *data, t_point point);

#endif