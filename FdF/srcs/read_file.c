/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:45:14 by diogmart          #+#    #+#             */
/*   Updated: 2023/02/06 14:11:31 by diogmart         ###   ########.fr       */
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
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (width);
}

int	get_height(char *file_name)
{
	int	height;
	int	fd;

	fd = open(file_name, 'r');
	height = 0;
	while (get_next_line(fd))
		height++;
	close(fd);
	return (height);
}

int	**fill_map(t_data *data, char *file_name)
{
	int		fd;
	int		i;
	int		j;
	int		h;
	int		**map;
	char	*line;

	j = 0;
	i = 0;
	h = 0;
	map = (int **)ft_calloc(sizeof(int *), (data->width + 1));
	fd = open(file_name, 'r');
	line = get_next_line(fd);
	while (h < data->width)
		map[h++] = (int *)ft_calloc(sizeof(int), (data->height + 1));
	while (line != NULL && i < data->height)
	{
		h = 0;
		while (line[j] != '\0')
		{
			if (ft_isdigit(line[j]))
			{
				map[h++][i] = ft_atoi(&line[j]);
				j += ft_nbr_len(ft_atoi(&line[j]));
			}
			else
				j++;
		}
		i++;
		j = 0;
		free(line);
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
}
