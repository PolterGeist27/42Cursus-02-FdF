/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:45:06 by diogmart          #+#    #+#             */
/*   Updated: 2023/02/13 12:24:37 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_data(t_data *data)
{
	int i;

	i = 0;
	while (i < data->height)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);

}

void	init_data(t_data *data)
{
	// Minilibx
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 1920, 1080, "FdF");
	//Image
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
		&data->line_length, &data->endian);
	// map data
	data->height = 0;
	data->width = 0;
	data->map = NULL;
}

int	main(int argc, char **argv)
{
	t_data *data;

	if (argc != 2)
	{
		ft_printf("Error! Input 1 map to display\n");
		return (0);
	}
	data = malloc(sizeof(t_data));
	init_data(data);
	read_file(&data, argv[1]);
	//mlx_hook(data->mlx, ...);
	mlx_loop(data->mlx);
	free_data(data);
}
