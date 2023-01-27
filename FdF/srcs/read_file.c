/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:45:14 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/27 15:11:46 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(char *file_name)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file_name, 'r');
	line = get_next_line(fd);
	width = ft_wordcount(line, ' ');
	free(line);
	close(fd);
	return (width);
}

int get_height(char *file_name)
{
	int height;
	int	fd;

	fd = open(file_name, 'r');
	height = 0;
	while (get_next_line(fd))
		height++;
	close(fd);
	return (height);
}

int **fill_map(t_data *data, char *file_name)
{
	int		fd;
	int		i;
	int		j;	
	int		**map;
	char	*line;

	j = 0;
	i = 0;
	map = (int **)malloc(sizeof(int *) * data->width);
	fd = open(file_name, 'r');
	line = get_next_line(fd);
	while (line != NULL)
	{	
		map[i] = (int *)malloc(sizeof(int) * (data->height));
		while(line[j] != '\0')
		{
			map[i][j] = ft_atoi(&line[j]);
			j++;
		}
		i++;
		// ERROR IS HERE
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

void	read_file(t_data *data, char *file_name)
{
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->map = fill_map(data, file_name);
		ft_printf("here2\n");
}
