/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:37:45 by lpicques          #+#    #+#             */
/*   Updated: 2021/03/29 12:29:57 by lpicques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int		ft_size_all(int size, char **strs, char *sep)
{
	int i;
	int taille;

	i = 0;
	taille = 0;
	while (i < size)
	{
		taille = taille + ft_strlen(strs[i]);
		i++;
	}
	taille = taille + (size - 1) * (ft_strlen(sep) + 1);
	return (taille);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;
	int		taille;
	int		i;

	taille = ft_size_all(size, strs, sep);
	if (size == 0)
	{
		tab = malloc(sizeof(char));
		*tab = 0;
		return (tab);
	}
	if (!(tab = (char *)malloc(sizeof(tab) * taille)))
		return (0);
	*tab = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(tab, strs[i]);
		if (i < size - 1)
			ft_strcat(tab, sep);
		i++;
	}
	return (tab);
}
