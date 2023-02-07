/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:44:03 by diogmart          #+#    #+#             */
/*   Updated: 2023/02/07 10:03:59 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "../minilibx/mlx.h"
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

//	void	*mlx;
//	void	*mlx_win;
} t_data;

//	read_file.c
void	read_file(t_data **data, char *file_name);
int 	get_height(char *file_name);
int 	get_width(char *file_name);

//	utils.c
int		ft_wordcount(char const *s, char c);
int		ft_nbr_len(long n);

#endif