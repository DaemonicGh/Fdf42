/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:14:40 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/07 14:14:42 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_atoi(const char *str)
{
	int	nbr;
	int	sgn;
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sgn = 1;
	if (str[i] == '-')
	{
		sgn = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	nbr = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr * sgn);
}

int	nbrlen_base(int nbr, int base)
{
	int	size;

	size = nbr <= 0;
	while (nbr != 0)
	{
		nbr /= base;
		size++;
	}
	return (size);
}

static void	putnbr_fd(int fd, int nbr)
{
	if (nbr >= 10)
		putnbr_fd(fd, nbr / 10);
	nbr = nbr % 10 + '0';
	write(fd, &nbr, 1);
}

void	ft_putnbr_fd(int fd, int nbr)
{
	if (nbr == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
	}
	putnbr_fd(fd, nbr);
}

void	ft_putuhex_fd(int fd, unsigned int nbr)
{
	const char	*hex = "0123456789ABCDEF";

	if (nbr >= 16)
		ft_putuhex_fd(fd, nbr / 16);
	write(fd, &hex[nbr % 16], 1);
}
