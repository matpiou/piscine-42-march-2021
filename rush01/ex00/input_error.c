/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:33:53 by rcollas           #+#    #+#             */
/*   Updated: 2021/03/21 17:45:13 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_input_check(char *str)
{
	int i;

	i = 0;
	while (str[i] && i < 32)
	{
		if (!(str[i] >= '1' && str[i] <= '4'))
			return (1);
		i += 2;
	}
	i = 1;
	while (str[i])
	{
		if (!(str[i] == ' '))
			return (1);
		if (i > 29)
			return (1);
		i += 2;
	}
	return (0);
}

int		legit_grid(int input[16])
{
	int i;

	i = 0;
	while (i < 4)
	{
		if ((input[i] + input[i + 4]) > 5)
			return (1);
		i++;
	}
	i = 8;
	while (i < 12)
	{
		if ((input[i] + input[i + 4]) > 5)
			return (1);
		i++;
	}
	return (0);
}
