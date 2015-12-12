/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:45:38 by fkoehler          #+#    #+#             */
/*   Updated: 2015/12/12 17:54:31 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <fcntl.h>
#include "libft.h"

typedef	struct	s_tetri
{
	char			array[4][5];
	char			letter;
	size_t			width;
	size_t			height;
}					t_tetri;

int					main(int argc, char **argv);
int					read_tetri(int fd);
int					check_tetri(char *str);
int					isvalid_tetri(char *str, char c);
t_tetri 			**copy_tetris(int fd, size_t nb_tetri);
t_tetri				*init_tetri(char *buf, char letter);
void				fill_array(char *buf, t_tetri *tetri, char letter);
void				replace_char(char *str, char c, char d);
void				put_blocks_up(t_tetri *tetri);
void				put_blocks_left(t_tetri *tetri);
void				set_tetri_height(t_tetri *tetri);
void				set_tetri_width(t_tetri *tetri);
int					search_char_column_n(t_tetri *tetri, char c, int n);

#endif
