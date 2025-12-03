/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:37:54 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/17 16:37:56 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	itostr(long nbr, char *str, int *i)
{
	if (nbr >= 10)
		itostr(nbr / 10, str, i);
	str[*i] = nbr % 10 + '0';
	(*i)++;
}

int	ft_itostr(int nbr, char *str)
{
	long	lnbr;
	int		i;

	i = 0;
	lnbr = nbr;
	if (nbr < 0)
	{
		str[i++] = '-';
		lnbr = -lnbr;
	}
	itostr(lnbr, str, &i);
	return (i);
}

char	*setstr(char *str, char *section, int pos)
{
	int	i;

	i = 0;
	while (str[pos] && section[i])
	{
		str[pos++] = section[i++];
	}
	return (str);
}
