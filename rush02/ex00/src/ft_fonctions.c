/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamin <raamin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 10:22:30 by raamin            #+#    #+#             */
/*   Updated: 2021/03/28 23:20:59 by raamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft.h"

int		lookup(int size, char *dictionary[1024][2], char *key)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!ft_strcmp(key, dictionary[i][0]))
			return (i);
		i++;
	}
	return (-1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = (char *)malloc(ft_strlen(src) + 1)))
		return (0);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*build(int q)
{
	int		k;
	char	*big;

	big = (char *)malloc(1 + q * 3 + 1);
	big[0] = '1';
	k = 0;
	while (k < 3 * q)
	{
		big[1 + k] = '0';
		k++;
	}
	big[1 + q * 3] = 0;
	return (big);
}
