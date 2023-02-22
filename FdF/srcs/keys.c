/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:27:46 by diogmart          #+#    #+#             */
/*   Updated: 2023/02/22 12:17:48 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(int key, t_data *data)
{
	// Scroll up: 	4
	// Scroll down: 5
	if (key == 4)
		data->zoom = data->zoom * 1.5;
	if (key == 5)
	{
		if (data->zoom > 2)
			data->zoom = data->zoom / 1.5;
	}
	ft_printf("Hello\n");
}

void	ft_translate(int key, t_data *data)
{
/* 	if (key == UP)
		data->iso.transl_y -= 10;
	else if (key == DOWN)
		data->iso.transl_y += 10;
	else if (key == LEFT)
		data->iso.transl_x -= 10;
	else
		data->iso.transl_x += 10; */
}

/* int	check_keys(int key, t_data *img)
{
	ft_printf("Hello\n");
	if (key == ESC)
		ft_close(img);
	if (key == SCROLL_UP || key == SCROLL_DOWN)
		ft_zoom(key, img);
	else if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		ft_translate(key, img);
	else if ((key == ZP_ROT || key == ZM_ROT || key == YP_ROT
			|| key == YM_ROT || key == XP_ROT || key == XM_ROT)
		&& img->proj == 1)
		op_rotate(key, img);
	else if (key == PROJECTION)
		img->proj *= -1;
	else
		return (0);
	return (1);
} */

int	mouse_hook(int button, int x, int y, void *param)
{
	t_data	*data;

	
	data = (t_data *)param;
	(void)x;
	(void)y;
 	if (button == 5)
	{
 		if (data->zoom > 2)
			data->zoom = data->zoom / 1.5;
	}
	if (button == 4)
		data->zoom = data->zoom * 1.5;
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->img);
	data->img = data->img = mlx_new_image(data->mlx, data->img_w, data->img_h);
	draw(data);
	return (0);
}
/* 	mlx_clear_window(data->mlx_win, data->mlx);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->img_w, data->img_h);
	draw(data);
	return (0); */