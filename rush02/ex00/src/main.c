/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamin <raamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 09:37:23 by raamin            #+#    #+#             */
/*   Updated: 2021/03/28 23:39:24 by raamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

int	nextstep(int q, int size, char *dictionary[99][2])
{
	char	*big;
	int		index;

	big = build(q);
	index = lookup(size, dictionary, big);
	free(big);
	ft_putchar(' ');
	ft_putstr(dictionary[index][1]);
	return (0);
}

int	printrecursive(char *key, int size, char *dictionary[99][2], int level)
{
	int		ret;
	int		q;
	int		r;
	int		length;

	while (level != 0 && *key == '0')
		key++;
	length = ft_strlen(key);
	if (level != 0 && length == 0)
		return (0);
	q = (length - 1) / 3;
	r = (length - 1) % 3;
	if (r == 0)
		ret = unites(key, size, dictionary, level);
	else if (r == 1)
		ret = dizaines(key, size, dictionary, level);
	else
		ret = cents(key, size, dictionary, level);
	if (q > 0)
	{
		if (ret > 0)
			nextstep(q, size, dictionary);
		printrecursive(key + r + 1, size, dictionary, level + 1);
	}
	return (0);
}

int	getinputs(int argc, char **argv, char **filename, char **key)
{
	if (argc == 2)
		*filename = "english.txt";
	else if (argc == 3)
		*filename = argv[1];
	else
		return (1);
	*key = argv[argc - 1];
	return (0);
}

int	checkinput(char *key)
{
	int		i;

	i = 0;
	while (key[i])
	{
		if (key[i] < '0' || key[i] > '9')
		{
			ft_putstr("Error\n");
			return (1);
		}
		++i;
		if (ft_strlen(key) > 35)
		{
			ft_putstr("Dict Error\n");
			return (1);
		}
	}
	if (*key == '-')
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int			size;
	char		*key;
	char		*filename;
	char		*dictionary[99][2];

	if (getinputs(argc, argv, &filename, &key) > 0)
		return (1);
	if (checkinput(key) > 0)
		return (1);
	if (getdictionary(filename, &size, dictionary) == 0)
		return (1);
	while (*key == '0')
		key++;
	if (ft_strlen(key) == 0)
		printrecursive("0", size, dictionary, 0);
	else
		printrecursive(key, size, dictionary, 0);
	ft_putchar('\n');
	return (freedictionary(size, dictionary));
}
