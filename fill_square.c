/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:36:00 by fkoehler          #+#    #+#             */
/*   Updated: 2015/12/16 11:25:02 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_place_for_tetri(char **square, t_tetri *tetri, int i, int j)
{
	int	k;
	int	l;

	k = 0;
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

void	place_tetri(char **square, t_tetri *tetri, int i, int j)
{
	int	k;
	int	l;

	k = 0;
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

void	remove_tetri(char **square, t_tetri *tetri, int i, int j)
{
	int		k;
	int		l;

	k = 0;
	while (k < tetri->height)
	{
		l = 0;
		while (l < tetri->width)
		{
			if (tetri->array[k][l] == tetri->letter)
				square[i + k][j + l] = '.';
			l++;
		}
		k++;
	}
}

int		fill_square(char **square, int size, t_tetri **array, int n)
{
	int	i;
	int	j;

	i = 0;
	if (array[n] == NULL)
		return (1);
	while ((i + array[n]->height) <= size)
	{
		j = 0;
		while ((j + array[n]->width) <= size)
		{
			if (check_place_for_tetri(square, array[n], i, j))
			{
				place_tetri(square, array[n], i, j);
				if (!(fill_square(square, size, array, n + 1)))
					remove_tetri(square, array[n], i, j);
				else
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
