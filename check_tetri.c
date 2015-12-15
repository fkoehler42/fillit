/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimazouz <mimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:03:59 by mimazouz          #+#    #+#             */
/*   Updated: 2015/12/15 11:35:26 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		isvalid_tetri(char *str, char c)
{
	int	i;
	int	neighbour;
	int	nb_char;
	
	i = 0;
	neighbour = 0;
	nb_char = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			nb_char++;
			if (i >= 5 && str[i - 5] == c)
				neighbour++;
			if (i >= 1 && str[i - 1] == c)
				neighbour++;
			if (i < 19 && str[i + 1] == c)
				neighbour++;
			if (i < 15 && str[i + 5] == c)
				neighbour++;
		}
		i++;
	}
	return (nb_char == 4 && (neighbour == 6 || neighbour == 8));
}

int		check_tetri(char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] != '\n' && j < 4)
		{
			if (str[i] != '#' && str[i] != '.')
				return (0);
			i++;
			j++;
		}
		if (str[i] == '\n' && j == 4)
			i++;
		else
			return (0);
	}
	return (isvalid_tetri(str, '#'));
}
