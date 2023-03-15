/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:45:14 by diogmart          #+#    #+#             */
/*   Updated: 2023/03/15 10:38:28 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(t_data *data)
{
	ft_printf("Error\n");
	free_data(data);
	exit(1);
}

int	get_width(char *file_name)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file_name, 'r');
	line = get_next_line(fd);
	width = ft_countwords(line, ' ');
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (width);
}

int	get_height(char *file_name)
{
	char	*line;
	int		height;
	int		fd;

	fd = open(file_name, 'r');
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

void	fill_row(int *row, char *line)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	split = ft_split(line, ' ');
	while (split[j] != NULL)
	{
		row[i++] = ft_atoi(split[j]);
		free(split[j]);
		j++;
	}
	free(split);
}

void	read_file(t_data **data, char *file_name)
{
	char	*line;
	int		fd;
	int		i;
	int		h;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		ft_error(data);
	(*data)->map_h = get_height(file_name);
	(*data)->map_w = get_width(file_name);
	i = 0;
	h = 0;
	(*data)->map = (int **)malloc(sizeof(int *) * ((*data)->map_h));
	line = get_next_line(fd);
	while (h < (*data)->map_h)
		(*data)->map[h++] = (int *)malloc(sizeof(int) * ((*data)->map_w));
	while (line != NULL && i < (*data)->map_h)
	{
		fill_row((*data)->map[i++], line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
