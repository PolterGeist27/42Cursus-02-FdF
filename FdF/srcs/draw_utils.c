/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:44:25 by diogmart          #+#    #+#             */
/*   Updated: 2023/03/01 12:05:07 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_data *data, t_vector p0, t_vector p1)
{
	if (p0.x < data->map_w - 1)
	{
		p1.x = p0.x + 1;
		p1.y = p0.y;
		ft_bresenham(data, p0, p1);
	}
	if (p0.y < data->map_h - 1)
	{
		p1.x = p0.x;
		p1.y = p0.y + 1;
		ft_bresenham(data, p0, p1);
	}
}

void	draw_line_2d(t_data *data, t_vector p0, t_vector p1)
{
	if (p0.x < data->map_w - 1)
	{
		p1.x = p0.x + 1;
		p1.y = p0.y;
		ft_bresenham_2d(data, p0, p1);
	}
	if (p0.y < data->map_h - 1)
	{
		p1.x = p0.x;
		p1.y = p0.y + 1;
		ft_bresenham_2d(data, p0, p1);
	}
}

void	ft_get_color(t_data *data, int z, int z1)
{
	if (z > 0 || z1 > 0)
		data->color = 0xe80c0c;
	else if (z == 0 && z1 == 0)
		data->color = 0xFFFFFF;
	else if (z < 0 || z1 < 0)
		data->color = 0x2596be;
}

t_point	ft_algebra(t_data *data, t_point point)
{
	float	x0;
	float	y0;
	float	z0;

	x0 = point.x * cos(0.8) - point.y * sin(0.8);
	y0 = point.y * cos(0.8) + point.x * sin(0.8);
	point.x = x0 * cos(data->ops.z_angle) - y0 * sin(data->ops.z_angle);
	point.y = x0 * sin(data->ops.z_angle) + y0 * cos(data->ops.z_angle);
	x0 = point.x * cos(data->ops.y_angle) + point.z * sin(data->ops.y_angle);
	z0 = -point.x * sin(data->ops.y_angle) + point.z * cos(data->ops.y_angle);
	y0 = point.y;
	point.y = y0 * cos(data->ops.x_angle) - z0 * sin(data->ops.x_angle);
	point.z = y0 * sin(data->ops.x_angle) + z0 * cos(data->ops.x_angle);
	point.x = x0;
	point.x += data->ops.x_translate;
	point.y += data->ops.y_translate;
	return (point);
}
