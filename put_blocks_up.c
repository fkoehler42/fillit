/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_blocks_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 13:21:56 by fkoehler          #+#    #+#             */
/*   Updated: 2015/12/16 11:22:39 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_blocks_up(t_tetri *tetri)
{
	int	i;

	while (ft_strchr(tetri->array[0], tetri->letter) == NULL)
	{
		i = 0;
		while (i < 3)
		{
			ft_strcpy(tetri->array[i], tetri->array[i + 1]);
			i++;
		}
		ft_strcpy(tetri->array[3], "....");
	}
}

void	put_blocks_left(t_tetri *tetri)
{
	int	i;
	int	j;

	while (!(search_char_column_n(tetri, tetri->letter, 0)))
	{
		j = 0;
		while (j < 3)
		{
			i = 0;
			while (i < 4)
			{
				tetri->array[i][j] = tetri->array[i][j + 1];
				i++;
			}
			j++;
		}
		i = 0;
		while (i < 4)
		{
			tetri->array[i][3] = '.';
			i++;
		}
	}
}

int		search_char_column_n(t_tetri *tetri, char c, int n)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tetri->array[i][n] == c)
			return (1);
		i++;
	}
	return (0);
}
