/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tetri_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:31:57 by fkoehler          #+#    #+#             */
/*   Updated: 2015/12/16 11:23:11 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	set_tetri_height(t_tetri *tetri)
{
	int		i;
	size_t	height;

	i = 0;
	height = 0;
	while (i < 4)
	{
		if (ft_strchr(tetri->array[i], tetri->letter) != NULL)
			height++;
		i++;
	}
	tetri->height = height;
}

void	set_tetri_width(t_tetri *tetri)
{
	int		i;
	int		j;
	size_t	width;

	i = 0;
	j = 0;
	width = 0;
	while (j < 4)
	{
		if (search_char_column_n(tetri, tetri->letter, i))
			width++;
		i++;
		j++;
	}
	tetri->width = width;
}
