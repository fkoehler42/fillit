/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:41:29 by fkoehler          #+#    #+#             */
/*   Updated: 2015/12/09 14:56:41 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)malloc(sizeof(*s) * size + 1);
	if (!s)
		return (NULL);
	while (s[i])
	{
		s[i] = 0;
		i++;
	}
	s[i] = 0;
	return (s);
}
