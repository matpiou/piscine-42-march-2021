/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamin <raamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 09:39:52 by raamin            #+#    #+#             */
/*   Updated: 2021/03/28 15:04:48 by raamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft.h"

int		unites(char *key, int size, char *dictionary[99][2], int level)
{
	char	*unit;
	int		index;
	int		ret;

	ret = 1;
	unit = ft_strdup(key);
	unit[1] = 0;
	if (ft_atoi(unit) == 0 && level != 0)
		ret = 0;
	else
	{
		if (level > 0)
			ft_putchar(' ');
		index = lookup(size, dictionary, unit);
		ft_putstr(dictionary[index][1]);
	}
	free(unit);
	return (ret);
}

int		first(char *diz, int size, char *dictionary[99][2], int level)
{
	int		index;

	if (level > 0)
		ft_putchar(' ');
	index = lookup(size, dictionary, diz);
	ft_putstr(dictionary[index][1]);
	return (1);
}

int		second(char *diz, int size, char *dictionary[99][2], int level)
{
	int		index;
	char	*keyloop;

	keyloop = ft_strdup(diz);
	keyloop[1] = '0';
	index = lookup(size, dictionary, keyloop);
	if (level > 0)
		ft_putchar(' ');
	ft_putstr(dictionary[index][1]);
	free(keyloop);
	if (diz[1] != '\0')
	{
		index = lookup(size, dictionary, diz + 1);
		ft_putchar('-');
		ft_putstr(dictionary[index][1]);
	}
	return (1);
}

int		dizaines(char *key, int size, char *dictionary[99][2], int level)
{
	char	*diz;
	int		ret;

	ret = 1;
	diz = ft_strdup(key);
	diz[2] = 0;
	if (ft_atoi(diz) == 0)
		ret = 0;
	else
	{
		if (*diz == '0')
			diz++;
		if ((0 < ft_atoi(diz) && ft_atoi(diz) <= 20))
			ret = first(diz, size, dictionary, level);
		else
			ret = second(diz, size, dictionary, level);
	}
	return (ret);
}

int		cents(char *key, int size, char *dictionary[99][2], int level)
{
	char	*cents;
	int		index;
	int		ret;

	ret = 0;
	cents = ft_strdup(key);
	cents[3] = 0;
	if (ft_atoi(cents) != 0)
	{
		cents[1] = 0;
		if (ft_atoi(cents) != 0)
		{
			index = lookup(size, dictionary, cents);
			if (level > 0)
				ft_putchar(' ');
			ft_putstr(dictionary[index][1]);
			ft_putstr(" hundred");
			ret = 1;
		}
		ret += dizaines(key + 1, size, dictionary, level + ret);
	}
	free(cents);
	return (ret);
}
