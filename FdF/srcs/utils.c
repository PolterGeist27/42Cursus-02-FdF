/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:25:29 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/25 13:25:33 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_wordcount(char const *s, char c)
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