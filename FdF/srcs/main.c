/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:45:06 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/25 13:33:31 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_data(t_data *data)
{
	int i;

	i = 0;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
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
	data->height = 0;
	data->width = 0;
	data->map = NULL;
	read_file(data, argv[1]);
	
	
	free_data(data);
}