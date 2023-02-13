/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:09:32 by diogmart          #+#    #+#             */
/*   Updated: 2023/02/13 12:13:48 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_bresenham(t_data *data, float x, float y, float x1, float y1)
{
	float x_step;
	float y_step;

	x_step = x1 - x;
	y_step = y1 - y;
	x_step /= max(module(x), module(y));
	y_step /= max(module(x), module(y));
	while ((x > x1) && (y > y1))
	{
		my_mlx_pixel_put(data, x, y, 0x0000FFFF);
		x += x_step;
		y += y_step;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}