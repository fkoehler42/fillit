/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:03:21 by fkoehler          #+#    #+#             */
/*   Updated: 2015/12/12 18:19:50 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_tetris(t_tetri **tab, int nb_tetris)
{
	int i = 0;
	while (i < nb_tetris)
	{
		ft_putnbr(tab[i]->height);
		ft_putchar(' ');
		ft_putnbr(tab[i]->width);
		ft_putendl("");
		int j = 0;
		while (j < 4)
		{
			ft_putendl(tab[i]->array[j]);
			j++;
		}
		ft_putendl("");
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	fd;
	int	nb_tetri;
	
	if (argc != 2)
	{
		ft_putendl("error");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	nb_tetri = read_tetri(fd);
	ft_putnbr(nb_tetri);
	ft_putendl(" tetriminos");
	if (close(fd) == -1)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
t_tetri **tab = copy_tetris(fd, nb_tetri);
	if (close(fd) == -1)
		return (0);
	print_tetris(tab, nb_tetri);
	return (0);
}
