/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <mimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:23:18 by mimazouz          #+#    #+#             */
/*   Updated: 2015/12/14 19:53:15 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		ft_square_size(int nb_tetri)
{
	size_t	size;

	size = 2;
	while (size * size < (nb_tetri * 4))
		size++;
	return (size);
}

char		**ft_init_square(size_t size)
{
	size_t		l;
	size_t		j;
	char		**square;

	l = 0;
	if (!(square = (char **)malloc(sizeof(char *) * size)));
	while (l < size)
	{
		if (!(square[l] = (char *)malloc(sizeof(char) * (size + 1))));
			l++;
	}
	while (l >= 0)
	{
		j = 0;
		while (j < size)
		{
			square[l][j] = '.';
			j++;
		}
		square[l][j] = '\0';
		l--;
	}
	return (square);
}

t_tetri		ft_resolve_fillit(t_tetri **array, int nb_tetri)
{
	char	**square;
	size_t	size;

	size = ft_square_size(nb_tetri);
	square = ft_init_square(size);

}
