/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:09:32 by diogmart          #+#    #+#             */
/*   Updated: 2023/02/16 11:17:21 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	isometric(t_data *data, float *x, float *y, int *z)
{
	float	x0;
	float	y0;
	float	z0;
	double	angle = 0.8;

	//scaling
	x0 = *x * data->zoom;
	y0 = *y * data->zoom;
	z0 = *z * data->zoom;

	//isometric matrix
	*x = x0 * cos(0.80) - y0 * sin(0.80);
	*y = y0 * cos(0.80) + z0 + x0 * sin(0.80);
	// x = x0 * cos(0.8) - y0 * sin(0.8);
	// y = y0 * cos(0.8) + x0 * sin(0.8);

  	//rotate around z axis
 	x0 = *x * cos(angle) - *y * sin(angle);
	y0 = *x * sin(angle) + *y * cos(angle);

	// //rotate around y axis
 	*x = x0 * cos(angle) + z0 * sin(angle);
	*z = -x0 * sin(angle) + z0 * cos(angle);
	*y = y0;

	//rotate around x axis
 	y0 = *y * cos(0) - *z * sin(0);
	z0 = *y * sin(0) + *z * cos(0);
	x0 = *x;

	//translate
	*x = x0 + 200;
	*y = y0 + 200;
	*z = z0;
}


/* void	ft_isometric(float *x, float *y, int z)
{
	float	x0;
	float	y0;

	x0 = *x;
	y0 = *y;
	
	*x = x0 * cos(0.8) - y0 * sin(0.8);
	*y = x0 * sin(0.8) + y0 * cos(0.8) + z;

//	*x = (*x - *y) * cos(0.8);
//	*y = (x0 + *y) * sin(0.8) - z;
} */

void	ft_bresenham(t_data *data, float x0, float y0, float x1, float y1)
{
	float	x_step;
	float	y_step;
	//float	max;
	int		pixels;
	int		z;
	int		z1;

	z = -data->map[(int)y0][(int)x0];
	z1 = -data->map[(int)y1][(int)x1];
	isometric(data, &x0, &y0, &z);
	isometric(data, &x1, &y1, &z1);
	//data->color = (z) ? 0xe80c0c : 0xFFFFFF;

	x_step = x1 - x0;
	y_step = y1 - y0;

	//max = ft_max(module(x_step), module(y_step));
	pixels = sqrt((x_step * x_step) + (y_step * y_step));
	x_step /= pixels;
	y_step /= pixels;
	while (pixels > 0)
	{
		my_mlx_pixel_put(data, (int)x0, (int)y0, data->color);
		//mlx_pixel_put(data->mlx, data->mlx_win, x0, y0, data->color);
		x0 += x_step;
		y0 += y_step;
		pixels--;
	}
}

void	draw(t_data *data)
{
	float	y;
	float	x;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				ft_bresenham(data, (float)x, (float)y, (float)(x + 1), (float)y);
			if (y < data->height - 1)
				ft_bresenham(data, (float)x, (float)y, (float)x, (float)(y + 1));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}