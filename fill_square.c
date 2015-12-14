/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:36:00 by fkoehler          #+#    #+#             */
/*   Updated: 2015/12/14 19:53:13 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_place_for_tetri(char **square, t_tetri *tetri, size_t i, size_t j)
{
	size_t	k;
	size_t	l;

	while (k < tetri->height)
	{
		l = 0;
		while (l < tetri->width)
		{
			if (tetri->array[k][l] == tetri->letter
					&& square[i + k][j + l] != '.')
				return (0);
			l++;
		}
		k++;
	}
	return (1);
}

void	place_tetri(char **square, t_tetri *tetri, size_t i, size_t j)
{
	size_t	k;
	size_t	l;

	while (k < tetri->height)
	{
		l = 0;
		while (l < tetri->width)
		{
			if (tetri->array[k][l] == tetri->letter)
				square[i + k][j + l] = tetri->letter;
			l++;
		}
		k++;
	}
}



int	fill_square(char **square, size_t size, t_tetri **array, int nb_tetri)
{
	int	i;
	int	j;
	int	n;

	n = 0;
	while (n < nb_tetri)
	{
		i = 0;
		j = 0;
		while (!(place_tetri(array[n], square, i, j)) && square[i])
		{
			place_tetri(array[n], square, i, j)
		}

	}


}
