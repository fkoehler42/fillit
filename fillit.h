/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:45:38 by fkoehler          #+#    #+#             */
/*   Updated: 2015/12/16 11:28:05 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft.h"

typedef	struct		s_tetri
{
	char			array[4][5];
	char			letter;
	int				width;
	int				height;
}					t_tetri;

int					main(int argc, char **argv);
int					read_tetri(int fd);
int					check_tetri(char *str);
int					isvalid_tetri(char *str, char c);
t_tetri				**copy_tetris(int fd, int nb_tetri);
t_tetri				*init_tetri(char *buf, char letter);
void				fill_array(char *buf, t_tetri *tetri, char letter);
void				put_blocks_up(t_tetri *tetri);
void				put_blocks_left(t_tetri *tetri);
void				set_tetri_height(t_tetri *tetri);
void				set_tetri_width(t_tetri *tetri);
int					search_char_column_n(t_tetri *tetri, char c, int n);
char				**ft_resolve_fillit(t_tetri **array, int nb_tetri);
int					ft_square_size(int nb_tetri);
char				**ft_init_square(int size);
int					fill_square(char **square, int size, t_tetri **array,
					int n);
int					check_place_for_tetri(char **square, t_tetri *tetri,
					int i, int j);
void				place_tetri(char **square, t_tetri *tetri,
					int i, int j);
void				remove_tetri(char **square, t_tetri *tetri,
					int i, int j);
void				print_square(char **square);

#endif
