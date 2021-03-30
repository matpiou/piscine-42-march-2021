/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:02:06 by lpicques          #+#    #+#             */
/*   Updated: 2021/03/29 15:28:56 by lpicques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*s2;
	int		i;
	int		j;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (!(s2 = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	j = 0;
	while (src[j])
	{
		s2[j] = src[j];
		j++;
	}
	s2[j] = '\0';
	return (s2);
}
