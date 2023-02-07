/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:45:06 by diogmart          #+#    #+#             */
/*   Updated: 2023/02/07 10:15:31 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_data(t_data **data)
{
	int i;

	i = 0;
	while (i < (*data)->height)
	{
		free((*data)->map[i]);
		i++;
	}
	free((*data)->map);
	free(*data);
}

void	init_data(t_data **data)
{
//	(*data)->mlx = mlx_init();
//	(*data)->mlx_win = mlx_new_window((*data)->mlx, 1920, 1080, "FdF");
	(*data)->height = 0;
	(*data)->width = 0;
	(*data)->map = NULL;
}

int	main(int argc, char **argv)
{
	t_data *data;

	if (argc != 2)
	{
		ft_printf("Error! Input 1 map to display");
		return (0);
	}
	data = malloc(sizeof(t_data));
	init_data(&data);
	read_file(&data, argv[1]);
	free_data(&data);
//	mlx_loop(data->mlx);
}
