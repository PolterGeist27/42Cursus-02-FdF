/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:45:14 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/25 13:35:08 by diogmart         ###   ########.fr       */
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
	while (get_next_line(fd) != NULL)
		height++;
	close(fd);
	return (height);
}

void	fill_map(int **map, char *file_name);

void	read_file(t_data *data, char *file_name)
{
	data->height = get_height(file_name);
	data->width = get_width(file_name);
}
