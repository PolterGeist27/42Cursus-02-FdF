/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:09:32 by diogmart          #+#    #+#             */
/*   Updated: 2023/03/01 14:34:34 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	isometric(t_data *data, float *x, float *y, int *z)
{
	t_point	point;

	point.x = *x * data->ops.zoom;
	point.y = *y * data->ops.zoom;
	point.z = *z * data->ops.zoom;
	point = ft_algebra(data, point);
	*x = point.x;
	*y = point.y;
	*z = point.z;
}

int	check_limits(t_data *data, int x, int y)
{
	if (data->img_w - 1 < x || x < 0)
		return (0);
	if (data->img_h - 1 < y || y < 0)
		return (0);
	return (1);
}

void	ft_bresenham(t_data *data, t_vector p0, t_vector p1)
{
	float	x_step;
	float	y_step;
	int		pixels;
	int		z;
	int		z1;

	z = data->map[(int)p0.y][(int)p0.x];
	z1 = data->map[(int)p1.y][(int)p1.x];
	ft_get_color(data, z, z1);
	isometric(data, &p0.x, &p0.y, &z);
	isometric(data, &p1.x, &p1.y, &z1);
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

void	draw(t_data *data)
{
	t_vector	p0;
	t_vector	p1;

	p0.y = 0;
	while (p0.y < data->map_h)
	{
		p0.x = 0;
		while (p0.x < data->map_w)
		{
			draw_line(data, p0, p1);
			p0.x++;
		}
		p0.y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
