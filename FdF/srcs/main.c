/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:45:06 by diogmart          #+#    #+#             */
/*   Updated: 2023/03/15 10:46:15 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_h)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data);
}

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_data(data);
	exit(EXIT_SUCCESS);
}

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 1920, 1080, "FdF");
	data->img_w = 1920;
	data->img_h = 1080;
	data->img = mlx_new_image(data->mlx, data->img_w, data->img_h);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->map_h = 0;
	data->map_w = 0;
	data->map = NULL;
	data->ops.zoom = 20;
	data->ops.x_translate = 0;
	data->ops.y_translate = 0;
	data->ops.x_angle = 0.61;
	data->ops.y_angle = 0;
	data->ops.z_angle = 0;
	data->color = 0xFFFFFF;
	data->dimension = 1;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2 || open(argv[1], O_RDONLY, 0) < 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	data = malloc(sizeof(t_data));
	init_data(data);
	read_file(&data, argv[1]);
	data->ops.x_translate = (data->img_w - (data->ops.zoom * data->map_w)) / 2;
	data->ops.y_translate = (data->img_h - (data->ops.zoom * data->map_h)) / 2;
	draw(data);
	mlx_mouse_hook(data->mlx_win, mouse_hook, data);
	mlx_hook(data->mlx_win, 2, (1L << 0), check_keys, data);
	mlx_hook(data->mlx_win, 17, 0, ft_close, data);
	mlx_loop(data->mlx);
}
