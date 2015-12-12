/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:07:19 by fkoehler          #+#    #+#             */
/*   Updated: 2015/12/12 17:34:48 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"

int	read_tetri(int fd)
{
	int		nb_tetri;
	int		ret;
	int		ret2;
	char	buf[21];
	char	buf2[2];

	nb_tetri = 0;
	ret = 0;
	ret2 = 0;
	ft_bzero((void *)buf, 21);
	ft_bzero((void *)buf2, 2);
	while ((ret = read(fd, buf, 20)) > 0)
	{
		if (!check_tetri(buf))
			return (0);
		if ((ret2 = read(fd, buf2, 1)) == 1 && buf2[0] != '\n')
			return (0);
		nb_tetri++;
	}
	if (ret2 == 1)
		return (0);
	return (nb_tetri);
}
