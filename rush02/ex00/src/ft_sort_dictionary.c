/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_dictionary.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamin <raamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 10:52:55 by raamin            #+#    #+#             */
/*   Updated: 2021/03/28 21:33:10 by raamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	getline(int fd, char key[99], char value[99])
{
	int		index;
	char	car;

	index = 0;
	while (read(fd, &car, 1) > 0)
	{
		if ('0' <= car && car <= '9')
			key[index++] = car;
		else if ('a' <= car && car <= 'z')
			value[index++] = car;
		else if (car == ':')
		{
			key[index++] = 0;
			index = 0;
		}
		else if (car == '\n')
		{
			value[index++] = 0;
			index = 0;
			return (1);
		}
	}
	return (0);
}

int	getdictionary(char *filename, int *size, char *dictionary[99][2])
{
	char	key[99];
	char	value[99];
	int		fd;

	fd = open(filename, 0);
	*size = 0;
	if (fd < 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	while (getline(fd, key, value) > 0)
	{
		if (ft_strlen(key) > 0 && ft_strlen(value) > 0)
		{
			dictionary[*size][0] = ft_strdup(key);
			dictionary[*size][1] = ft_strdup(value);
			(*size)++;
		}
		else
			ft_putstr("Dict Error\n");
	}
	close(fd);
	return (*size);
}

int	freedictionary(int size, char *dictionary[99][2])
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(dictionary[i][0]);
		free(dictionary[i][1]);
		i++;
	}
	return (0);
}
