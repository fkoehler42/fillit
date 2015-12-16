/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:03:21 by fkoehler          #+#    #+#             */
/*   Updated: 2015/12/16 12:29:27 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		error(int fd)
{
	if (fd == -1)
		ft_putendl("error");
	else
	{
		close(fd);
		ft_putendl("error");
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		nb_tetri;
	char	**square;
	t_tetri	**tetris_array;

	fd = -1;
	if (argc != 2)
		return (error(fd));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (error(fd));
	if (!(nb_tetri = read_tetri(fd)))
		return (error(fd));
	if (close(fd) == -1)
		return (error(fd));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (error(fd));
	tetris_array = copy_tetris(fd, nb_tetri);
	if (close(fd) == -1)
		return (error(fd));
	square = ft_resolve_fillit(tetris_array, nb_tetri);
	ft_print_array(square);
	return (0);
}
