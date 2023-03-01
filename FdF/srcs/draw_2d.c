/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:00:42 by diogmart          #+#    #+#             */
/*   Updated: 2023/03/01 11:20:36 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_operations(t_data *data, float *x, float *y, int *z)
{
	float	x0;
	float	y0;
	float	z0;

	x0 = *x * data->ops.zoom;
	y0 = *y * data->ops.zoom;
	z0 = *z * data->ops.zoom;
	*x = x0 + data->ops.x_translate;
	*y = y0 + data->ops.y_translate;
	*z = z0;
}

void	ft_bresenham_2d(t_data *data, t_vector p0, t_vector p1)
{
	float	x_step;
	float	y_step;
	int		pixels;
	int		z;
	int		z1;

	z = data->map[(int)p0.y][(int)p0.x];
	z1 = data->map[(int)p1.y][(int)p1.x];
	ft_get_color(data, z, z1);
	ft_operations(data, &p0.x, &p0.y, &z);
	ft_operations(data, &p1.x, &p1.y, &z1);
	x_step = p1.x - p0.x;
	y_step = p1.y - p0.y;
	pixels = sqrt((x_step * x_step) + (y_step * y_step));
	x_step /= pixels;
	y_step /= pixels;
	while (pixels > 0)
	{
		if (check_limits(data, p0.x, p0.y))
			my_mlx_pixel_put(data, (int)p0.x, (int)p0.y, data->color);
		p0.x += x_step;
		p0.y += y_step;
		pixels--;
	}
}

void	draw_2d(t_data *data)
{
	t_vector	p0;
	t_vector	p1;

	p0.y = 0;
	while (p0.y < data->map_h)
	{
		p0.x = 0;
		while (p0.x < data->map_w)
		{
			draw_line_2d(data, p0, p1);
			p0.x++;
		}
		p0.y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
