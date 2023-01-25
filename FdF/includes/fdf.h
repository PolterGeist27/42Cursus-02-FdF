/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:44:03 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/25 13:29:22 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

void	read_file(t_data *data, char *file_name);
int 	get_height(char *file_name);
int 	get_width(char *file_name);
int		ft_wordcount(char const *s, char c);

typedef struct s_data {
	int width;
	int	height;
	int **map;
} t_data;

#endif