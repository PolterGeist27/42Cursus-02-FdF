/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:00:42 by diogmart          #+#    #+#             */
/*   Updated: 2023/02/22 14:12:14 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_operations(t_data *data, float *x, float *y, int *z)
{
	float	x0;
	float	y0;
	float	z0;

	//scaling
	x0 = *x * data->ops.zoom;
	y0 = *y * data->ops.zoom;
	z0 = *z * data->ops.zoom;

	// translate
	*x = x0 + data->ops.x_translate;
	*y = y0 + data->ops.y_translate;
	*z = z0;
}

void	ft_bresenham_2d(t_data *data, float x0, float y0, float x1, float y1)
{
	float	x_step;
	float	y_step;
	//float	max;
	int		pixels;
	int		z;
	int		z1;

	z = -data->map[(int)y0][(int)x0];
	z1 = -data->map[(int)y1][(int)x1];
	data->color = (z) ? 0xe80c0c : 0xFFFFFF;
	ft_operations(data, &x0, &y0, &z);
	ft_operations(data, &x1, &y1, &z1);

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

void	draw_2d(t_data *data)
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
				ft_bresenham_2d(data, (float)x, (float)y, (float)(x + 1), (float)y);
			if (y < data->map_h - 1)
				ft_bresenham_2d(data, (float)x, (float)y, (float)x, (float)(y + 1));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
