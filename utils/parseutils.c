/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:12:22 by rprieur           #+#    #+#             */
/*   Updated: 2025/11/07 14:12:24 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

unsigned int	ahextocol(const char *str)
{
	unsigned int	nbr;
	int				i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i++] != '0')
		return (0x0);
	if (str[i++] != 'x')
		return (0x0);
	nbr = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr = nbr * 16 + str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			nbr = nbr * 16 + str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			nbr = nbr * 16 + str[i] - 'A' + 10;
		else
			break ;
		i++;
	}
	return (nbr << 8 | 0xFF);
}

static char	*allocdstrjoin(char *str1, char *str2, int str2len)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	if (!str1 && !str2)
		return (NULL);
	if (!str1)
		return (str2);
	if (!str2)
		return (str1);
	newstr = malloc(ft_strlen(str1) + str2len + 1);
	if (!newstr)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i])
		newstr[i++] = str1[j++];
	free(str1);
	j = 0;
	while (str2[j])
		newstr[i++] = str2[j++];
	free(str2);
	newstr[i] = 0;
	return (newstr);
}

char	*read_all(int fd)
{
	int			len;
	char		*str;
	char		*buf;
	int			size_mod;

	if (fd < 0 || fd >= 1024 || READ_BUFFER_SIZE <= 0)
		return (NULL);
	str = NULL;
	size_mod = 1;
	while (1)
	{
		buf = malloc(sizeof(char) * (READ_BUFFER_SIZE * size_mod + 1));
		if (!buf)
			return (NULL);
		len = read(fd, buf, READ_BUFFER_SIZE * size_mod);
		if (len <= 0)
			break ;
		buf[len] = 0;
		str = allocdstrjoin(str, buf, len);
		if (len < READ_BUFFER_SIZE * size_mod)
			return (str);
		size_mod *= 2;
	}
	free(buf);
	if (len < 0)
		return (NULL);
	return (str);
}
