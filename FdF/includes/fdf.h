/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:44:03 by diogmart          #+#    #+#             */
/*   Updated: 2023/02/22 12:11:25 by diogmart         ###   ########.fr       */
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

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;


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

	// Zoom
	int	zoom;
	
	// Color
	int	color;

	// Dimension (2D or 3D)
	int Dimension;
	
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

// draw.c
void	ft_bresenham(t_data *data, float x0, float y0, float x1, float y1);
void	draw(t_data *data);
int		check_limits(t_data *data, int x, int y);

// keys.c
//int		ft_mouse_hook(int key, void *img);
int		mouse_hook(int button,int x,int y,void *param);

#endif