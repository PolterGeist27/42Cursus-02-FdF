/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:27:46 by diogmart          #+#    #+#             */
/*   Updated: 2023/03/01 10:40:53 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_translate(int key, t_data *data)
{
	if (key == UP)
		data->ops.y_translate += 10;
	else if (key == DOWN)
		data->ops.y_translate -= 10;
	else if (key == LEFT)
		data->ops.x_translate += 10;
	else
		data->ops.x_translate -= 10;
}

void	ft_rotate(int key, t_data *data)
{
	if (key == ROT_X1)
		data->ops.x_angle += 0.2;
	else if (key == ROT_X2)
		data->ops.x_angle -= 0.2;
	else if (key == ROT_Y1)
		data->ops.y_angle += 0.2;
	else if (key == ROT_Y2)
		data->ops.y_angle -= 0.2;
	else if (key == ROT_Z1)
		data->ops.z_angle += 0.2;
	else if (key == ROT_Z2)
		data->ops.z_angle -= 0.2;
}

int	check_keys(int key, t_data *data)
{
	if (key == ESC)
		ft_close(data);
	else if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		ft_translate(key, data);
	else if (key == DIMENSION)
		data->dimension *= -1;
	else if (key == ROT_X1 || key == ROT_X2 || key == ROT_Y1 || key == ROT_Y2
		|| key == ROT_Z1 || key == ROT_Z2)
		ft_rotate(key, data);
	else
		return (0);
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->img_w, data->img_h);
	choose_draw(data);
	return (1);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)x;
	(void)y;
	if (button == 5)
	{
		if (data->ops.zoom > 2)
			data->ops.zoom = data->ops.zoom / 1.5;
	}
	if (button == 4)
	{
		if (data->ops.zoom < 10000)
			data->ops.zoom = data->ops.zoom * 1.5;
	}
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->img_w, data->img_h);
	choose_draw(data);
	return (0);
}
