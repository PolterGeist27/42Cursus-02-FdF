/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:09:32 by diogmart          #+#    #+#             */
/*   Updated: 2023/02/22 10:03:32 by diogmart         ###   ########.fr       */
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
	double	x_angle = 0.61;
	double	y_angle = 0;
	double	z_angle = 0;

	//scaling
	x0 = *x * data->zoom;
	y0 = *y * data->zoom;
	z0 = *z * data->zoom;

	//isometric matrix
	*x = x0 * cos(0.8) - y0 * sin(0.8);
	*y = y0 * cos(0.8) + z0 + x0 * sin(0.8);

  	//rotate around z axis
 	x0 = *x * cos(z_angle) - *y * sin(z_angle);
	y0 = *x * sin(z_angle) + *y * cos(z_angle);

	// //rotate around y axis
 	*x = x0 * cos(y_angle) + z0 * sin(y_angle);
	*z = -x0 * sin(y_angle) + z0 * cos(y_angle);
	*y = y0;

	//rotate around x axis
 	y0 = *y * cos(x_angle) - *z * sin(x_angle);
	z0 = *y * sin(x_angle) + *z * cos(x_angle);
	x0 = *x;

	//translate
	*x = x0 + 200;
	*y = y0 + 200;
	*z = z0;
}

int	check_limits(t_data *data, int x, int y)
{
	if (data->img_w < x || x < 0)
		return (0);
	if (data->img_h < y || y < 0)
		return (0);
	return (1);
}

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
	data->color = (z || z1) ? 0xe80c0c : 0xFFFFFF;
	isometric(data, &x0, &y0, &z);
	isometric(data, &x1, &y1, &z1);

	x_step = x1 - x0;
	y_step = y1 - y0;

	pixels = sqrt((x_step * x_step) + (y_step * y_step));
	x_step /= pixels;
	y_step /= pixels;
	while (pixels > 0)
	{
		if (check_limits(data, x0, y0))
			my_mlx_pixel_put(data, (int)x0, (int)y0, data->color);
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
	while (y < data->map_h)
	{
		x = 0;
		while (x < data->map_w)
		{
			if (x < data->map_w - 1)
				ft_bresenham(data, (float)x, (float)y, (float)(x + 1), (float)y);
			if (y < data->map_h - 1)
				ft_bresenham(data, (float)x, (float)y, (float)x, (float)(y + 1));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}