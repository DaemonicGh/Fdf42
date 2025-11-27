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

#include "fdf.h"

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

int	setstr(char *str, char *replacement)
{
	int	i;

	i = 0;
	while (replacement[i])
	{
		str[i] = replacement[i];
		i++;
	}
	return (i);
}

int	min(int val1, int val2)
{
	if (val1 < val2)
		return (val1);
	return (val2);
}

int	max(int val1, int val2)
{
	if (val1 > val2)
		return (val1);
	return (val2);
}
