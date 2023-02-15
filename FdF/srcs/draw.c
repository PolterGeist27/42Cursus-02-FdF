/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:09:32 by diogmart          #+#    #+#             */
/*   Updated: 2023/02/15 13:43:06 by diogmart         ###   ########.fr       */
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

void	ft_isometric(float *x, float *y, int z)
{
	float	x0;
	float	y0;

	x0 = *x;
	y0 = *y;
	
/* 	*x = x0 * cos(0.8) - y0 * sin(0.8);
	*y = x0 * sin(0.8) + y0 * cos(0.8) + z; */
	*x = (*x - *y) * cos(0.8);
	*y = (x0 + *y) * sin(0.8) - z;
}

void	ft_bresenham(t_data *data, float x0, float y0, float x1, float y1)
{
	float	x_step;
	float	y_step;
	float	max;
	int	z;
	int	z1;

	z = data->map[(int)y0][(int)x0];
	z1 = data->map[(int)y1][(int)x1];

	x0 *= data->zoom;
	y0 *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	data->color = (z) ? 0xe80c0c : 0xFFFFFF;

	x_step = x1 - x0;
	y_step = y1 - y0;

	ft_isometric(&x0, &y0, z);
	ft_isometric(&x1, &y1, z1);
	x0 += 150;
	y0 += 150;
	x1 += 150;
	y1 += 150;


	max = ft_max(module(x_step), module(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x0 - x1) && (int)(y0 - y1))
	{
		//my_mlx_pixel_put(data, x0, y0, data->color);
		mlx_pixel_put(data->mlx, data->mlx_win, x0, y0, data->color);
		x0 += x_step;
		y0 += y_step;
	}
	//mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
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
}