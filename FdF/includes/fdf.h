/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:44:03 by diogmart          #+#    #+#             */
/*   Updated: 2023/02/13 12:17:35 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct s_data {

	int 	width;
	int		height;
	int 	**map;

	// Minilibx
	void	*mlx;
	void	*mlx_win;
	
	// Image
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

//	read_file.c
void	read_file(t_data **data, char *file_name);
int 	get_height(char *file_name);
int 	get_width(char *file_name);

//	utils.c
int		ft_wordcount(char const *s, char c);
int		ft_nbr_len(long n);
int		max(int x, int y);
int		module(int x);

#endif