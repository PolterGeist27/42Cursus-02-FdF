/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:25:29 by diogmart          #+#    #+#             */
/*   Updated: 2023/02/13 11:49:27 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*(s + i) != '\0')
	{
		while (*(s + i) == c && *(s + i) != '\0')
			i++;
		if (*(s + i) != '\0')
		{
			count++;
			i++;
		}
		while (*(s + i) != c && *(s + i) != '\0')
			i++;
	}
	return (count);
}

int	ft_nbr_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	max(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

int	module(int x)
{
	if (x < 0)
		return (x * -1);
	else
		return (x);
}
